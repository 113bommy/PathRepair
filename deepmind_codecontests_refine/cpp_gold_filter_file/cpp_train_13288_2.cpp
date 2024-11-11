#include <bits/stdc++.h>
using namespace std;
const int N = 1001000, P = 1e9 + 7;
int n, cnt, x, y, u;
int Fa[N], s[N][30], l[N], fa[N], tp[N];
int p[N], f[N], g[N], ok[N], d[N];
char S[N], T[N];
void ins(int c, int p) {
  for (x = y; S[p] != S[p - l[x] - 1]; x = Fa[x])
    ;
  if (s[x][c]) return y = s[x][c], void();
  l[s[x][c] = y = ++cnt] = l[x] + 2;
  ok[y] = ok[x];
  if (x == 1) return;
  for (x = Fa[x]; S[p] != S[p - l[x] - 1]; x = Fa[x])
    ;
  Fa[y] = s[x][c];
}
int main() {
  scanf("%s", T + 1);
  n = strlen(T + 1);
  if (n & 1) return puts("0");
  for (int i = 1; i <= n / 2; i++) S[i * 2 - 1] = T[i], S[i * 2] = T[n - i + 1];
  l[Fa[0] = ok[0] = y = cnt = 1] = -1;
  for (int i = 1; i <= n; i++) ins(S[i] - 'a', i), p[i] = y;
  for (int i = 1; i <= cnt; i++) {
    fa[i] = ok[Fa[i]] ? Fa[i] : fa[Fa[i]];
    d[i] = l[i] - l[fa[i]];
    if (ok[i] && fa[i] != 0) tp[i] = d[i] == d[fa[i]] ? tp[fa[i]] : fa[i];
  }
  f[0] = 1;
  for (int i = 1; i <= n; i++)
    if (!(i & 1)) {
      f[i] = 0;
      for (u = ok[p[i]] ? p[i] : fa[p[i]]; u; u = tp[u]) {
        if (d[u] != d[fa[u]])
          (f[i] += (g[u] = f[i - l[u]])) %= P;
        else
          (f[i] += (g[u] = (g[fa[u]] + f[i - l[tp[u]] - d[u]]) % P)) %= P;
      }
    }
  printf("%d\n", f[n]);
}
