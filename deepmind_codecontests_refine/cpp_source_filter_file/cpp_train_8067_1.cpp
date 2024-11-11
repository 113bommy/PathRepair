#include <bits/stdc++.h>
const long double pi = acos(-1.0);
const long double eps = 1e-6;
using namespace std;
const int N = 100 * 100 + 10;
int n;
long long t;
long long a[N], dp[N];
long long cnt[N];
void solve() {
  cin >> n >> t;
  long long sz = min(n * 1ll, t);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    for (int j = 1; j <= sz; j++) a[i + j * n] = a[i];
  }
  long long kol = min(n * n * 1ll, n * t);
  dp[0] = 0;
  for (int i = 1; i <= kol; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  long long mx = 0;
  for (int i = 1; i < N; i++) mx = max(mx, cnt[i]);
  long long ans = 0;
  for (int i = 1; i <= kol; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans + mx * (t - min(t, n * 1ll)) << endl;
}
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(6);
  int step;
  step = 1;
  for (int i = 1; i <= step; i++) {
    solve();
  }
}
