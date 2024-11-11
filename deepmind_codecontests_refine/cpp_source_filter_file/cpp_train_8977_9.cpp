#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long t, n;
void solve() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    long long ans = 0;
    long long bits;
    long long temp = pow(2, 62);
    for (long long i = 62; i >= 0; i--) {
      if (n & temp) {
        bits = i + 1;
        break;
      }
      temp = temp >> 1;
    }
    for (long long i = 1; i <= bits; i++) {
      long long first_pos = pow(2, i - 1);
      if (n > first_pos) {
        ans += i;
      }
      long long steps_left = n - first_pos;
      long long repeat_after_steps = pow(2, i);
      ans += i * (steps_left / repeat_after_steps);
    }
    cout << ans << "\n";
  }
}
int32_t main() {
  solve();
  return 0;
}
