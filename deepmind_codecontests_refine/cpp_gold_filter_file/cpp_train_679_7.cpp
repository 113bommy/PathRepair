#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 300010;
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline int mult(int a, int b) { return (a * (long long)b) % mod; }
int dp[2][N];
int a, b, k, t;
int sum[N];
void solve(int st, int c) {
  memset(sum, 0, sizeof sum);
  for (int i = st; i < N; i++) {
    sum[i] = 1;
  }
  for (int j = 0; j < t; j++) {
    for (int i = 0; i < N; i++) {
      int s = i - k - 1;
      int t = i + k;
      if (t >= N) t = N - 1;
      if (s < 0)
        dp[c][i] = sum[t];
      else
        dp[c][i] = (sum[t] - sum[s] + mod) % mod;
    }
    sum[0] = dp[c][0];
    for (int i = 1; i < N; i++) {
      sum[i] = add(dp[c][i], sum[i - 1]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> k >> t;
  solve(N / 2 + a, 0);
  solve(N / 2 + b, 1);
  for (int i = N - 2; i >= 0; i--) {
    if (dp[0][i] == 0 && i <= a) break;
    dp[0][i] = add(dp[0][i], dp[0][i + 1]);
  }
  int res = 0;
  for (int i = 0; i + 1 < N; i++) {
    res = add(res, mult(dp[1][i], dp[0][i + 1]));
  }
  cout << res << "\n";
  return 0;
}
