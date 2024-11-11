#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int N,ans=0;
  cin>>N;
  for(long long int i=1; i*(i+1)<N; ++i){
    if(N%i==0) ans+=N/i-1;
  }
  cout<<ans;
  return 0;
}