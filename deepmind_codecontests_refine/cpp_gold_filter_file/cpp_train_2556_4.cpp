#include <bits/stdc++.h>
using namespace std;
int m[100005], f[100005][8], g[8][8], c[8][265];
char s[100005];
queue<int> q;
int main() {
  int n, u, v = 0;
  long long w = 0;
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; ++i) s[i] -= 97;
  memset(f, 0x3f, sizeof f);
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < n; ++j)
      if (i == s[j]) {
        f[j][i] = 0;
        q.emplace(j);
      }
    while (!q.empty()) {
      u = q.front();
      q.pop();
      if (u && f[u - 1][i] > f[u][i] + 1) {
        f[u - 1][i] = f[u][i] + 1;
        q.emplace(u - 1);
      }
      if (u < n - 1 && f[u + 1][i] > f[u][i] + 1) {
        f[u + 1][i] = f[u][i] + 1;
        q.emplace(u + 1);
      }
    }
  }
  memset(g, 0x3f, sizeof g);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 8; ++j)
      for (int k = 0; k < 8; ++k) g[j][k] = min(g[j][k], f[i][j] + f[i][k]);
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      for (int k = 0; k < 8; ++k) g[j][k] = min(g[j][k], g[j][i] + g[i][k] + 1);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 8; ++j)
      for (int k = 0; k < 8; ++k) f[i][j] = min(f[i][j], f[i][k] + g[j][k] + 1);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 8; ++j) m[i] |= (f[i][j] - g[(int)s[i]][j]) << j;
  for (int i = 0; i < n; ++i)
    for (int j = max(i - 15, 0); j < i; ++j) {
      u = i - j;
      for (int k = 0; k < 8; ++k) u = min(u, f[i][k] + f[j][k] + 1);
      if (v < u) {
        v = u;
        w = 1;
      } else if (v == u)
        ++w;
    }
  for (int i = 16, j = 0; i < n; ++i, ++j) {
    ++c[(int)s[j]][m[j]];
    for (int k = 0; k < 8; ++k)
      for (int l = 0; l < 256; ++l)
        if (c[k][l]) {
          u = 0x3fffffff;
          for (int o = 0; o < 8; ++o)
            u = min(u, f[i][o] + g[k][o] + ((l >> o) & 1) + 1);
          if (v < u) {
            v = u;
            w = c[k][l];
          } else if (v == u)
            w += c[k][l];
        }
  }
  printf("%d %lld\n", v, w);
  return 0;
}
