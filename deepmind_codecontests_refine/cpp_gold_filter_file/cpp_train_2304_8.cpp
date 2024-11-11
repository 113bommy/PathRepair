#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 205, p = 1000000007, inf = 0x3f3f3f3f;
int read() {
  int f = 1, g = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) g = g * 10 + ch - '0';
  return f * g;
}
int ans, n, k, size[N], str[M][M], f[N][M], g[M];
int siz, fir[N];
struct edge {
  int u, v, nex;
} e[N * 2];
void add(int u, int v) {
  e[++siz] = (edge){u, v, fir[u]};
  fir[u] = siz;
}
void check(int &x, int y) { x = (x + y < p) ? (x + y) : (x + y - p); }
void merge(int x, int y) {
  for (int i = min(size[x], k); i >= 0; i--) {
    for (int j = 1; (j <= min(size[y], k)) && (i + j <= k); j++)
      check(f[x][i + j], (long long)f[x][i] * f[y][j] % p);
    f[x][i] = (long long)f[x][i] * f[y][0] % p;
  }
  size[x] += size[y];
}
void work(int x, int fa) {
  f[x][0] = 2;
  size[x] = 1;
  for (int i = fir[x]; i; i = e[i].nex)
    if (e[i].v != fa) {
      work(e[i].v, x);
      merge(x, e[i].v);
      for (int j = 0; j <= min(size[e[i].v], k); j++)
        check(g[j], p - f[e[i].v][j]);
    }
  for (int i = 0; i <= min(size[x], k); i++) check(g[i], f[x][i]);
  for (int i = min(size[x], k); i >= 0; i--) check(f[x][i + 1], f[x][i]);
  check(f[x][1], p - 1);
}
int main() {
  n = read();
  k = read();
  str[0][0] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= i; j++)
      str[i][j] =
          ((long long)str[i - 1][j] * j + (long long)str[i - 1][j - 1] * j) % p;
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    add(u, v);
    add(v, u);
  }
  work(1, 0);
  for (int i = 0; i <= k; i++) check(ans, (long long)str[k][i] * g[i] % p);
  printf("%d\n", ans);
  return 0;
}
