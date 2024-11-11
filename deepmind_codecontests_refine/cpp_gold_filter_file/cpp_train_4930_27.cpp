#include <bits/stdc++.h>
using namespace std;
const int N = 4001000;
const int M = 1000100;
int n;
struct g {
  int id, v;
} a[M];
int q;
long long sum[N][2], v0[N][2], v1[N][2], A[M], len[M], cnt[M], tmp1, tmp2;
int l[M], r[M], flag[M], L[M], R[M];
int i, top;
double ans[M];
int gf(int x, int typ) {
  int p = x, t;
  if (typ == 0)
    while (p != l[p]) p = l[p];
  else
    while (p != r[p]) p = r[p];
  if (p != x) {
    if (typ == 0)
      t = l[x], l[x] = p, x = t;
    else
      t = r[x], r[x] = p, x = t;
  }
  return p;
}
void clean(int l, int r, int x, int typ) {
  if (v0[x][typ] || v1[x][typ]) {
    sum[x][typ] +=
        v0[x][typ] * (r - l) + v1[x][typ] * (r - l) * (r - l - 1) / 2;
    if (r - l > 1) {
      v0[2 * x][typ] += v0[x][typ];
      v1[2 * x][typ] += v1[x][typ];
      int m = (l + r) >> 1;
      v0[2 * x + 1][typ] += v0[x][typ] + (m - l) * v1[x][typ];
      v1[2 * x + 1][typ] += v1[x][typ];
    }
    v0[x][typ] = v1[x][typ] = 0;
  }
}
void change(int x, int l, int r, int a, int b, int c) {
  clean(l, r, x, c);
  if ((a <= l) && (r <= b)) {
    v0[x][c] += tmp1 + (l + 1) * tmp2;
    v1[x][c] += tmp2;
    return;
  }
  int m = (l + r) >> 1;
  if (a < m) change(2 * x, l, m, a, b, c);
  if (m < b) change(2 * x + 1, m, r, a, b, c);
  clean(l, m, 2 * x, c);
  clean(m, r, 2 * x + 1, c);
  sum[x][c] = sum[2 * x][c] + sum[2 * x + 1][c];
}
long long query(int x, int l, int r, int a, int b, int c) {
  clean(l, r, x, c);
  if ((a <= l) && (r <= b)) return sum[x][c];
  int m = (l + r) >> 1;
  long long ans = 0;
  if (a < m) ans += query(2 * x, l, m, a, b, c);
  if (m < b) ans += query(2 * x + 1, m, r, a, b, c);
  return ans;
}
bool cmp(g a, g b) { return a.v > b.v; }
void solve(int x, int l, int r) {
  clean(l, r, x, 0);
  clean(l, r, x, 1);
  if (r - l == 1) {
    ans[r] = sum[x][0] * 1.0 / sum[x][1];
    return;
  }
  int m = (l + r) >> 1;
  solve(2 * x, l, m);
  solve(2 * x + 1, m, r);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i].v), a[i].id = i, A[i] = a[i].v;
  sort(a + 1, a + 1 + n, cmp);
  for (i = 1; i <= n; i++) l[i] = r[i] = i;
  for (i = 1; i <= n; i++) {
    flag[a[i].id] = 1;
    if (flag[a[i].id - 1]) {
      l[gf(a[i].id, 0)] = gf(a[i].id - 1, 0);
      r[gf(a[i].id - 1, 1)] = gf(a[i].id, 1);
    }
    if (flag[a[i].id + 1]) {
      r[gf(a[i].id, 1)] = gf(a[i].id + 1, 1);
      l[gf(a[i].id + 1, 0)] = gf(a[i].id, 0);
    }
    L[a[i].id] = gf(a[i].id, 0);
    R[a[i].id] = gf(a[i].id, 1);
  }
  for (i = 1; i <= n; i++) {
    cnt[i] = min(i - L[i], R[i] - i);
    len[i] = i - L[i] + R[i] - i + 1;
  }
  for (i = 1; i <= n; i++) {
    if (cnt[i]) {
      tmp1 = 0;
      tmp2 = A[i];
      change(1, 0, n, 0, cnt[i], 0);
      tmp1 = 0;
      tmp2 = 1;
      change(1, 0, n, 0, cnt[i], 1);
      tmp1 = (len[i] + 1) * A[i];
      tmp2 = -A[i];
      change(1, 0, n, len[i] - cnt[i], len[i], 0);
      tmp1 = len[i] + 1;
      tmp2 = -1;
      change(1, 0, n, len[i] - cnt[i], len[i], 1);
    }
    if (cnt[i] < len[i] - cnt[i]) {
      tmp1 = (cnt[i] + 1) * A[i];
      tmp2 = 0;
      change(1, 0, n, cnt[i], len[i] - cnt[i], 0);
      tmp1 = cnt[i] + 1;
      tmp2 = 0;
      change(1, 0, n, cnt[i], len[i] - cnt[i], 1);
    }
  }
  scanf("%d", &q);
  solve(1, 0, n);
  for (i = 1; i <= q; i++) {
    int o;
    scanf("%d", &o);
    printf("%.12lf\n", ans[o]);
  }
}
