#include <bits/stdc++.h>
using namespace std;
int n, m, ft, cp, ed, x, y, lo, hi, SS, TT, S, T, V, ret;
int v[500], l[500], d[500], g[500], ex[50000], ey[50000];
int lbl[500][500], qd[50000], qn[50000], qc[50000];
void bd(int x, int y, int c) {
  qd[++ed] = y, qn[ed] = l[x], l[x] = ed, qc[ed] = c;
}
int ISAP(int x, int y) {
  int mn = V - 1, F = 0, R = y, t;
  if (x == T) return y;
  for (int i = l[x]; i; i = qn[i]) {
    if (qc[i] > 0) {
      if (v[x] == v[qd[i]] + 1) {
        t = ISAP(qd[i], min(qc[i], R));
        qc[i] -= t;
        qc[i ^ 1] += t;
        R -= t;
        F += t;
        if (v[S] >= V) return F;
        if (!R) break;
      }
      mn = min(mn, v[qd[i]]);
    }
  }
  if (!F) {
    g[v[x]]--;
    if (!g[v[x]]) v[S] = V;
    v[x] = mn + 1;
    g[v[x]]++;
  }
  return F;
}
int MaxFlow() {
  memset(v, 0, sizeof(v));
  memset(g, 0, sizeof(g));
  int ret = 0;
  g[0] = V;
  while (v[S] < V) ret += ISAP(S, 1 << 30);
  return ret;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &ft, &cp);
  memset(lbl, -1, sizeof(lbl));
  for (int i = (0); i < (ft); i++) {
    scanf("%d%d", &x, &y);
    x--, y--;
    ex[i] = x, ey[i] = y;
    lbl[x][y] = -2;
    d[x]++, d[y + n]++;
  }
  for (int i = (0); i < (n + m); i++) ret += !!(d[i] % cp);
  SS = n + m;
  TT = SS + 1;
  S = TT + 1;
  T = S + 1;
  V = n + m + 4;
  for (int i = (0); i < (cp); i++) {
    memset(l, 0, sizeof(l));
    ed = 1;
    for (int j = (0); j < (n); j++)
      for (int k = (0); k < (m); k++)
        if (lbl[j][k] == -2) bd(j, k + n, 1), bd(k + n, j, 0);
    for (int j = (0); j < (n); j++) {
      lo = d[j] / (cp - i);
      hi = (d[j] + cp - i - 1) / (cp - i);
      bd(SS, j, hi - lo), bd(j, SS, 0);
      bd(S, j, lo), bd(j, S, 0);
      bd(SS, T, lo), bd(T, SS, 0);
    }
    for (int j = (n); j < (n + m); j++) {
      lo = d[j] / (cp - i);
      hi = (d[j] + cp - i - 1) / (cp - i);
      bd(j, TT, hi - lo), bd(TT, j, 0);
      bd(S, TT, lo), bd(TT, S, 0);
      bd(j, T, lo), bd(T, j, 0);
    }
    bd(SS, TT, (1 << 28)), bd(TT, SS, 0);
    MaxFlow();
    for (int j = (0); j < (n); j++)
      for (int k = (l[j]); k; k = qn[k])
        if (qd[k] >= n && qd[k] < n + m && !qc[k]) {
          d[j]--;
          d[qd[k]]--;
          lbl[j][qd[k] - n] = i;
        }
  }
  printf("%d\n", ret);
  for (int i = (0); i < (ft); i++) printf("%d ", lbl[ex[i]][ey[i]] + 1);
  return 0;
}
