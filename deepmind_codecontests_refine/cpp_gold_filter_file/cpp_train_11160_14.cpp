#include <bits/stdc++.h>
int oo[1 + (500000 - 1) * 2], oj[1 + (500000 - 1) * 2];
int link(int o, int j) {
  static int _ = 1;
  oo[_] = o, oj[_] = j;
  return _++;
}
int ae[500000], pp[500000], dd[500000];
struct E {
  int u, v, w;
} ee[(500000 * 3)];
int qu[500000], m, s, t;
int compare(const void *a, const void *b) {
  struct E *e = (struct E *)a;
  struct E *f = (struct E *)b;
  return e->v - f->v;
}
int prev[500000 + 2], next[500000 + 2];
char used[500000 + 2];
int ff[500000];
void init(int n) {
  int i;
  long long f;
  s = n, t = n + 1;
  f = 1;
  for (i = 0; i < n; i++) {
    ff[i] = f;
    f = f * (i + 1) % 1000000007;
  }
}
void dfs(int p, int i, int d) {
  int o;
  pp[i] = p, dd[i] = d;
  for (o = ae[i]; o; o = oo[o]) {
    int j = oj[o];
    if (j != p) dfs(i, j, d + 1);
  }
}
int add(int i, int j, int n) {
  struct E *e;
  int hi, hj, h;
  hi = 0, hj = n - 1;
  qu[hi++] = i;
  qu[hj--] = j;
  while (i != j)
    if (dd[i] >= dd[j])
      qu[hi++] = i = pp[i];
    else
      qu[hj--] = j = pp[j];
  hj += 2;
  while (hj < n) qu[hi++] = qu[hj++];
  if (m + hi > n * 3) return 0;
  e = &ee[m++], e->u = s, e->v = qu[0], e->w = qu[1];
  for (h = 1; h < hi - 1; h++)
    e = &ee[m++], e->u = qu[h - 1], e->v = qu[h], e->w = qu[h + 1];
  e = &ee[m++], e->u = qu[hi - 2], e->v = qu[hi - 1], e->w = t;
  return 1;
}
int count(int i, int l, int r) {
  int o, k, h, j, st;
  prev[s] = next[s] = -1, used[s] = 0;
  prev[t] = next[t] = -1, used[t] = 0;
  for (o = ae[i]; o; o = oo[o]) {
    j = oj[o];
    prev[j] = next[j] = -1, used[j] = 0;
  }
  for (h = l; h < r; h++) {
    struct E *e = &ee[h];
    if (next[e->u] != -1 || prev[e->w] != -1) return 0;
    next[e->u] = e->w, prev[e->w] = e->u;
  }
  k = 1;
  for (j = s; j != -1; j = next[j]) used[j] = 1;
  st = used[t];
  for (o = ae[i]; o; o = oo[o]) {
    j = oj[o];
    if (prev[j] == -1) {
      k++;
      for (; j != -1; j = next[j]) used[j] = 1;
    }
  }
  if (!used[t]) k++;
  for (o = ae[i]; o; o = oo[o]) {
    j = oj[o];
    if (!used[j]) return 0;
  }
  if (st) return k == 1 ? 1 : 0;
  return ff[k - 2];
}
int main() {
  int n, h, i, j, l, r;
  long long ans;
  scanf("%d", &n), init(n);
  for (h = 0; h < n - 1; h++) {
    scanf("%d%d", &i, &j), i--, j--;
    ae[i] = link(ae[i], j);
    ae[j] = link(ae[j], i);
  }
  dfs(-1, 0, 0);
  for (i = 0; i < n; i++) {
    scanf("%d", &j), j--;
    if (j < 0) continue;
    if (j == i || !add(j, i, n)) {
      printf("0\n");
      return 0;
    }
  }
  qsort(ee, m, sizeof *ee, compare);
  ans = 1;
  for (i = 0, l = 0; i < n; i++, l = r) {
    r = l;
    while (r < m && ee[r].v == i) r++;
    ans = ans * count(i, l, r) % 1000000007;
    if (ans == 0) {
      printf("0\n");
      return 0;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
