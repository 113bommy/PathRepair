#include <bits/stdc++.h>
char BB[1 << 20], *SS, *TT;
int R() {
  int re = 0;
  char c =
      (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 20, stdin), SS == TT)
           ? EOF
           : *SS++);
  while (!isdigit(c))
    c = (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 20, stdin), SS == TT)
             ? EOF
             : *SS++);
  while (isdigit(c))
    re = re * 10 + c - '0',
    c = (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 20, stdin), SS == TT)
             ? EOF
             : *SS++);
  return re;
}
const int N = 105, mod = 1e9 + 7;
int e[N << 1], nt[N << 1], hd[N], cnt;
void bb(int a, int b) {
  e[++cnt] = b;
  nt[cnt] = hd[a];
  hd[a] = cnt;
  return;
}
int n, k;
int f[N][N], g[N];
void dfs(int a, int fa) {
  f[a][0] = f[a][k + 1] = 1;
  for (int i = hd[a]; i; i = nt[i]) {
    int v = e[i];
    if (v == fa) continue;
    dfs(v, a);
    memset(g, 0, sizeof(g));
    for (int i = 0; i <= 2 * k; i++) {
      for (int j = 0; j <= 2 * k; j++)
        (g[i + j <= 2 * k ? std::min(i, j + 1) : std::max(i, j + 1)] +=
         1ll * f[a][i] * f[v][j] % mod) %= mod;
    }
    memcpy(f[a], g, sizeof(f[a]));
  }
  return;
}
int main() {
  n = R(), k = R();
  for (int i = 1, a, b; i < n; i++) a = R(), b = R(), bb(a, b), bb(b, a);
  dfs(1, 0);
  int re = 0;
  for (int i = 0; i <= k; i++) (re += f[1][i]) %= mod;
  return printf("%d\n", re), 0;
}
