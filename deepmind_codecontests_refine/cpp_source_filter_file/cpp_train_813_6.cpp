#include <bits/stdc++.h>
using namespace std;
int H,W;
string board[50]
int dj[]={-1,-1,-1,0,0,1,1,1};
int di[]={-1,0,1,-1,1,-1,0,1};
int ni,nj,b;

int main(){
cin >>H >>W;
for (int i=0;i<H;i++)cin >>board[i];
for(int i=0;i<H;i++){
for(int j=0;j<W;j++){
	if(board[i][j]=='.'){
      b=0;
        for (int k=0;k<8;k++){
          ni=i+di[k];nj=j+dj[k];
          if(ni<0||nj<0||ni>=H||nj>=W)continue;
          if(board[ni][nj]=='#')b++;
        }
      board[i][j]='0'+b;   
      }
}}
  for(int i=0;;i<H;i++){cout <<board[i]<<endl;}
}