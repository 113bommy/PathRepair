#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 2015;
long long a[MAXN], c[MAXN], ans, n, m;
inline long long c2(long long p) { return p * (p - 1) / 2; }
inline long long solve(long long k) {
  a[n] = min(c[n], k * m - c2(k) * n);
  for (int i = n - 1; i; i--) a[i] = min(c[i], a[i + 1] - k);
  if (a[1] < 0) return 0;
  long long A1 = max(1LL, m - k * n + 1 - ((m * k - c2(k + 1) * n + k) - a[1]));
  long long space = (m - A1 + 1) - k * n;
  long long ret = a[1], now = a[1];
  for (int i = 2; i <= n; i++) {
    now += k;
    long long d = a[i] - now;
    if (space >= d)
      space -= d, now += d;
    else
      now += space, space = 0;
    ret += now;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= m / n; i++) ans = max(ans, solve(i));
  cout << ans << "\n";
  return 0;
}
