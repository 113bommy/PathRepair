#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n, m, x[1024], y[1024], z[1024];
int main(){
  cin >> n >> m;
  for(int i=0;i<n;:i++) cin >> x[i] >> y[i] >> z[i];
  ll ans = 0;
  for(int sx=-1;sx<3;sx+=2){
    for(int sy=-1;sy<3;sy+=2){
  	  for(int sz=-1;sz<3;sz+=2){
        vector<ll> v;
        for(int i=0;i<n;i++) v.push_back(sx*x[i]+sy*y[i]+sz*z[i]);
        sort(v.begin(), v.end(), greater<ll>());
        ll sum = 0;
        for(int i=0;i<m;i++) sum += v[i];
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << endl;
  return 0;
}