#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, S = 26, P = 1e9 + 7;
inline void pls(int &a, int b) {
  a += b;
  if (a >= P) a -= P;
}
char s0[N], s[N];
int st, t, nxt[N][S], l[N], fa[N], lk[N], df[N], g[N], f[N];
void init() {
  st = 1;
  t = 1;
  l[1] = -1;
  fa[0] = 1;
}
void insert(int n) {
  int c = s[n] - 'a', p, f;
  for (p = st; s[n - l[p] - 1] != s[n]; p = fa[p])
    ;
  f = p;
  if (!nxt[f][c]) {
    for (p = fa[f]; s[n - l[p] - 1] != s[n]; p = fa[p])
      ;
    fa[++t] = nxt[p][c];
    nxt[f][c] = t;
    l[t] = l[f] + 2;
    df[t] = l[t] - l[fa[t]];
    lk[t] = df[t] == df[fa[t]] ? lk[fa[t]] : fa[t];
  }
  st = nxt[f][c];
}
int main() {
  init();
  scanf("%s", s0 + 1);
  int n = strlen(s0 + 1);
  for (register int i = 1, j = 0; i << 1 <= n; i++)
    s[++j] = s0[i], s[++j] = s0[n - i + 1];
  f[0] = 1;
  for (register int i = 1; i <= n; i++) {
    insert(i);
    for (register int p = st; p; p = lk[p]) {
      g[p] = f[i - df[p] - l[lk[p]]];
      if (lk[p] != fa[p]) pls(g[p], g[fa[p]]);
      if (i & 1 ^ 1) pls(f[i], g[p]);
    }
  }
  printf("%d", f[n]);
  return 0;
}
