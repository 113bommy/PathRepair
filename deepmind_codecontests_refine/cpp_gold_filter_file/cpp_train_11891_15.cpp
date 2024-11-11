#include <bits/stdc++.h>
using namespace std;
long long add(long long a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
long long mult(long long a, long long b) { return a * b % 1000000007; }
long long n, m, k;
long long dp[1003][1003];
void read() { cin >> n >> m >> k; }
void solve() {
  n -= k + 1;
  m -= k + 1;
  for (long long i = 1; i <= 1000; i++) dp[i][1] = i;
  for (long long i = 2; i <= k; i++) {
    long long sum = 0;
    for (long long j = 1; j <= 1000; j++) {
      sum = add(sum, dp[j - 1][i - 1]);
      dp[j][i] = add(dp[j - 1][i], sum);
    }
  }
  if (n < 0 || m < 0) {
    cout << 0 << '\n';
    return;
  }
  long long mult1 = 0, mult2 = 0;
  for (long long i = 1; i <= n; i++) mult1 = add(mult1, dp[i][k]);
  for (long long i = 1; i <= m; i++) mult2 = add(mult2, dp[i][k]);
  cout << mult(mult1, mult2) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}
