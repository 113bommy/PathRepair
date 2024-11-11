#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, q, num, b0[N], b[N], c[2][N], ans[N];
struct data {
  int p, s, b;
} a[N];
struct qry {
  int x, y, id;
} Q[N];
bool cmp(qry a, qry b) { return a.x < b.x; }
bool cmp1(data a, data b) { return a.p < b.p; }
bool cmp2(data a, data b) { return a.s < b.s; }
void mdf(int *c, int o, int x) {
  while (o <= num) c[o] += x, o += (o & -o);
}
int qry(int *c, int o) {
  int s = 0;
  while (o) s += c[o], o -= (o & -o);
  return s;
}
int calc(int x, int y) {
  int res = 0;
  res += qry(c[0], upper_bound(b + 1, b + num + 1, x + y) - b - 1);
  res += qry(c[1], upper_bound(b + 1, b + num + 1, x - y) - b - 1);
  return res - qry(c[0], num);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i].p);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i].s);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i].b);
  for (int i = (1); i <= (n); ++i)
    b0[i] = a[i].p + a[i].b, b0[i + n] = a[i].p - a[i].b;
  sort(b0 + 1, b0 + n * 2 + 1);
  b[++num] = b0[1];
  for (int i = (2); i <= (n << 1); ++i)
    if (b0[i] != b0[i - 1]) b[++num] = b0[i];
  for (int i = (1); i <= (q); ++i) scanf("%d", &Q[i].x);
  for (int i = (1); i <= (q); ++i) scanf("%d", &Q[i].y);
  for (int i = (1); i <= (q); ++i) Q[i].id = i;
  sort(Q + 1, Q + q + 1, cmp);
  sort(a + 1, a + n + 1, cmp1);
  int j = 1;
  for (int i = (1); i <= (q); ++i) {
    while (j <= n && a[j].p <= Q[i].x) {
      int x = lower_bound(b + 1, b + num + 1, a[j].p + a[j].b) - b;
      int y = lower_bound(b + 1, b + num + 1, a[j].p - a[j].b) - b;
      mdf(c[0], x, 1), mdf(c[1], y, 1), ++j;
    }
    ans[Q[i].id] += calc(Q[i].x, Q[i].y);
  }
  memset(c, 0, sizeof(0));
  sort(a + 1, a + n + 1, cmp2);
  j = 1;
  for (int i = (1); i <= (q); ++i) {
    while (j <= n && a[j].s < Q[i].x) {
      int x = lower_bound(b + 1, b + num + 1, a[j].p + a[j].b) - b;
      int y = lower_bound(b + 1, b + num + 1, a[j].p - a[j].b) - b;
      mdf(c[0], x, 1), mdf(c[1], y, 1), ++j;
    }
    ans[Q[i].id] -= calc(Q[i].x, Q[i].y);
  }
  for (int i = (1); i <= (q); ++i) printf("%d ", ans[i]);
  return 0;
}
