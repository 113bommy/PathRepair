#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<long long>> dp(n + 1, vector<long long>(2, inf));
  deque<long long> m = {0};
  deque<long long> m3 = {0};
  deque<long long> m1 = {inf};
  deque<long long> m2 = {inf};
  dp[0][0] = 0;
  for (long long i = 1; i <= n; i++) {
    if (s[i - 1] == '1') {
      dp[i][1] = min(m2.front(), m3.front()) + i;
    }
    dp[i][0] = min(m1.front(), dp[i - 1][0] + i);
    if (i >= k) {
      if (m.front() == dp[i - k][0]) {
        m.pop_front();
      }
      if (m1.front() == dp[i - k][1]) {
        m1.pop_front();
      }
    }
    if (i >= k + 1) {
      if (m2.front() == dp[i - k - 1][1]) {
        m2.pop_front();
      }
      if (m3.front() == dp[i - k - 1][0]) {
        m3.pop_front();
      }
    }
    while (!m.empty() && m.back() > dp[i][0]) {
      m.pop_back();
    }
    m.push_back(dp[i][0]);
    while (!m1.empty() && m1.back() > dp[i][1]) {
      m1.pop_back();
    }
    m1.push_back(dp[i][1]);
    while (!m2.empty() && m2.back() > dp[i][1]) {
      m2.pop_back();
    }
    m2.push_back(dp[i][1]);
    while (!m3.empty() && m3.back() > dp[i][0]) {
      m3.pop_back();
    }
    m3.push_back(dp[i][0]);
  }
  cout << min(dp[n][0], dp[n][1]);
  return 0;
}
