#include <bits/stdc++.h>
using namespace std;
long long k, pt[220000], hd[120000], nt[220000], d[220000], fa[220000], dc, ans,
    f[220000], s[220000], w[220000], n, q, i, sz[220000];
int x, y;
void add(int x, int y) {
  ++k;
  nt[k] = hd[x];
  hd[x] = k;
  pt[k] = y;
}
void Dfs(int x, int f) {
  d[x] = d[f] + 1;
  fa[x] = f;
  s[x] = 1;
  for (int i = hd[x]; i; i = nt[i]) {
    if (pt[i] == f) continue;
    Dfs(pt[i], x), s[x] += s[pt[i]], w[x] += s[pt[i]] * s[pt[i]];
  }
  w[x] += (n - s[x]) * (n - s[x]);
  dc += w[x];
}
int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
int main() {
  cin >> n;
  for (i = 1; i < n; ++i) scanf("%d%d", &x, &y), add(x, y), add(y, x);
  Dfs(1, 0);
  ans = n * (n - 1) * (n - 1) - dc;
  cout << ans << endl;
  cin >> q;
  for (i = 1; i <= n; ++i) f[i] = i, sz[i] = 1;
  while (q--) {
    scanf("%d%d", &x, &y);
    int xx = find(x), yy = find(y);
    while (xx != yy) {
      if (d[xx] < d[yy]) swap(xx, yy);
      int z = find(fa[xx]);
      ans -= (n - sz[xx]) * sz[xx] * (sz[xx] - 1) * 2 +
             (n - sz[z]) * sz[z] * (sz[z] - 1) * 2 +
             sz[z] * (sz[z] - 1) * (sz[z] - 2) +
             ((n - sz[z]) * (n - sz[z]) - w[z]) * sz[z] +
             ((n - sz[xx]) * (n - sz[xx]) - w[xx]) * sz[xx] +
             sz[xx] * (sz[xx] - 1) * (sz[xx] - 2);
      sz[z] += sz[xx];
      f[xx] = z;
      w[z] += w[xx] - s[xx] * s[xx] - (n - s[xx]) * (n - s[xx]);
      xx = z;
      ans += ((n - sz[z]) * (n - sz[z]) - w[z]) * sz[z] +
             sz[z] * (sz[z] - 1) * (sz[z] - 2) +
             (n - sz[z]) * sz[z] * (sz[z] - 1) * 2;
    }
    printf("%d\n", ans);
  }
}
