#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n, L, a[2 * N], b[4 * N], li[N], ri[N];
bool chk(long long x) {
  long long mx = -5 * n;
  for (register long long i = (1); i <= (2 * n); ++i) {
    li[i] = lower_bound(b + 1, b + 1 + 4 * n, a[i] - x) - b;
    ri[i] = upper_bound(b + 1, b + 1 + 4 * n, a[i] + x) - b - 1;
    mx = max(mx, li[i] - i);
    if (ri[i] - i < mx) return 0;
  }
  return 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> L;
  for (register long long i = (1); i <= (n); ++i) cin >> a[i], a[i] += L;
  for (register long long i = (1); i <= (n); ++i) cin >> b[i];
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  for (register long long i = (1); i <= (n); ++i) a[i + n] = a[i] + L;
  for (register long long i = (1); i <= (n); ++i)
    b[i + n] = b[i] + L, b[i + 2 * n] = b[i] + 2 * L,
          b[i + 3 * n] = b[i] + 3 * L;
  long long l = 0, r = L - 1, mid, p = 0;
  while (l <= r) {
    mid = l + r >> 1;
    if (chk(mid))
      p = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << p << '\n';
  return 0;
}
