#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
long long v[N], w[N], t[N];
long long n, a, b, c, d, start, len;
long long st[4 * N];
void build(int p, int l, int r) {
  if (l == r) {
    st[p] = w[l];
    return;
  }
  int m = (l + r) / 2;
  build(2 * p, l, m);
  build(2 * p + 1, m + 1, r);
  st[p] = min(st[2 * p], st[2 * p + 1]);
}
long long query(int p, int l, int r, int i, int j) {
  if (r < i or l > j) return LINF;
  if (l >= i and r <= j) return st[p];
  int m = (l + r) / 2;
  return min(query(2 * p, l, m, i, j), query(2 * p + 1, m + 1, r, i, j));
}
int main() {
  scanf("%lld %lld %lld %lld %lld %lld %lld", &n, &a, &b, &c, &d, &start, &len);
  v[0] = w[0] = start;
  for (int i = 1; i <= n; i++) {
    long long u;
    scanf("%lld %lld", &t[i], &u);
    if (u) {
      v[i] = v[i - 1] + a;
      w[i] = w[i - 1] + c;
    } else {
      v[i] = v[i - 1] - b;
      w[i] = w[i - 1] - d;
    }
  }
  build(1, 1, n);
  int tm = 1;
  for (int i = 1; i <= n; i++) {
    while (t[tm] < t[i - 1] + len + 1 and tm <= n) tm++;
    long long mn = query(1, 1, n, i, tm) - w[i - 1];
    if (v[i - 1] + mn >= 0)
      return printf("%lld\n", i == 1 ? 0 : t[i - 1] + 1), 0;
    if (v[i] < 0) return printf("-1\n"), 0;
  }
  printf("%lld\n", t[n] + 1), 0;
  return 0;
}
