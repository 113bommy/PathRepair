#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int n, a[500001];
long long x, y, ans = 1LL << 60, ps[500001];
bool isp[MAX + 5];
int main() {
  fill_n(isp, MAX + 5, true);
  isp[0] = isp[1] = false;
  for (int i = 2; i * i <= MAX; ++i)
    if (isp[i])
      for (int j = 2; i * j <= MAX; ++j) isp[i * j] = false;
  cin >> n >> x >> y;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  ps[0] = a[0];
  for (int i = 1; i < n; ++i) ps[i] = ps[i - 1] + a[i];
  for (int g = 2; g <= MAX; ++g) {
    if (!isp[g]) continue;
    long long curr = 0;
    for (int k = g; k - g <= MAX; k += g) {
      int r = upper_bound(a, a + n, k) - a - 1,
          l = upper_bound(a, a + n, k - g) - a;
      int f = lower_bound(a + l, a + r + 1, k - (long double)x / y) - a;
      curr +=
          x * (f - l) + y * ((long long)k * (r - f + 1) - (ps[r] - ps[f - 1]));
    }
    ans = min(ans, curr);
  }
  cout << ans << '\n';
}
