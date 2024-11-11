#include <bits/stdc++.h>
using namespace std;
const int N = 300 * 1000 + 13;
int n;
long long a[N], b[N];
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < int(n); ++i) scanf("%lld%lld", &a[i], &b[i]);
  long long ans = 0, mn = 1e18;
  for (int i = 0; i < int(n); ++i) {
    int ni = (i + 1) % n;
    long long val = min(a[ni], b[i]);
    ans += a[ni] - val;
    mn = min(mn, val);
  }
  ans += mn;
  printf("%lld\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < int(T); ++i) solve();
}
