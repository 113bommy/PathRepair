#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3e3 + 5, Mod = 1e9 + 7;
int fpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % Mod;
    x = 1ll * x * x % Mod;
    y >>= 1;
  }
  return res;
}
int Lagrange(int n, int *x, int *y, int xi) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int s1 = 1, s2 = 1;
    for (int j = 0; j <= n; j++)
      if (i != j) {
        s1 = 1ll * (xi - x[j]) % Mod * s1 % Mod;
        s2 = 1ll * (x[i] - x[j]) % Mod * s2 % Mod;
      }
    res = (res + 1ll * y[i] * s1 % Mod * fpow(s2, Mod - 2) % Mod) % Mod;
    res = (res + Mod) % Mod;
  }
  return res;
}
struct Graph {
  int to, next;
} e[MAX_N << 1];
int fir[MAX_N], e_cnt;
void clearGraph() {
  memset(fir, -1, sizeof(fir));
  e_cnt = 0;
}
void Add_Edge(int u, int v) { e[e_cnt] = (Graph){v, fir[u]}, fir[u] = e_cnt++; }
int N, D, f[MAX_N][MAX_N];
void dfs(int x) {
  for (int i = 1; i <= N; i++) f[x][i] = 1;
  for (int i = fir[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    dfs(v);
    for (int j = 1; j <= N; j++) f[x][j] = 1ll * f[x][j] * f[v][j] % Mod;
  }
  for (int i = 1; i <= N; i++) f[x][i] = (f[x][i] + f[x][i - 1]) % Mod;
}
int x[MAX_N], y[MAX_N];
int main() {
  clearGraph();
  scanf("%d%d", &N, &D);
  for (int i = 2, fa; i <= N; i++) scanf("%d", &fa), Add_Edge(fa, i);
  dfs(1);
  for (int i = 1; i <= N; i++) x[i] = i, y[i] = f[1][i];
  printf("%d\n", Lagrange(N, x, y, D));
  return 0;
}
