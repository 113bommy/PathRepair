#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const double Inf = 1e15;
int n, k, a[N], l, r, d;
double _ans, f[N][2], sum, inv;
double calc(int i, int j) {
  while (r < j)
    r++, sum += a[r], inv += 1.0 / (double)a[r], _ans += sum / (double)a[r];
  while (j < r)
    _ans -= sum / (double)a[r], sum -= a[r], inv -= 1.0 / (double)a[r], r--;
  while (l < i) _ans -= a[l] * inv, sum -= a[l], inv -= 1.0 / (double)a[l], l++;
  while (i < l) l--, sum += a[l], inv += 1.0 / (double)a[l], _ans += a[l] * inv;
  return _ans;
}
void solve(int l, int r, int dl, int dr) {
  if (l > r) return;
  int mid = l + r >> 1, p = dl;
  f[mid][d & 1] = Inf;
  for (register int i = (dl); i <= (min(mid, dr)); ++i) {
    double t = f[i - 1][(d - 1) & 1] + calc(i, mid);
    if (t < f[mid][d & 1]) f[mid][d & 1] = t, p = i;
  }
  solve(l, mid - 1, dl, p);
  solve(mid + 1, r, p, dr);
}
signed main() {
  long long tot = 0;
  scanf("%d %d", &n, &k);
  for (register int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  for (register int i = (1); i <= (n); ++i)
    tot += a[i], f[i][1] = f[i - 1][1] + tot / (double)a[i];
  l = r = 1;
  sum = a[1];
  inv = 1.0 / (double)a[1];
  _ans = 1.0;
  for (register int i = (2); i <= (k); ++i) d = i, solve(1, n, 1, n);
  printf("%.10lf\n", f[n][d & 1]);
  return 0;
}
