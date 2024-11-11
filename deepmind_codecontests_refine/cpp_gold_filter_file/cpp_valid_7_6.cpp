#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long seg[4 * N], a[N];
void build(int p, int s, int e) {
  if (s == e) {
    seg[p] = a[s];
    return;
  }
  int m = (s + e) / 2;
  build(2 * p, s, m);
  build(2 * p + 1, m + 1, e);
  seg[p] = gcd(seg[2 * p], seg[2 * p + 1]);
}
long long query(int p, int s, int e, int l, int r) {
  if (s > r || e < l) return 0;
  if (l <= s && e <= r) return seg[p];
  int m = (s + e) / 2;
  return gcd(query(2 * p, s, m, l, r), query(2 * p + 1, m + 1, e, l, r));
}
void solve() {
  int n;
  scanf("%d", &n);
  long long a[n];
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
  }
  for (int i = 0; i < n - 1; ++i) {
    ::a[i] = abs(a[i] - a[i + 1]);
  }
  build(1, 0, n - 1);
  long long l = 0, ans = 1;
  for (int r = 0; r < n - 1; ++r) {
    while (r >= l && query(1, 0, n - 1, l, r) == 1) {
      ++l;
    }
    ans = max(ans, r - l + 2);
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
}
