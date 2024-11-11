#include<iostream>
#include<stdio.h>
using namespace std;

int dy[]={-1,0,1,0};
int dx[]={0,1,0.-1};

double dp[3][3][16];
int n;
char s,t,b;
int S,T,B;

double solve(int y,int x,int n){
  if(dp[y][x][n]!=-1.0)return dp[y][x][n];
  if(n==0)return dp[y][x][n]=(y*3+x==T?1.0:0.0);

  double sum=0.0;
  for(int i=0;i<4;i++){
    int ny=y+dy[i];
    int nx=x+dx[i];
    if(ny<0||nx<0)sum+=solve(y,x,n-1);
    else if(ny>=3||nx>=3)sum+=solve(y,x,n-1);
    else if(ny*3+nx==B)sum+=solve(y,x,n-1);
    else sum+=solve(ny,nx,n-1);
  }
  return dp[y][x][n]=sum/4.0;
}

void init(){
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<16;k++)
	dp[i][j][k]=-1.0;
}

int main(){
  while(1){
    cin>>n;
    if(n==0)break;
    cin>>s>>t>>b;
    init();
    S=s-'A';
    T=t-'A';
    B=b-'A';
    printf("%.8f\n",solve(S/3,S%3,n));
  }
  
  return 0;
}