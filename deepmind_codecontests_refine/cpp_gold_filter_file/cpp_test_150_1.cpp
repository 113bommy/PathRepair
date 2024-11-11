#include <bits/stdc++.h>
using namespace std;
constexpr size_t MAXN = 1e3 + 5;
long long a[MAXN], b[MAXN][4];
inline long long Cal(long long x, long long y, long long n) {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long tmp = 1e10;
    for (long long j = 0; j <= x; j++)
      for (long long k = 0; k <= y; k++)
        if ((a[i] - j - k * 2) >= 0 && (a[i] - j - k * 2) % 3 == 0)
          tmp = min(tmp, (a[i] - j - k * 2) / 3);
    if (tmp == 1e10) return tmp;
    ans = max(ans, tmp);
  }
  return ans + x + y;
}
inline void Solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long ans = 1e10;
  for (long long i = 0; i <= 3; i++)
    for (long long j = 0; j <= 3; j++) ans = min(ans, Cal(i, j, n));
  cout << ans << '\n';
}
signed main(void) {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) Solve();
}
