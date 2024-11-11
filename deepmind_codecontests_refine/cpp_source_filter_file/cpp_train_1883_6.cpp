#include <iostream>
using namespace std;
 
#define check cnt=0;for(j=0;j<6;j++)if(d[q][j]==d[r][j])cnt++;
#define m tmp=d[r][1];d[r][1]=d[r][3];d[r][3]=d[r][4];d[r][4]=d[r][2];d[r][2]=tmp;
#define y tmp=d[r][0];d[r][0]=d[r][3];d[r][3]=d[r][5];d[r][5]=d[r][2];d[r][2]=tmp;
 
bool same(int d[][6],int q,int r){
 int tmp,cnt,j,a=1,i,k;
 check
   if(cnt==6)a=0;
 
 while(a){
  for(i=0;i<5;i++){
   for(k=0;k<4;k++){
    check
    if(cnt==6)break;
    m
   }
   check
   if(cnt==6)break;
   tmp=d[r][0];
   d[r][0]=d[r][1];
   d[r][1]=d[r][5];
   d[r][5]=d[r][4];
   d[r][4]=tmp;
  }
  if(cnt==6)break;
  y
  for(k=0;k<4;k++){
   check
   if(cnt==6)break;
   m
  }
  if(cnt==6)break;
  y
  y
  for(k=0;k<4;k++){
   check
   if(cnt==6)break;
   m
  }
  a=0;
 }
 
 if(cnt==6)return true;
 return false;
 
}
 
 
int main(){
 int n,tmp,cnt,a=1,i,j,judge=0;
 
 cin >> n;
 
 int d[n][6];
 
 for(i=0;i<n;i++){
  for(j=0;j<6;j++){
   cin >> d[i][j] ;
  }
 }
 
 for(q=0;q<n-1;q++){
  for(r=q+1;r<n;r++){
  if(same(d,q,r))judge++;
  }
 }
 if(judge>0)cout << "No" << endl ;
 else cout << "Yes" << endl ;
 
 return 0;
}