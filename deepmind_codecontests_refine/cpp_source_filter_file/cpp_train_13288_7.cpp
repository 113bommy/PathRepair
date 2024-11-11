#include <bits/stdc++.h>
using namespace std;
int n, od, ev, c, ls, nx[1000010][26], sm[1000010], f[1000010], len[1000010],
    fail[1000010], hf[1000010], d[1000010];
char S[1000010], s[1000010];
int nwc(int L) {
  len[++c] = L + 2;
  return c;
}
int find(int x, int w) {
  for (; x && s[w] != s[w - len[x] - 1]; x = fail[x])
    ;
  return x;
}
void ins(int w, int c) {
  int p = find(ls, w);
  if (nx[p][c]) {
    ls = nx[p][c];
    return;
  }
  int nw = nx[p][c] = nwc(len[p]);
  int x = find(fail[p], w);
  if (!x)
    fail[nw] = ev;
  else
    fail[nw] = nx[x][c];
  d[nw] = len[nw] - len[fail[nw]];
  hf[nw] = d[nw] == d[fail[nw]] ? hf[fail[nw]] : fail[nw];
  ls = nw;
}
int main() {
  scanf("%s", S + 1);
  n = strlen(S + 1);
  ls = od = nwc(-3);
  ev = nwc(-2);
  fail[ev] = od;
  for (int i = 1; i <= n; ++i) s[i] = S[i % 2 ? i + 1 >> 1 : n + 1 - (i >> 1)];
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    ins(i, s[i] - 97);
    for (int u = ls; u > od; u = hf[u]) {
      sm[u] = f[i - len[hf[u]] - d[u]];
      if (hf[u] ^ fail[u]) sm[u] = (sm[u] + sm[fail[u]]) % 1000000007;
      if (1 + len[u] & 1) f[i] = (f[i] + sm[u]) % 1000000007;
    }
  }
  printf("%d", f[n]);
}
