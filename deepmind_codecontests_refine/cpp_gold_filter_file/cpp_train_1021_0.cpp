#include<iostream>
using namespace std;
int h,k;
char s[50][50];
int main(void){
  cin>>h>>k;
  for(int i=0;i<h;i++)for(int j=0;j<k;j++)cin>>s[i][j];
  for(int i=0 ;i<h;i++)
    for(int j=0 ;j<k;j++){
      bool t=0;
      if(s[i][j]=='#'){
        if(i!=0&&s[i-1][j]=='#')t=1;
        if(i!=h&&s[i+1][j]=='#')t=1;
        if(j!=0&&s[i][j-1]=='#')t=1;
        if(j!=k&&s[i][j+1]=='#')t=1;
        if(!t){
          cout<<"No";
          return 0;
        }
      }
    }
  cout<<"Yes";
  return 0;
}