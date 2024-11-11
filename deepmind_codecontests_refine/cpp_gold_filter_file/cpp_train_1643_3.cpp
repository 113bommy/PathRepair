#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
ll A=0,B=0,N,x;
ll Q(ll&i,string&S,vector<ll>&F,vector<ll>&G){
  if(S.at(i)=='0')return (A+F.at(i))%(x+1);
  return ((B-G.at(i))%(x-1)+x-1)%(x-1);
}
ll f(ll m){
  if(m==0)return 0;
  ll i=0,n=m;
  while(n>0){
    if(n%2==1)i++;
    n/=2;
  }
  return 1+f(m%i);
}
signed main(){
  ll i,s=1;string S,T;cin>>N>>S;
  T=S;sort(ALL(T));
  x=upper_bound(ALL(T),'0')-T.begin();
  x=N-x;vector<ll>F(N);
  REP(i,N){
    F.at(N-1-i)=s;
    if(S.at(N-1-i)=='1')A+=s;
    s*=2;s%=x+1;A%=x+1;
  }
  s=1;vector<ll>G(N);
  if(x<=1){
    REP(i,N)G.at(i)=-1;
  }
 else REP(i,N){
    G.at(N-1-i)=s;
    if(S.at(N-1-i)=='1')B+=s;
    s*=2;s%=x-1;B%=x-1;
  }
  REP(i,N){
    if(x==1&&S.at(i)=='1')cout<<0<<endl;
    else{
      ll RES=Q(i,S,F,G);
      cout<<1+f(RES)<<endl;
    }
  }
  return 0;
}