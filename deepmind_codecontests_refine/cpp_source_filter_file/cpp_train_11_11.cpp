#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005, maxm = 320, tt = 998244353;
int n, m, n1, a[maxn], f[maxn], g[maxm][maxn], bl[maxn], sq, val[maxn],
    tag[maxm];
int L[maxn], R[maxn];
int las[maxn], las1[maxn];
void build(int x, int l, int r) {
  for (int i = l; i <= r; i++) {
    g[x][val[i]] = (g[x][val[i]] + f[i - 1]) % tt;
  }
  for (int i = 1; i <= n1; i++) g[x][i] = (g[x][i] + g[x][i - 1]) % tt;
}
void change(int l, int r, int p, int now) {
  int st = bl[l] + 1, ed = bl[r] - 1;
  if (st <= ed)
    for (int i = st; i <= ed; i++) tag[i] += p;
  if (bl[l] != bl[r]) {
    for (int i = l; i <= R[bl[l]]; i++)
      if (p == -1)
        (g[bl[i]][val[i] + p] += f[i - 1]) %= tt, val[i]--;
      else
        (((g[bl[i]][val[i]] -= f[i - 1]) %= tt) += tt) %= tt, val[i]++;
    if (bl[r] != bl[now] || (bl[r] == bl[now] && R[bl[now]] == now)) {
      for (int i = L[bl[r]]; i <= r; i++)
        if (p == -1)
          (g[bl[i]][val[i] + p] += f[i - 1]) %= tt, val[i]--;
        else
          (((g[bl[i]][val[i]] -= f[i - 1]) %= tt) += tt) %= tt, val[i]++;
    } else {
      for (int i = L[bl[r]]; i <= r; i++)
        if (p == -1)
          val[i]--;
        else
          val[i]++;
    }
  } else {
    if (bl[r] != bl[now] || (bl[r] == bl[now] && R[bl[now]] == now)) {
      for (int i = l; i <= r; i++)
        if (p == -1)
          (g[bl[i]][val[i] + p] += f[i - 1]) %= tt, val[i]--;
        else
          (((g[bl[i]][val[i]] -= f[i - 1]) %= tt) += tt) %= tt, val[i]++;
    } else {
      for (int i = l; i <= r; i++)
        if (p == -1)
          val[i]--;
        else
          val[i]++;
    }
  }
}
int query(int l, int r) {
  int ret = 0;
  for (int i = bl[l]; i < bl[r]; i++) ret = (ret + g[i][m - tag[i]]) % tt;
  for (int i = L[bl[r]]; i <= r; i++)
    if (val[i] + tag[bl[r]] <= m) ret = (ret + f[i - 1]) % tt;
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  n1 = m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), n1 = max(n1, a[i]);
  int ls = 0, bls = 0;
  sq = sqrt(n);
  for (int i = 1; i <= n; i++) {
    bl[i] = bls + 1;
    if (i - ls == sq || i == n) L[++bls] = ls + 1, R[bls] = i, ls = i;
  }
  ls = 0, bls = 0;
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (i == ls + sq) {
      build(++bls, ls + 1, i);
      ls = i;
    }
    if (las[a[i]]) change(las1[a[i]] + 1, las[a[i]], -1, i);
    change(las[a[i]] + 1, i, 1, i);
    las1[a[i]] = las[a[i]], las[a[i]] = i;
    f[i] = query(1, i);
  }
  printf("%d\n", f[n]);
  return 0;
}
