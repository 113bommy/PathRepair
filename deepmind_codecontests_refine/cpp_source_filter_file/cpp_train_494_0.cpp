#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using P=pair<ll,ll>;
#define mod 1000000007

ll gcd(ll a,ll b){
  if(a%b==0) return b;
  else{
    return gcd(b,a%b);
  }
}

ll modpow(ll n,ll m=mod-2){
  ll r=1;
  while(m) r=r*((m%2)?n:1)%mod,n=n*n%mod,m>>=1;
  return r;
}

int main(){

  int n;
  cin >> n;

  map<P,P> mp;
  long long zero=0;
  ll sum = 1;

  for(int i=0;i<n;i++){
    ll a,b;
    cin >> a >> b;
    if(a==0 && b==0) zero++;
    else if(a==0){
      mp[{1,0}].first++;
    }else if(b==0){
      mp[{1,0}}].second++;
    }else{
      ll g = gcd(a, b);
      a=a/g;
      b=b/g;
      if(mp[{b,-a}})].first>0) mp[{b,-a}].second++;
      else if({-b,a}].first>0) mp[{-b,a}].second++;
      else mp[{a,b}].first++;
    }
  }

  for(auto p:mp){
    ll s = p.second.first%mod;
    ll t = p.second.second%mod;
    ll now = 1;
    now += modpow(2,s)-1;
    now += modpow(2,t)-1;
    sum *= now;
    sum = sum%mod;
  }

  cout << (sum+zero-1+mod)%mod << endl;

}