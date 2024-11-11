#include<bits/stdc++.h>
using namespace std;
static const int mod=1000000007;
int64_t f(int64_t x,int64_t y){
if(y==0)
  return 1;
  else{
  if(y%2==0){
  return (f(x,y/2)*f(x,y/2))%mod;
  }else{
  return (((x*f(x,y/2))%mod)*f(x,y/2))%mod;
  }
  }

}
int64_t comb(int64_t n,int64_t k){
int64_t N=1; 
  for(int i=n-k+1;i<=n;i++)
    N=(N*i)%mod;
  int64_t K=1;
  for(int i=1;i<=k;i++)
    K=(K*i)%mod;
  return (N*f(K,mod-2))%mod;
}
int main(){
int64_t N,a,b;
  cin>>N>>a>>b;
  int64_t ans=(f(2,N)-1-comb(N,a)-comb(N,b)+2*mod)%mod;
  cout<<ans<<endl;
  
   return 0;
}