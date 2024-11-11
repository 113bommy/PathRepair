#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
const long long INF = (long long)1e18;
struct Line {
  long long a, b;
  Line() {}
  Line(long long a, long long b) : a(a), b(b) {}
} st[4 * N];
int n;
long long a[N], b[N], dp[N];
long long get(Line line, int i) { return line.a * a[i] + line.b; }
long long query(int k, int l, int r, int i) {
  if (i < l || i > r) return INF;
  long long res = get(st[k], i);
  if (l == r) return res;
  int m = (l + r) >> 1;
  return min({res, query(k << 1, l, m, i), query(k << 1 | 1, m + 1, r, i)});
}
void update(int k, int l, int r, int i, int j, Line v) {
  if (j < l || i > r) return;
  int m = (l + r) >> 1;
  if (i <= l && j >= r) {
    if (get(st[k], l) <= get(v, l) && get(st[k], r) <= get(v, r)) return;
    if (get(st[k], l) >= get(v, l) && get(st[k], r) >= get(v, r)) {
      st[k] = v;
      return;
    }
  }
  update(k << 1, l, m, i, j, v);
  update(k << 1 | 1, m + 1, r, i, j, v);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%I64d", &b[i]);
  for (int i = 1; i <= 4 * n; i++) st[i] = Line((int)1e9 + 7, (int)1e9 + 7);
  dp[1] = 0;
  update(1, 1, n, 1, n, Line(b[1], dp[1]));
  for (int i = 2; i <= n; i++) {
    dp[i] = query(1, 1, n, i);
    update(1, 1, n, 1, n, Line(b[i], dp[i]));
  }
  printf("%I64d\n", dp[n]);
  return 0;
}
