#include <bits/stdc++.h>
#pragma GCC optimize( \
    "Ofast,vpt,unroll-loops,shrink-wrap-separate,loop-nest-optimize")
using namespace std;
const int nax = 500005, dax = 2, lim = 50, lgax = 25, bit = 64,
          mod = 1000000007, inf = 1000000007;
const long long llax = 9e18;
int t[nax][2], a[nax], nxt;
void add(long long x, int b) {
  int node = 0;
  for (int i = b; i >= 0; --i) {
    if (!t[node][(x >> i) & 1]) t[node][(x >> i) & 1] = ++nxt;
    node = t[node][(x >> i) & 1];
  }
}
void del(long long x, int b) {
  int node = 0, tmp;
  for (int i = b; i >= 0; --i) {
    tmp = t[node][(x >> i) & 1];
    t[node][(x >> i) & 1] = 0;
    node = tmp;
  }
}
long long query(long long x, int b) {
  int node = 0;
  long long res = 0;
  for (int i = b; i >= 0; --i) {
    if (t[node][(x >> i) & 1])
      node = t[node][(x >> i) & 1];
    else if (t[node][!((x >> i) & 1)])
      node = t[node][!((x >> i) & 1)], res += 1ll << i;
    else
      return 0;
  }
  return res;
}
long long rec(int l, int r, int b) {
  if (l >= r || b < 0) return 0;
  int m = partition(a + l, a + r + 1, [&](int x) { return (x >> b) & 1; }) - a;
  long long res = llax;
  for (int i = l; i < m; ++i) add(a[i], b);
  for (int i = m; i <= r; ++i) res = min(res, query(a[i], b));
  if (res == llax) res = 0;
  for (int i = l; i < m; ++i) del(a[i], b);
  return res + rec(l, m - 1, b - 1) + rec(m, r, b - 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << rec(0, n - 1, 2) << '\n';
  return 0;
}
