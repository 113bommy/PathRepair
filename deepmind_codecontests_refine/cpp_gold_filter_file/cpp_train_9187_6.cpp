#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long mo = 536870911;
long long T, n, m, i, t, j, k, x, y, z, q, p, s, num, bz1, l, mx, r, ll, rr;
vector<int> f[N], g[N];
vector<pair<int, int> > ans;
int d[N], b[N], bz[N], v[N];
long long get() {
  long long f = 1, s = 0;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) s = s * 10 + c - 48;
  return f * s;
}
int main() {
  T = get();
  while (T--) {
    n = get();
    m = get();
    ans.clear();
    for (long long i = 1; i <= n; i++)
      d[i] = b[i] = 0, bz[i] = 1e9, f[i].clear(), g[i].clear();
    for (long long i = 1; i <= m; i++) {
      z = get();
      x = get();
      y = get();
      if (z)
        d[y]++, f[x].push_back(y), ans.push_back(make_pair(x, y));
      else
        g[x].push_back(y), g[y].push_back(x);
    }
    j = 0;
    for (long long i = 1; i <= n; i++)
      if (!d[i]) v[++j] = i, bz[i] = j;
    i = 0;
    while (i < j) {
      x = v[++i];
      for (auto y : f[x]) {
        d[y]--;
        if (!d[y]) v[++j] = y, bz[y] = j;
      }
      for (auto y : g[x]) {
        if (bz[y] < bz[x]) continue;
        ans.push_back(make_pair(x, y));
      }
    }
    printf("%s\n", (j == n) ? "YES" : "NO");
    if (j == n) {
      for (auto p : ans) printf("%d %d\n", p.first, p.second);
    }
  }
}
