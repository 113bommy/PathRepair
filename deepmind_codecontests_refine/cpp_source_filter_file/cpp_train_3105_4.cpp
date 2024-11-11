#include <bits/stdc++.h>
using namespace std 
int main(){
int n,k[100],count=0;
  cin>>n;
  for(int i=0;i<n;++i){
   cin>>k[i];
  }
  for(int i=1;i<=n;++i){
   if(k[i-1]==k[i]){
     ++count;
     k[i]=10000;
   }
  }
  cout<<count<<endl;
}
