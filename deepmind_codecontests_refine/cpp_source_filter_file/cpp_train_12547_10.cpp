#include <bits/stdc++.h>
using namespace std;
const int N = 2020, M = 2002000;
int i, j, k, n, nn, m1, m2, ff, ch, x, y, k1, k2, m;
int p[N];
struct edge {
  int s, n;
};
struct Graph {
  int num, time, dn, en, En;
  int A[N], B[N], b[N], d[N], z[N], h[N], H[N], in[N], tmp[N], fg[N];
  edge e[M], E[M];
  bitset<2020> a[N], map[N];
  void e_add(int x, int y) {
    e[++en].s = y;
    e[en].n = h[x];
    h[x] = en;
  }
  void E_add(int x, int y) {
    E[++En].s = y;
    E[En].n = H[x];
    H[x] = En;
    in[y]++;
  }
  void Tj(int x) {
    A[x] = B[x] = ++time;
    d[++dn] = x;
    z[x] = 1;
    for (int k = h[x]; k; k = e[k].n) {
      if (!A[e[k].s]) {
        Tj(e[k].s);
        if (B[e[k].s] < B[x]) B[x] = B[e[k].s];
      } else if (z[e[k].s] && A[e[k].s] < B[x])
        B[x] = A[e[k].s];
    }
    if (A[x] == B[x]) {
      num++;
      int now = 0;
      while (now != x) {
        now = d[dn--];
        b[now] = num;
        z[now] = 0;
      }
    }
  }
  bool rebuild() {
    int i, k;
    for (i = 2; i <= nn; i++)
      if (!A[i]) Tj(i);
    for (i = 1; i <= n; i++)
      if (b[i << 1] == b[i << 1 | 1]) return 0;
    for (i = 2; i <= nn; i++)
      for (k = h[i]; k; k = e[k].n)
        if (b[i] != b[e[k].s] && !a[b[i]][b[e[k].s]])
          a[b[i]][b[e[k].s]] = 1, E_add(b[e[k].s], b[i]);
    return 1;
  }
  void solve() {
    int i, j = 0, k, jj;
    for (i = 1; i <= num; i++) tmp[i] = in[i];
    for (i = 1; i <= num; i++)
      if (!fg[i] && !tmp[i]) {
        d[++j] = i;
        for (jj = 2; jj <= nn; jj++)
          if (b[jj] == i) fg[b[jj ^ 1]] = 1;
      }
    i = 0;
    while (i < j) {
      i++;
      for (k = H[d[i]]; k; k = E[k].n)
        if (!fg[i] && --tmp[E[k].s] == 0) {
          d[++j] = E[k].s;
          for (jj = 2; jj <= nn; jj++)
            if (b[jj] == d[j]) fg[b[jj ^ 1]] = 1;
        }
    }
    for (i = 2; i <= nn; i++)
      if (!fg[b[i]]) printf("%d ", i & 1);
    puts("");
  }
  void Js() {
    int i, j = 0, k;
    for (i = 1; i <= num; i++) tmp[i] = in[i], map[i][i] = 1;
    for (i = 1; i <= num; i++)
      if (!tmp[i]) d[++j] = i;
    i = 0;
    while (i < j) {
      i++;
      for (k = H[d[i]]; k; k = E[k].n) {
        map[E[k].s] |= map[d[i]];
        if (--tmp[E[k].s] == 0) d[++j] = E[k].s;
      }
    }
    for (i = 1; i <= num; i++) {
      for (j = 2; j <= nn; j++)
        if (b[j] == i && map[i][b[j ^ 1]]) {
          fg[i] = 1;
          break;
        }
    }
  }
} F, G;
void R(int &x) {
  ff = x = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') ff = 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (ff) x = -x;
}
int main() {
  R(n);
  R(m1);
  R(m2);
  for (i = 1; i <= m1; i++) {
    R(x);
    R(y);
    if (x < 0)
      x = (-x) << 1;
    else
      x = x << 1 | 1;
    if (y < 0)
      y = (-y) << 1;
    else
      y = y << 1 | 1;
    F.e_add(x ^ 1, y);
    F.e_add(y ^ 1, x);
  }
  for (i = 1; i <= m2; i++) {
    R(x);
    R(y);
    if (x < 0)
      x = (-x) << 1;
    else
      x = x << 1 | 1;
    if (y < 0)
      y = (-y) << 1;
    else
      y = y << 1 | 1;
    G.e_add(x ^ 1, y);
    G.e_add(y ^ 1, x);
  }
  nn = n << 1 | 1;
  k1 = F.rebuild();
  k2 = G.rebuild();
  if (!k1 && !k2) return puts("SIMILAR"), 0;
  if (k1 != k2) {
    if (k1)
      F.solve();
    else
      G.solve();
    return 0;
  }
  F.Js();
  G.Js();
  for (i = 1; i <= n; i++) {
    k1 = F.fg[F.b[i << 1]] << 1 | F.fg[F.b[i << 1 | 1]];
    k2 = G.fg[G.b[i << 1]] << 1 | G.fg[G.b[i << 1 | 1]];
    if (k1 != k2) {
      if ((k1 == 1 && k2 == 2) || (k1 == 2 && k2 == 1)) {
        F.solve();
        return 0;
      }
      if (k1 == 0) {
        if (k2 == 2)
          F.fg[F.b[i << 1 | 1]] = 1;
        else
          F.fg[F.b[i << 1]] = 1;
        F.solve();
        return 0;
      }
      if (k2 == 0) {
        if (k1 == 2)
          G.fg[G.b[i << 1 | 1]] = 1;
        else
          G.fg[G.b[i << 1]] = 1;
        G.solve();
        return 0;
      }
    }
    if (!k1) p[++m] = i << 1, p[++m] = i << 1 | 1;
  }
  for (i = 1; i <= m; i++)
    for (j = 1; j <= m; j++)
      if ((p[i] >> 1) != (p[j] >> 1)) {
        k1 = F.map[F.b[p[i]]][F.b[p[j]]];
        k2 = G.map[G.b[p[i]]][G.b[p[j]]];
        if (k1 != k2) {
          if (k1) {
            G.fg[G.b[p[i] ^ 1]] = 1;
            G.fg[G.b[p[j]]] = 1;
            G.solve();
            return 0;
          } else {
            F.fg[F.b[p[i] ^ 1]] = 1;
            F.fg[F.b[p[j]]] = 1;
            F.solve();
            return 0;
          }
        }
      }
  puts("SIMILAR");
}
