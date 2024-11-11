#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a=0,b,d=-1;
  cin>>n;
  int c[n];
  for(int i=0;i<n;i++){
    cin>>c[i];
    a=max(a,c[i]);
  }
  for(int i=0;i<n;i++){
    if(c[i]!=a){
      if(d<min(c[i],a-c[i])){
        b=c[i];
        d=min(c[i],a-c[i]);
      }
    }
  }
  cout<<a<<" "<<b;
}
