#include <bits/stdc++.h>
using namespace std;
long long n, a[200005];
long long f[200005], siz[200005], lf[200005];
long long ee, h[200005], nex[200005 << 1], to[200005 << 1];
void addedge(long long x, long long y) {
  nex[++ee] = h[x];
  to[ee] = y;
  h[x] = ee;
}
void dfs(long long x, long long pre) {
  siz[x] = a[x];
  bool leaf = 1;
  for (long long i = h[x]; i; i = nex[i])
    if (to[i] != pre) {
      leaf = 0;
      dfs(to[i], x);
      siz[x] += siz[to[i]], lf[x] += lf[to[i]];
      f[x] = max(f[x], f[to[i]]);
    }
  lf[x] += leaf;
  f[x] = max(f[x], (siz[x] + lf[x] - 1) / lf[x]);
}
signed main() {
  cin >> n;
  for (long long i = 2, x; i <= n && cin >> x; i++)
    addedge(i, x), addedge(x, i);
  for (long long i = 1; i <= n; cin >> a[i++])
    ;
  dfs(1, 0);
  cout << f[1] << endl;
  return 0;
}
