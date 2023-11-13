#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void displayTable(int X[],int Y[],int indx);
void DisplaySum(int, int, int, int, int,int);

int summation_X(int x[],int indx);
int summation_Y(int y[],int indx);

int summation_Xsq(int x[],int indx);
int summation_Ysq(int y[],int indx);

int  summation_XY(int x[],int y[],int indx);

void Correlation(int, int, int, int, int,int);

int main()
{
    int ex=1;
    while(ex!=0){
    system("cls");
    int indx,i;
     printf("\n\n                   \t\t\t\t\t \t\t\t\t       by -SandipPaudel\n\n\n");
    printf("Enter the number of elements for X and Y:");
    scanf("%d",&indx);
    int X[indx], Y[indx]; /////
    printf("\n\n");

   for (i=0;i<indx;i++){
        printf("\n[%d] elements of X:",i+1);
            //for x
        scanf("%d",&X[i]);
        }

        printf("\n\n");

    for (i=0;i<indx;i++){
        // for y
        printf("\n[%d] elements of Y:",i+1);
        scanf("%d",&Y[i]);
    }


/////// VARIABLE DECLARE FOR EASY USE ///////////
    int sumX=summation_X(X,indx);
    int sumY=summation_Y(Y,indx);

    int sumXsq=summation_Xsq(X,indx);
    int sumYsq=summation_Ysq(Y,indx);

    int sumXY=summation_XY(X,Y,indx);
////////////////VARIABLE DECLARION SECTION END////////

    displayTable(X,Y,indx);

    DisplaySum(sumX, sumY, sumXsq, sumYsq, sumXY,indx);

    Correlation(sumX, sumY, sumXsq, sumYsq, sumXY,indx);

    system("pause >nul");

    ////////////////////// repeat section //////////////

    system("cls");
    printf("0 to exit and any other integer to repeat:");
    scanf("%d",&ex);
 }
    return 0;
}
//-------------------CALC_FUNCTIONS-----------------------///

///////////// TABLE DISPLAY SECTION /////////////////////
void displayTable(int X[],int Y[],int indx)
{
    int i;
    system("cls");
    printf("\n   |\tX\t| \tY\t| \tX^2\t| \tY^2\t| \tXY\t| \n\n");
    for (i=0;i<indx;i++){
        printf("   |\t%d\t| \t%d\t| \t%d\t| \t%d\t| \t%d\t| \n",X[i], Y[i], X[i]*X[i], Y[i]*Y[i], X[i]*Y[i]);
    }

}

void DisplaySum(int sumX,int sumY,int sumXsq, int sumYsq, int sumXY,int indx)
{
    printf("\n---------------------------------------------------------------------------------------------");
    printf("\n         |\t Elements (n)=%d    \t\t|",indx);
    printf("\n         |\tSummationOf X=%d    \t\t|",sumX);
    printf("\n         |\tSummationOf Y=%d    \t\t|",sumY);
    printf("\n         |\tSummationOf (X^2)=%d\t\t|",sumXsq);
    printf("\n         |\tSummationOf (Y^2)=%d\t\t|",sumYsq);
    printf("\n         |\tSummationOf XY=%d   \t\t|",sumXY);
    printf("\n---------------------------------------------------------------------------------------------");

}


//////////// SUMMATION OF X AND Y ////////////////////////
int  summation_X(int x[],int indx)
{
    int sum=0,i;
    for (i=0;i<indx;i++){
        sum += x[i];
    }
    return sum;
}

int  summation_Y(int y[],int indx)
{
    int sum=0,i;
    for (i=0;i<indx;i++){
        sum += y[i];
    }

    return sum;
}
/////////////////////////////////////////////////////////



//////////// SQUARE SUMMATION OF X AND Y /////////////////////

int summation_Xsq(int x[],int indx){
      int sum=0,i;
    for (i=0;i<indx;i++){
        sum += (x[i]*x[i]);
    }
    return sum;
}

int summation_Ysq(int y[],int indx){
      int sum=0,i;
    for (i=0;i<indx;i++){
        sum += (y[i]*y[i]);
    }
    return sum;
}
///////////////////////////////////////


///////////////// SUMMATION OF XY ////////////////////
int  summation_XY(int x[],int y[],int indx)
{
    int sum=0,i;
    for (i=0;i<indx;i++){
        sum += ( y[i]*x[i] );
    }
    return sum;
}

//////////////////////  FINAL CALCULATION /////////////////

void Correlation(int X, int Y, int Xsq, int Ysq, int XY,int indx){
    float r;
    float x=X, y=Y, xsq=Xsq, ysq=Ysq, xy=XY, n=indx ;

    float A= sqrt( (n*xsq)-(x*x) );
    float B= sqrt ( (n*ysq)-(y*y) );

    r = ( (n*xy)-(x*y) ) / (A*B);
    printf("\n\n");
    printf("\n\CorrelationCoeffecient (r): %f",r);
    printf("\n\n");

    /////////// relation section......

    //printf("\t\t");
    if (r==1){
        printf("THERE IS PERFECTLY POSITIVE CORRELATION BETWEEN VARIABLES!");
    }
    else if (r==-1){
        printf("THERE IS PERFECTLY NEGETIVE CORRELATION BETWEEN VARIABLES!");
    }
    else if (r==0){
        printf("THERE IS NO CORRELATION BETWEEN VARIABLES!");
    }
    else if(r>0){
        printf("VARIABLES ARE POSITIVELY CORRELATED!");
    }
    else if(r<0){
        printf("VARIABLES ARE NEGATIVELY CORRELATED!");
    }
    else{
        printf("____Undefined____");
    }
    printf("\n");

}

///////// THE END //////
//;/////// TIME TAKEN : 3HRS + SOMETIME...
