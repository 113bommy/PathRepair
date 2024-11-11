#include<bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin>>q;
  while(q--){
    int m,n,t,c=0;
    cin>>m>>n;
    t=m*m+n*n;
    for(int i=0;i<10000;i++)
      for(int j=0;j<10000;j++)
        if(i*i+j*j<1)continue;
         if((m*i+n*j)%(i*i+j*j)==0&&(m*j-n*i)%(i*i+j*j)==0)c++;
    if(c<=4)cout<<'P'<<endl;
  else cout<<'C'<<endl;
  }
}