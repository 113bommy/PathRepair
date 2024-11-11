#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
struct edge {
  int y, c, w, next;
} a[N << 1];
int len, last[N];
void ins(int x, int y, int c, int w) {
  a[++len] = (edge){y, c, w, last[x]};
  last[x] = len;
  a[++len] = (edge){x, 0, -w, last[y]};
  last[y] = len;
}
int q[N << 2], d[N], f[N], S, T, prv[N], ans, sta[N], top;
bool v[N];
bool spfa() {
  memset(d, 0x3f, sizeof d);
  memset(f, 0, sizeof f);
  d[S] = 0;
  f[S] = 0x3f3f3f3f;
  int l = 1, r = 0;
  v[q[++r] = S] = 1;
  for (int x = q[l]; l <= r; x = q[++l]) {
    v[x] = 0;
    for (int k = last[x], y; k; k = a[k].next) {
      if (d[y = a[k].y] > d[x] + a[k].w && a[k].c) {
        d[y] = d[x] + a[k].w;
        f[y] = min(f[x], a[k].c);
        if (!v[y]) v[q[++r] = y] = 1;
        prv[y] = k;
      }
    }
  }
  return f[T] > 0;
}
void upd() {
  ans += f[T] * d[T];
  int k = prv[T];
  while (k) {
    a[k].c -= f[T];
    a[k ^ 1].c += f[T];
    k = prv[a[k ^ 1].y];
  }
}
int A[N], C[N], lst[N];
int main() {
  len = 1;
  memset(last, 0, sizeof last);
  memset(lst, 0, sizeof lst);
  int n, m;
  scanf("%d%d", &n, &m);
  ans = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &C[i]);
  S = 0;
  T = 2 * n + 1;
  for (int i = 1; i <= n; ++i) {
    ins(S, i, 1, C[A[i]]);
    ins(i + n, T, 1, 0);
    ins(i, i + n, 1, 0);
    if (i != n) ins(i, i + 1, m - 1, 0);
    if (!lst[A[i]])
      lst[A[i]] = i;
    else {
      ins(i - 1, lst[A[i]] + n, 1, -C[A[i]]);
      lst[A[i]] = i;
    }
  }
  while (spfa()) upd();
  printf("%d\n", ans);
  return 0;
}
