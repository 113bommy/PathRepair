#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, x, y, z, nn, flag;
int id[60][60], f[60 * 2][60][60], o[60 * 2][60][60], re[60 * 2][60];
vector<int> a[3000], g, h;
vector<pair<int, int> > q[60], w[60];
bool dfs(int x, int y, int ty) {
  if (!ty && x == g.size() || ty && x == h.size()) return 1;
  int i;
  int A = !ty ? g[x] : h[x], B = !ty ? id[y][A] : id[A][y];
  if (!B) return 0;
  if (!ty) {
    for (i = 0; i < a[B].size(); i++) {
      int C = a[B][i];
      g.push_back(C);
      if (g.size() > nn) return 0;
    }
  } else {
    for (i = a[B].size() - 1; i >= 0; i--) {
      int C = a[B][i];
      h.push_back(C);
      if (h.size() > nn) return 0;
    }
  }
  return dfs(x + 1, A, ty);
}
inline void work1(int i, int j) {
  int A = id[i][j], wei, len = a[A].size();
  if (!A || len < 2) return;
  for (k = 0; k + 1 < len; k++) {
    int B = a[A][k], C = a[A][k + 1];
    if (B == i && C == j) break;
  }
  if (k + 1 == len) return;
  wei = k;
  g.clear();
  for (k = wei + 1; k < len; k++) {
    int B = a[A][k];
    g.push_back(B);
    if (g.size() > nn) return;
  }
  h.clear();
  for (k = wei; k >= 0; k--) {
    int B = a[A][k];
    h.push_back(B);
    if (h.size() > nn) return;
  }
  if (dfs(1, j, 0) && dfs(1, i, 1)) {
    int B = g.size() + h.size();
    if (B <= nn) f[B - 1][h[h.size() - 1]][g[g.size() - 1]]++;
  }
}
inline void work2(int i, int j) {
  int A = id[i][j], len = a[A].size();
  if (!len) return;
  if (a[A][len - 1] != i) return;
  h.clear();
  for (k = len - 1; k >= 0; k--) {
    int B = a[A][k];
    h.push_back(B);
    if (h.size() > nn) return;
  }
  if (dfs(1, i, 1)) {
    int B = h.size();
    q[j].push_back(make_pair(h[B - 1], B));
  }
}
inline void work3(int i, int j) {
  int A = id[i][j], len = a[A].size();
  if (!len) return;
  if (a[A][0] != j) return;
  g.clear();
  for (k = 0; k < len; k++) {
    int B = a[A][k];
    g.push_back(B);
    if (g.size() > nn) return;
  }
  if (dfs(1, j, 0)) {
    int B = g.size();
    w[i].push_back(make_pair(g[B - 1], B));
  }
}
inline void S(int &x, int y) {
  x += y;
  if (x >= 1000000007) x -= 1000000007;
}
inline void print() {
  int i, j, k;
  for (i = 1; i <= 40; i++) {
    int an = 0;
    for (j = 1; j <= n; j++)
      for (k = 1; k <= n; k++)
        if (f[i][j][k]) printf("%d %d %d %d\n", i, j, k, f[i][j][k]);
  }
  printf("\n");
}
inline void work() {
  int u, r, v, x, y, t;
  for (i = 1; i <= nn; i++)
    for (u = 1; u <= n; u++)
      for (r = 1; r <= n; r++)
        if (x = f[i][u][r]) {
          for (j = 0; j < q[u].size(); j++) {
            pair<int, int> A = q[u][j];
            int B = A.second + i;
            if (B <= nn) S(f[B][A.first][r], x);
          }
        }
  for (i = 1; i <= nn; i++)
    for (u = 1; u <= n; u++)
      for (r = 1; r <= n; r++)
        if (x = f[i][u][r]) {
          for (j = 0; j < w[r].size(); j++) {
            pair<int, int> A = w[r][j];
            int B = A.second + i;
            if (B <= nn) S(f[B][u][A.first], x);
          }
        }
  for (i = 1; i <= nn; i++)
    for (u = 1; u <= n; u++)
      for (r = 1; r <= n; r++)
        if (x = f[i][u][r]) {
          for (v = 1; v <= n; v++) {
            int A = id[r][v];
            if (A && !a[A].size()) S(o[i + 1][u][v], x);
          }
          S(re[i][u], x);
        }
  for (i = 1; i <= nn; i++)
    for (u = 1; u <= n; u++)
      if (x = re[i][u]) {
        for (j = 1; j <= nn - i; j++) {
          for (v = 1; v <= n; v++)
            if (y = o[j][v][u]) S(re[i + j][v], 1ll * x * y % 1000000007);
        }
      }
}
int main() {
  scanf("%d%d", &n, &m);
  nn = n * 2 + 1;
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &k);
    id[x][y] = i;
    for (j = 1; j <= k; j++) scanf("%d", &z), a[i].push_back(z);
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      work1(i, j);
      work2(i, j);
      work3(i, j);
    }
  work();
  for (i = 1; i <= nn - 1; i++) {
    int an = 0;
    for (j = 1; j <= n; j++) S(an, re[i][j]);
    printf("%d\n", an);
  }
  return 0;
}
