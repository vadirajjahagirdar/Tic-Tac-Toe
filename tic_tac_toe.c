#include<stdio.h>
#include<stdlib.h>

int compute(int p[][3],int n,int n1) //check for all combinations of the game.
{
    n=n-1;
    switch(n) //check for all possible combination of game success.
    {
	case 0:if ( (p[0][0]==n1 && p[0][1]==n1 && p[0][2]==n1) || (p[0][0]==n1 && p[1][0]==n1&& p[2][0]==n1) || (p[0][0]==n1 && p[1][1]==n1 && p[2][2]==n1) )
	       {
		   printf("Player %d wins!!!!congraulation\n",n1);
		   exit(1);
	       }
	       else
		   break;
	
	case 1:if(  (p[0][0]==n1 && p[0][1]==n1 && p[0][2]==n1) || (p[0][1]==n1 && p[1][1]==n1 && p[2][1]==n1) )
		{
		    printf("Player %d wins!!!congratulations\n",n1);
		    exit(1);
		}
		else
		    break;
	
	case 2:if( (p[0][0]==n1 &&
             p[0][1]==n1 && p[0][2]==n1) || (p[0][2]==n1 && p[1][2]==n1 && p[2][2]==n1) || (p[0][2]==n1 && p[1][1]==n1 && p[2][0]==n1) )
		{
		    printf("Player %d wins!!!congratulations\n",n1);
		    exit(1);
		}
		else
		    break;
	
	case 3:if( (p[1][0]==n1 && p[0][0]==n1 && p[2][0]==n1) || (p[1][0]==n1 && p[1][1]==n1 && p[1][2]==n1) )
	       {
		   printf("Player %d wins!!!congratulations\n",n1);
		   exit(1);
	       }
	       else
		   break;
	
	case 4:if( (p[1][0]==n1 && p[1][1]==n1 && p[1][2]==n1) || (p[0][1]==n1 && p[1][1]==n1 && p[2][1]==n1) || (p[0][0]==n1 && p[1][1]==n1 && p[2][2]==n1) || (p[0][2]==n1 && p[1][1]==n1 && p[2][0]==n1) )
		{
		    printf("Player %d wins!!!congratulations\n",n1);
		    exit(1);
		}
		else
		    break;
	
	case 5:if( (p[1][0]==n1 && p[1][1]==n1 && p[1][2]==n1) || (p[0][2]==n1 && p[1][2]==n1 && p[2][2]==n1) )
		{
		    printf("Player %d wins!!!congratulations\n",n1);
		    exit(1);
		}
		else
		    break;
	
	case 6:if( (p[0][0]==n1 && p[1][0]==n1 && p[2][0]==n1) || (p[2][0]==n1 && p[2][1]==n1 && p[2][2]==n1) || (p[2][0]==n1 && p[1][1]==n1 && p[0][2]==n1) )
		{
		    printf("Player %d wins!!!congratulations\n",n1);
		    exit(1);
		}
		else
		    break;
  
  case 7:if( (p[2][0]==n1 && p[2][1]==n1 && p[2][2]==n1) || (p[2][1]==n1 && p[1][1]==n1 && p[0][1]==n1) )
		{
		    printf("Player %d wins!!!congratulations\n",n1);
		    exit(1);
		}
		else
		    break;
  
  case 8:if( (p[2][0]==n1 && p[2][1]==n1 && p[2][2]==n1) || (p[2][2]==n1 && p[1][2]==n1 && p[0][2]==n1) || (p[2][2]==n1 && p[1][1]==n1 && p[0][0]==n1) )
	     {
		 printf("Player %d wins!!!congratulations\n",n1);
		 exit(1);
	     }
	     else
		break;
  
  default:printf("print nothing");
  }
  return 0;
}

int initialboardbuild(int p[3][3])// Initialize the board with 0's.
{
     int i,j;
     for( i=0;i<3;i++)
     {
       for( j=0;j<3;j++)
       {
        	  p[i][j]=0;
       }
    }
    return 0;
}

int printboard(int p[3][3]) //print the current status of board, after each operation.
{
     int i,j;
     printf("\n");
     for( i=0;i<3;i++)
     {
       for( j=0;j<3;j++)
	     {
	      printf("%d ",p[i][j]);
	     }
      printf("\n");
    }
    return 0;
}

int build(int p[3][3],int n,int n1)// Initializes the board with given value of n1.
{
    switch(n)
    {
	case 1:p[0][0]=n1;
	       break;
	
	case 2:p[0][1]=n1;
	       break;
	
	case 3:p[0][2]=n1;
	       break;
	
	case 4:p[1][0]=n1;
	       break;
	
	case 5:p[1][1]=n1;
	       break;
	
	case 6:p[1][2]=n1;
	       break;
	
	case 7:p[2][0]=n1;
	       break;
	
	case 8:p[2][1]=n1;
	       break;
	
	case 9:p[2][2]=n1;
	       break;
	
	default:printf("Nothing is entered !!!!\n");
   }
    return 0;
}

int main()
{
    int board[3][3],i,j,n,k=1,m,n1=1,n2=2,stk[20],top=-1,z;
    printf("Welcome to 2 player Tic-Tac-Toe\n");
    printf("Initially board is filled with 0's\n");
    printf("Player 1 move is taken as 1\n");
    printf("Player 2 move is taken as 2\n");
    printf("To enter the move..Please enter the position in the board\n");
    printf("Okay!!!!!!!Lets!!!Begin!!!!!!");
    
    initialboardbuild(board);  // To build initial board with all 0's.
    printboard(board);         // Print the initial board.
	  
	  while(top<8) //loop, until the values on the stack are 9(counting starts with 0).
	  {
      printf("\nPlayer 1:Enter the move:");
      scanf("%d",&n);
      z=top;
      
      while(z!=-1)
      {
       if(n==stk[z]){ //check if the MOVE is already performed.f
         printf("\nPlease Don't Repeat the MOVE\nMOVE is WASTED\n");
         goto testcond1; //MOVE is already performed, do not perform "build board" action.
       }
       z--;
      }
      
      stk[++top]=n;
      build(board,n,n1); // if MOVE is not performed, build the board.
 testcond1:printboard(board);
           compute(board,n,n1);
    
    if(!(top<8)) //if values on the stack are equal to 9, then exit.
      break;
    
    else
    {
      printf("\nPlayer 2:Enter the move:");
      scanf("%d",&n);
      z=top;
      while(z!=-1)
      {
       if(n==stk[z]){
         printf("Please Don't Repeat the MOVE\nMOVE is WASTED\n");
         goto testcond2;
       }
       z--;
      }
      stk[++top]=n;
      build(board,n,n2);
      testcond2:printboard(board);
              compute(board,n,n2);
   
    }
    
   }
    
    printf("Match Drawn\n");
    printf("Thanks for Playing\n\n");
    
    return 0;
}

