#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long long MAX = 1e18;
int n, m, N;
int d[maxn], h[maxn];
long long p[maxn], A[maxn], B[maxn];
struct Node {
  int l, r;
  long long mx[3];
  Node() {
    mx[0] = mx[1] = -MAX;
    mx[2] = 0;
  }
} T[maxn << 2];
void build(int i, int l, int r) {
  T[i].l = l;
  T[i].r = r;
  if (l == r) {
    T[i].mx[0] = A[l];
    T[i].mx[1] = B[l];
    T[i].mx[2] = -MAX;
    return;
  }
  int M = l + r >> 1;
  build(i << 1, l, M);
  build(i << 1 | 1, M + 1, r);
  T[i].mx[0] = max(T[i << 1].mx[0], T[i << 1 | 1].mx[0]);
  T[i].mx[1] = max(T[i << 1].mx[1], T[i << 1 | 1].mx[1]);
  T[i].mx[2] = max(T[i << 1].mx[2], T[i << 1 | 1].mx[2]);
  T[i].mx[2] = max(T[i].mx[2], max(T[i << 1].mx[0] + T[i << 1 | 1].mx[1],
                                   T[i << 1].mx[1] + T[i << 1 | 1].mx[0]));
}
Node query(int i, int l, int r) {
  if (l > r) return Node();
  if (l <= T[i].l && T[i].r <= r) return T[i];
  int M = T[i].l + T[i].r >> 1;
  Node tmp, tmpl, tmpr;
  tmp.mx[0] = tmp.mx[1] = -MAX;
  tmp.mx[2] = 0;
  if (r <= M) return query(i << 1, l, r);
  if (l > M) return query(i << 1 | 1, l, r);
  tmpl = query(i << 1, l, M);
  tmpr = query(i << 1 | 1, M + 1, r);
  tmp.mx[0] = max(tmpl.mx[0], tmpr.mx[0]);
  tmp.mx[1] = max(tmpl.mx[1], tmpr.mx[1]);
  tmp.mx[2] = max(tmpl.mx[2], tmpr.mx[2]);
  tmp.mx[2] =
      max(tmp.mx[2], max(tmpl.mx[0] + tmpr.mx[1], tmpl.mx[1] + tmpr.mx[0]));
  return tmp;
}
void Work() {
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l <= r)
      printf("%I64d\n", query(1, r + 1, l + n - 1).mx[2]);
    else
      printf("%I64d\n", query(1, r + 1, l - 1).mx[2]);
  }
}
void Init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]), d[i + n] = d[i];
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]), h[n + i] = h[i];
  N = n * 2;
  p[1] = 0;
  for (int i = 2; i <= N; i++) p[i] = p[i - 1] + d[i - 1];
  for (int i = 1; i <= N; i++)
    A[i] = 1LL * h[i] * 2 + p[i], B[i] = 1LL * h[i] * 2 - p[i];
  build(1, 1, N);
}
int main() {
  Init();
  Work();
  return 0;
}
