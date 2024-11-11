#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int INF = 0x3f3f3f3f;
int n, m, ans1[N], ans2[N], b[N], len, c1[N], c2[N];
struct node {
  int a, b, t, id, tp, d;
} p[2 * N];
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
inline bool cmp1(node x, node y) {
  if (x.a != y.a) return x.a < y.a;
  return x.tp > y.tp;
}
inline bool cmp2(node x, node y) {
  if (x.b != y.b) return x.b > y.b;
  return x.tp < y.tp;
}
inline void add(int w, int v, int s) {
  for (; w >= 1; w -= (w & -w))
    if (c1[w] > v) c1[w] = v, c2[w] = s;
}
inline void query(int w, int &tmp, int &s) {
  for (; w <= n + m; w += (w & -w))
    if (tmp > c1[w]) tmp = c1[w], s = c2[w];
}
inline void clear(int w) {
  for (; w >= 1; w -= (w & -w)) c1[w] = INF;
}
inline void solve(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  solve(l, mid);
  solve(mid + 1, r);
  sort(p + l, p + r + 1, cmp2);
  for (int i = (l), iend = (r); i <= iend; i++) {
    if (p[i].id > mid && p[i].tp == 0)
      add(p[i].t, p[i].t, p[i].d);
    else if (p[i].id <= mid && p[i].tp) {
      int tmp = INF, s = -1;
      query(p[i].t, tmp, s);
      if (ans1[p[i].tp] > tmp) ans1[p[i].tp] = tmp, ans2[p[i].tp] = s;
    }
  }
  for (int i = (l), iend = (r); i <= iend; i++)
    if (p[i].id > mid && p[i].tp == 0) clear(p[i].t);
  sort(p + l, p + r + 1, cmp1);
}
int main() {
  n = read(), m = read();
  for (int i = (1), iend = (n); i <= iend; i++)
    p[i].a = -read(), p[i].b = read(), p[i].t = read(), p[i].d = i;
  for (int i = (1), iend = (m); i <= iend; i++)
    p[i + n].a = -read(), p[i + n].b = read(), p[i + n].t = read(),
          p[i + n].tp = i;
  sort(p + 1, p + m + n + 1, cmp1);
  memset(ans1, INF, sizeof(ans1)), memset(ans2, -1, sizeof(ans2)),
      memset(c1, INF, sizeof(c1)), memset(c2, -1, sizeof(c2));
  for (int i = (1), iend = (n + m); i <= iend; i++) p[i].id = i;
  for (int i = (1), iend = (n + m); i <= iend; i++) b[i] = p[i].t;
  sort(b + 1, b + n + m + 1);
  len = unique(b + 1, b + n + m + 1) - b - 1;
  for (int i = (1), iend = (n + m); i <= iend; i++)
    p[i].t = lower_bound(b + 1, b + n + m + 1, p[i].t) - b;
  solve(1, n + m);
  for (int i = (1), iend = (m); i <= iend; i++) printf("%d ", ans2[i]);
  return 0;
}
