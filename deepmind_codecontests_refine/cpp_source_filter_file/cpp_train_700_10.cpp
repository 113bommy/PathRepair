#include <bits/stdc++.h>
using namespace std;
long long n, a[101], b[101];
long double c[101], dp[101][101][101];
vector<pair<long long, long long> > v;
long double sol(long long in, long long rem, long long sim) {
  if (in == n) return 0;
  if (dp[in][rem][sim] != 1e15) return dp[in][rem][sim];
  long double ans = 1e15;
  if (in < n - 1 and v[in].first == v[in + 1].first) {
    ans = min(ans, sol(in + 1, rem, sim + 1) + c[in]);
  } else {
    ans = min(ans, sol(in + 1, rem + sim + 1, 0) + c[in]);
  }
  if (rem) {
    if (in < n - 1 and v[in].first == v[in + 1].first) {
      ans = min(ans, sol(in + 1, rem - 1, sim));
    } else {
      ans = min(ans, sol(in + 1, rem - 1 + sim, 0));
    }
  }
  return dp[in][rem][sim] = ans;
}
bool check(long double mid) {
  for (long long i = 0; i < n; i++) {
    c[i] = 1.0l * v[i].first - mid * v[i].second;
  }
  for (long long i = 0; i < n + 2; i++) {
    for (long long j = 0; j < n + 2; j++) {
      for (long long k = 0; k < n + 2; k++) {
        dp[i][j][k] = 1e15;
      }
    }
  }
  return sol(0, 0, 0) <= 0;
}
void solve() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    v.push_back({a[i], b[i]});
  }
  sort((v).begin(), (v).end());
  reverse((v).begin(), (v).end());
  long double lo = 0, hi = 1e12;
  for (long long i = 0; i < 100; i++) {
    double mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid;
  }
  long long ans = 1000 * hi;
  if (1000.0l * hi - ans > 0) {
    ans++;
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
