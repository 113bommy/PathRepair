#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, W, fa[1010], w[1010], b[1010];
long long f[1010][1010], tw[1010], tb[1010], ans;
int findf(int x) { return x == fa[x] ? x : fa[x] = findf(fa[x]); }
vector<int> mp[1010];
int main() {
  n = rd();
  m = rd();
  W = rd();
  for (int i = 1; i <= n; i++) tw[i] = w[i] = rd();
  for (int i = 1; i <= n; i++) tb[i] = b[i] = rd();
  int tx, ty;
  for (int i = 1; i <= n; i++) fa[i] = i, mp[i].push_back(i);
  vector<int>::iterator it;
  for (int i = 1, x, y; i <= m; i++) {
    x = rd();
    y = rd();
    tx = findf(x);
    ty = findf(y);
    if (tx != ty) {
      tw[tx] += tw[ty];
      tb[tx] += tb[ty];
      fa[ty] = tx;
      for (it = mp[ty].begin(); it != mp[ty].end(); it++) {
        mp[tx].push_back(*it);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    memcpy(f[i], f[i - 1], sizeof(f[i]));
    if (findf(i) != i) continue;
    for (int j = 0, tp; j <= W; j++) {
      if (j >= tw[i]) f[i][j] = max(f[i][j], f[i - 1][j - tw[i]] + tb[i]);
      for (it = mp[i].begin(); it != mp[i].end(); it++) {
        tp = *it;
        if (j >= w[tp]) f[i][j] = max(f[i][j], f[i - 1][j - w[tp]] + b[tp]);
      }
    }
  }
  for (int i = 0; i <= W; i++) ans = max(ans, f[n][i]);
  printf("%lld\n", ans);
  return 0;
}
