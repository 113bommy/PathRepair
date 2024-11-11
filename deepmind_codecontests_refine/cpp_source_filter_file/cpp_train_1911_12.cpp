#include <bits/stdc++.h>
struct segt {
  int l, r, min, minc;
  segt *lc, *rc;
} * T;
int f[250000][20], g[250000][20], a[250000], n;
segt *build(int l, int r) {
  segt *t = new segt;
  t->l = l, t->r = r;
  if (t->l + 1 < t->r) {
    int mid = t->l + t->r >> 1;
    t->lc = build(l, mid), t->rc = build(mid, r);
    t->min = t->lc->min, t->minc = t->lc->minc;
    if (t->rc->min < t->min) t->min = t->rc->min, t->minc = t->rc->minc;
  } else
    t->min = t->l - a[t->l], t->minc = t->l;
  return t;
}
void query(segt *t, int l, int r, int &min, int &minc) {
  if (l >= r) {
    min = ~0U >> 1;
    return;
  }
  if (t->l == l && t->r == r)
    min = t->min, minc = t->minc;
  else {
    int mid = t->l + t->r >> 1;
    if (r <= mid)
      query(t->lc, l, r, min, minc);
    else if (l >= mid)
      query(t->rc, l, r, min, minc);
    else {
      int _min, _minc;
      query(t->lc, l, mid, min, minc);
      query(t->rc, mid, r, _min, _minc);
      if (_min < min) min = _min, minc = _minc;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] >= n) a[i] = n - 1;
  }
  T = build(0, n);
  memset(f, -1, sizeof f);
  for (int i = 0; i < n; i++) {
    f[i][0] = i - a[i];
    if (f[i][0] < 0) {
      f[i][0] += n;
      int min, minc, _min, _minc;
      query(T, 0, i, min, minc);
      query(T, f[i][0], n, _min, _minc);
      if (_min - n < min) min = _min, minc = _minc;
      g[i][0] = minc;
    } else {
      int min;
      query(T, f[i][0], i, min, g[i][0]);
    }
  }
  for (int j = 1; j < 20; j++)
    for (int i = 0; i < n; i++)
      if (f[i][j - 1] > -1) {
        f[i][j] = f[g[i][j - 1]][j - 1];
        g[i][j] = g[g[i][j - 1]][j - 1];
        if (g[i][j - 1] > i && (f[i][j] <= i || f[i][j] > g[i][j - 1]) ||
            g[i][j - 1] < i && f[i][j] > g[i][j - 1] && f[i][j] <= i)
          f[i][j] = -1;
      }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = 19; j >= 0; j--)
      if (f[k][j] != -1 && (k > i && f[k][j] > i && f[k][j] < k ||
                            k < i && (f[k][j] < k || f[k][j] > i) || k == i)) {
        ans += 1 << j;
        if (f[k][j] == (i + 1) % n) {
          ans--;
          break;
        }
        k = g[k][j];
      }
    ans++;
  }
  printf("I64d\n", ans);
  return 0;
}
