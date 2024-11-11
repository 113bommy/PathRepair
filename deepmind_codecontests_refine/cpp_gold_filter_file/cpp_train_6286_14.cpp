#include <bits/stdc++.h>
const int N = 550, M = 20000;
int pref[M][N], suff[M][N], i, n, j, m, q, a[M], b[M], p[N], rank[N], ans;
int ta, tb, l, r;
int get(int (&p)[N], int v) { return p[v] = ((p[v] == v) ? v : get(p, p[v])); }
int main() {
  srand(time(0));
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) scanf("%d%d", &a[i], &b[i]);
  for (i = 1; i <= n; i++) p[i] = i, pref[0][i] = p[i], rank[i] = 1;
  for (i = 1; i <= m; i++) {
    if (get(p, a[i]) != get(p, b[i])) {
      ta = get(p, a[i]);
      tb = get(p, b[i]);
      if (rank[ta] > rank[tb])
        p[tb] = ta;
      else {
        p[ta] = tb;
        if (rank[ta] == rank[tb]) rank[tb]++;
      }
    }
    for (j = 1; j <= n; j++) pref[i][j] = p[j];
  }
  for (i = 1; i <= n; i++) p[i] = i, suff[m + 1][i] = p[i], rank[i] = 1;
  for (i = m; i >= 1; i--) {
    if (get(p, a[i]) != get(p, b[i])) {
      ta = get(p, a[i]);
      tb = get(p, b[i]);
      if (rank[ta] > rank[tb])
        p[tb] = ta;
      else {
        p[ta] = tb;
        if (rank[ta] == rank[tb]) rank[tb]++;
      }
    }
    for (j = 1; j <= n; j++) suff[i][j] = p[j];
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &l, &r);
    for (i = 1; i <= n; i++) p[i] = i, rank[i] = 1;
    for (i = 1; i <= n; i++) {
      ta = get(p, i);
      tb = get(p, get(suff[r + 1], i));
      if (ta != tb) {
        if (rank[ta] > rank[tb])
          p[tb] = ta;
        else {
          p[ta] = tb;
          if (rank[ta] == rank[tb]) rank[tb]++;
        }
      }
    }
    for (i = 1; i <= n; i++) {
      ta = get(p, i);
      tb = get(p, get(pref[l - 1], i));
      if (ta != tb) {
        if (rank[ta] > rank[tb])
          p[tb] = ta;
        else {
          p[ta] = tb;
          if (rank[ta] == rank[tb]) rank[tb]++;
        }
      }
    }
    ans = 0;
    for (i = 1; i <= n; i++) ans += (int)(get(p, i) == i);
    printf("%d\n", ans);
  }
  return 0;
}
