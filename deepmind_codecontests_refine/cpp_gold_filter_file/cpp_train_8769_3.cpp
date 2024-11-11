#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9 + 7;
const int N = 2e5 + 2;
ll total(ll val) { return (val * (val + 1)) / 2; }
int main() {
  int n;
  ll x;
  scanf("%d", &n);
  scanf("%lld", &x);
  vector<ll> d(2 * n + 1, 0);
  for (int i = (int)(0); i < (int)(n); i++) {
    scanf("%lld", &d[i]);
    d[n + i] = d[i];
  }
  ll hugs = 0, len = 0, ans = 0;
  int j = 0;
  for (int i = (int)(0); i < (int)(2 * n); i++) {
    hugs += total(d[i]);
    len += d[i];
    while (len > x) {
      hugs -= total(d[j]);
      len -= d[j];
      j++;
    }
    ll here = hugs;
    if (j != 0) {
      ll skips = d[j - 1] + len - x;
      here += total(d[j - 1]) - total(skips);
    }
    ans = max(ans, here);
  }
  printf("%lld\n", ans);
  return 0;
}
