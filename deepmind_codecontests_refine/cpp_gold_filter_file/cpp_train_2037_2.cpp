#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
int n, m, f[110][210], g[210];
vector<int> v[110];
void dfs(int np, int fath) {
  f[np][0] = f[np][m + 1] = 1;
  for (int &x : v[np]) {
    if (x == fath) continue;
    dfs(x, np);
    memset(g, 0, sizeof(g));
    for (int i = 0; i <= 2 * m + 1; i++) {
      for (int j = 0; j <= 2 * m; j++) {
        if (i + j <= 2 * m) {
          int p = min(i, j + 1);
          g[p] = add(g[p], mult(f[np][i], f[x][j]));
        } else {
          int p = max(i, j + 1);
          g[p] = add(g[p], mult(f[np][i], f[x][j]));
        }
      }
    }
    for (int i = 0; i <= 2 * m; i++) f[np][i] = g[i];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, ti, tj; i < n; i++) {
    scanf("%d%d", &ti, &tj);
    v[ti].push_back(tj);
    v[tj].push_back(ti);
  }
  dfs(1, 0);
  int ans = 0;
  for (int i = 0; i <= m; i++) ans = add(ans, f[1][i]);
  printf("%d\n", ans);
  return 0;
}
