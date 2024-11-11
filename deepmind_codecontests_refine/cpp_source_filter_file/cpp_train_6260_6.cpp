#include <bits/stdc++.h>
using namespace std;
int static fast = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();
int main() {
  int n, val;
  cin >> n;
  vector<int> dp(n + 1, 0);
  unordered_map<int, int> xor_cnt_even;
  unordered_map<int, int> xor_cnt_odd;
  xor_cnt_even[0] += 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> val;
    dp[i + 1] = dp[i] ^ val;
    if ((i + 1) % 2 == 0) {
      ans += xor_cnt_even[dp[i + 1]];
      xor_cnt_even[dp[i + 1]] += 1;
    } else {
      ans += xor_cnt_odd[dp[i + 1]];
      xor_cnt_odd[dp[i + 1]] += 1;
    }
  }
  cout << ans << endl;
  return 0;
}
