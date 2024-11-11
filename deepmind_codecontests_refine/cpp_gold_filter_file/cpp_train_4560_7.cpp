#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(){
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];
  sort(a.begin(),a.end());
  sort(f.rbegin(),f.rend());
  ll l = -1, r = 1e12;
  while(l+1<r){
    ll mid = (l+r)/2;
    ll s = 0;
    bool ok = [&]{
      rep(i,n){
      s += max(0ll,a[i]-mid/f[i]);
      }
      return s<=k;
    }();
    if(ok) r = mid; else l = mid;
  }
  cout << r << endl;
}
