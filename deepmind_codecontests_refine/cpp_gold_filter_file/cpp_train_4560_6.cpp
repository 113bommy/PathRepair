#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());
  ll l = -1, r = 1e12;
  while (l+1<r) {
    ll c = (l+r)/2;
    bool ok = [&]{
      ll s = 0;
      rep(i,n) {
        s += max(0ll, a[i]-c/f[i]);
      }
      return s <= k;
    }();
    if (ok) r = c; else l = c;
  }
  cout << r << endl;
  return 0;
}