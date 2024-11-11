#include <bits/stdc++.h>
using namespace std;
inline int _in() {
  char tt = getchar();
  int o, f = 0;
  while (tt < '0' || tt > '9') {
    if (tt == '-') f = 1;
    tt = getchar();
  }
  for (o = 0; tt >= '0' && tt <= '9'; tt = getchar()) o = o * 10 + tt - '0';
  return f ? -o : o;
}
int n, m, W, fa[1005], w[1005], b[1005];
int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
vector<int> p[1005];
int f[1005], g[1005];
int main() {
  n = _in();
  m = _in();
  W = _in();
  for (int i = 1; i <= n; i++) {
    w[i] = _in();
    fa[i] = i;
  }
  for (int i = 1; i <= n; i++) b[i] = _in();
  for (int i = 1; i <= m; i++) {
    int x, y;
    x = _in(), y = _in();
    x = getfa(x), y = getfa(y);
    if (x != y) fa[x] = y;
  }
  for (int i = 1; i <= n; i++) {
    p[getfa(i)].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= W; j++) g[j] = f[j];
    int sumw = 0, sumb = 0;
    for (int j = 0; j < p[i].size(); j++) {
      int x = p[i][j];
      sumw += w[x], sumb += b[x];
    }
    for (int j = W; j >= sumw; j--) f[j] = max(f[j], g[j - sumw] + sumb);
    for (int k = 0; k < p[i].size(); k++) {
      int x = p[i][k];
      for (int j = W; j >= w[x]; j--) f[j] = max(f[j], g[j - w[x]] + b[x]);
    }
  }
  int ans = 0;
  for (int i = 0; i <= W; i++) ans = max(ans, f[i]);
  cout << ans;
  return 0;
}
