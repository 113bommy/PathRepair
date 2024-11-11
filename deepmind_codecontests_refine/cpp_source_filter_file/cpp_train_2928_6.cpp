#include <bits/stdc++.h>
using namespace std;
struct myQueue {
  stack<pair<long long, long long> > s, s2;
  long long getMin() {
    if (s.empty() && s2.empty()) return 0;
    if (s.empty() || s2.empty())
      return s.empty() ? s2.top().second : s.top().second;
    else
      return min(s.top().second, s2.top().second);
  }
  void push(long long val) {
    if (s.empty())
      s.push({val, val});
    else
      s.push({val, min(s.top().second, val)});
  }
  void pop() {
    if (s2.empty())
      while (!s.empty()) {
        long long val = s.top().first;
        s.pop();
        if (s2.empty())
          s2.push({val, val});
        else
          s2.push({val, min(s2.top().second, val)});
      }
    if (!s2.empty()) s2.pop();
  }
};
const long long N = 1e3 + 5;
long long dp[N][N], mas[N];
int main() {
  long long n, k, x;
  cin >> n >> k >> x;
  n++;
  for (long long i = 1; i < n; ++i) cin >> mas[i];
  for (long long i = 0; i < N; ++i)
    for (long long j = 0; j < N; ++j) dp[i][j] = -(long long)(1e9 + 7);
  dp[0][x] = 0;
  for (long long ost = x - 1; ost >= 0; --ost)
    for (long long i = 1; i < n; ++i)
      for (long long j = max(0LL, i - k); j < i; ++j)
        if (dp[j][ost + 1] != -(long long)(1e9 + 7)) {
          dp[i][ost] = max(dp[i][ost], dp[j][ost + 1] + mas[i]);
        }
  long long ans = -(long long)(1e9 + 7);
  for (long long i = n - k + 1; i < n; ++i) ans = max(ans, dp[i][0]);
  if (ans == -(long long)(1e9 + 7))
    cout << -1;
  else
    cout << ans;
  return 0;
}
