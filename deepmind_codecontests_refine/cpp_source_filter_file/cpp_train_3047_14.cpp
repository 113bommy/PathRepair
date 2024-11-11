#include <bits/stdc++.h>
using namespace std;
void set_file_io(string in, string out) {
  freopen((in + ".txt").c_str(), "r", stdin);
  freopen((out + ".txt").c_str(), "w", stdout);
}
void solve_test() {
  int n;
  long long r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  long long num[n];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  long long direct[n], come_back[n], dp[n + 1];
  for (int i = 0; i < n; i++) {
    direct[i] = r1 * num[i] + r3 + d;
    come_back[i] = min(r1 * (num[i] + 2), r2 + r1) + 2 * d;
  }
  dp[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = LLONG_MAX;
    if (i == n - 2) {
      dp[i] = min(dp[i], come_back[i] + direct[i + 1]);
    }
    dp[i] = min(dp[i], direct[i] + dp[i + 1]);
    if (i < n - 1) {
      dp[i] = min(dp[i], come_back[i] + come_back[i + 1] + dp[i + 2]);
    }
  }
  long long t = 0;
  for (int i = 0; i < n; i++) {
    t += come_back[i];
    t += d;
  }
  cout << min(dp[0], t) - d;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  tests = 1;
  while (tests--) {
    solve_test();
  }
  return 0;
}
