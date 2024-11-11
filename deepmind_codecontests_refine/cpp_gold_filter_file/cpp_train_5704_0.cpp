#include<bits/stdc++.h>
using namespace std;

int r,co;
int mat[1000][1000];
string c[1000];

int main(){
  cin>>r>>co;
  for(int i=0;i<r;i++){
    cin>>c[i];  
  }
  if(c[0][0]=='#')mat[0][0]=1;
  for(int j=1;j<co;j++){
   if(c[0][j]=='#'&&c[0][j-1]=='.')mat[0][j]=1+mat[0][j-1];
   else mat[0][j]=mat[0][j-1];
  }
  for(int i=1;i<r;i++){
   if(c[i][0]=='#'&&c[i-1][0]=='.')mat[i][0]=1+mat[i-1][0];
   else mat[i][0]=mat[i-1][0];
   for(int j=1;j<co;j++){
     int a,b;
     if(c[i][j]=='#'&&c[i][j-1]=='.')a=1+mat[i][j-1];
   	 else a=mat[i][j-1];
     if(c[i][j]=='#'&&c[i-1][j]=='.')b=1+mat[i-1][j];
   	 else b=mat[i-1][j];
     mat[i][j]=min(a,b);
   }
  }
  cout<<mat[r-1][co-1];
}
