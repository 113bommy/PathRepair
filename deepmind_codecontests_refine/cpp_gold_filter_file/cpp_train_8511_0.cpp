#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
using ll=long long;
using Graph=vector<vector<pair<int,int>>>;
#define MOD 1000000007
#define INF 1000000000

//gcd(a,b)=a*x-byの解(x1,y1)を返す
// or 1=a*x-byの解、解がなければ(0,0)を返す。
//一般解 (x,y)=(b/gcd(a,b)*t+x1,a/gcd(a,b)*t+y1)
pair<ll,ll> solve(ll a,ll b){
  vector<ll> p,q,r,d;
  p.push_back(a);
  q.push_back(b);
  d.push_back(a/b);
  r.push_back(a%b);
  ll i=0;
  while(r[i]>0){
    p.push_back(q[i]);
    q.push_back(r[i]);
    d.push_back(q[i]/r[i]);
    r.push_back(q[i]%r[i]);
    i++;
  }
  ll gcd=q[i];
  if(q[i]!=1)return make_pair(0,0);
  i--;
  ll aa=1;
  ll bb=1;
  ll cc=0;
  while(i>0){
    i--;
    ll tmp=-bb*d[i+1]-cc;
    cc=-aa;
    aa=tmp;
    bb=tmp;
  }
  ll t;
  if(aa>0){
    t=aa/(b/gcd);
  }else{
    t=(-aa)/(b/gcd)+1;
  }
  return make_pair(aa+(b/gcd)*t,bb*d[i]+cc+(a/gcd)*t);
}

int main(){
  ll N;
  cin>>N;
  ll i=1;
  vector<ll> divd1;
  while(i*i<=N){
    if(N%i==0){
      divd1.push_back(i);
      divd1.push_back(N/i);
    }
    ++i;
  }

  int n=divd1.size();
  ll ans=2*N;
  if(N==1){
    cout<<1<<endl;
    return 0;
  }
  for(int i=0;i<n;++i){
    ll x=divd1[i];
    ll y=N/x;
    pair<ll,ll> a;
    a=solve(y,2*x);
    if(a.second>0){
      ans=min(ans,2*x*a.second);
    }
    a=solve(2*x,y);
    if(a.second>0){
      ans=min(ans,y*a.second);
    }
    a=solve(2*y,x);
    if(a.second>0){
      ans=min(ans,x*a.second);
    }
    if(x>1){
      a=solve(x,2*y);
      if(a.second>0){
        ans=min(ans,2*y*a.second);
      }
    }

  }
  cout<<ans<<endl;
}
