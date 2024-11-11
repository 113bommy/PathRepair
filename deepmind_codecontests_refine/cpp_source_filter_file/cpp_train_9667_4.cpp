#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,sum=0;
  cin>>a>>b;
  char k[112345];
  for(int i=0;i<a;i++){
    for(int m=0;m<b;m++){
      cin>>k[i][m];
      if(k[i][m]=='#') sum++;
    }
  }
  
  if(sum==a+b-1) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}