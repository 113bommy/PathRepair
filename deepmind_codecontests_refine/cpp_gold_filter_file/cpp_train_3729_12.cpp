#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define ALL(a)  (a).begin(),(a).end()
ll n,m;
ll p[100000],y[100000];
vector<ll> yd[100001];
int main(){
  cin>>n>>m;
  rep(i,m){
    cin>>p[i]>>y[i];
    yd[p[i]].push_back(y[i]);
  }
  rep(i,n){
    sort(ALL(yd[i+1]));
  }
  rep(i,m){
    printf("%012lld\n",ll(p[i])*1000000+(ll)(lower_bound(ALL(yd[p[i]]),y[i])-yd[p[i]].begin())+1);
  }
}