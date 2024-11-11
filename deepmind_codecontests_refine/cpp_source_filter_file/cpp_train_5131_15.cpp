#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void solve() {
  long long int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a > c * b) {
    cout << -1 << '\n';
    return;
  }
  if (c <= d) {
    cout << a << '\n';
    return;
  }
  long long int times = c / d;
  long long int num = times * (times + 1) / 2;
  long long int t = (2 * a + d * b) / (2 * d * b);
  if (t < times) {
    long long int ans1 = (t + 1) * a - ((t * (t + 1) / 2) * d * b);
    long long int ans2 = 0;
    long long int ans3 = 0;
    if (t > 0) {
      t--;
      ans2 = (t + 1) * a - ((t * (t + 1) / 2) * d * b);
      t++;
    }
    if (t < times) {
      t++;
      ans3 = (t + 1) * a - ((t * (t + 1) / 2) * d * b);
      t--;
    }
    cout << max({a, ans1, ans2, ans3}) << '\n';
  } else {
    long long int ans = (times + 1) * a - (num * d * b);
    cout << max(a, ans) << '\n';
  }
}
void init() {}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  long long int T;
  cin >> T;
  for (long long int TT = 1; TT <= T; TT++) {
    solve();
  }
  cerr << "Time : "
       << 1000 * ((long double)clock()) / (long double)CLOCKS_PER_SEC << "ms\n";
  return 0;
}
