#include <bits/stdc++.h>
using namespace std;
const int INF = std::numeric_limits<int>::max() / 3;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int dp[6000][6000];
long long sum[1000000];
long long min(long long a, long long b) { return a < b ? a : b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<long long> a;
  for (int i = 0, t; i < n; ++i) {
    cin >> t;
    a.push_back(t);
  }
  sort(a.begin(), a.end());
  int sz = n / k;
  int A = (n % k);
  int B = k - A;
  sum[0] = 0;
  for (int i = 1; i < n; ++i) sum[i] = sum[i - 1] + a[i] - a[i - 1];
  for (int i = 0; i <= A; ++i)
    for (int j = 0; j <= B; ++j) dp[i][j] = 2e9 + 1;
  dp[0][0] = 0;
  for (int i = 0; i <= A; ++i) {
    for (int j = 0; j <= B; ++j) {
      int x = (i + j) * sz + i;
      if (i < A) {
        long long t = dp[i][j] + sum[x + sz] - sum[x];
        dp[i + 1][j] = min(dp[i + 1][j] * 1LL, t);
      }
      if (j < B) {
        long long t = dp[i][j] + sum[x + sz - 1] - sum[x];
        dp[i][j + 1] = min(dp[i][j + 1] * 1LL, t);
      }
    }
  }
  cout << dp[A][B] << endl;
  return 0;
}
