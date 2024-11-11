#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double EPS = 1e-9, INF = 1e12;
const int mod = (int)1e9 + 7;
long long n, m, k;
long long dp[2][10001];
long long C[110][110];
long long pw(long long n, long long m) {
  long long res = 1;
  for (; m; m /= 2) {
    if (m & 1) res = res * n;
    n = n * n % mod;
  }
  return res;
}
int main() {
  for (int i = 0; i < (int)110; i++)
    for (int j = 0; j < (int)i + 1; j++)
      C[i][j] = j == 0 || j == i ? 1 : (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  cin >> n >> m >> k;
  dp[0][0] = 1;
  int cur = 0, next = 1;
  for (int i = 0; i < (int)n; i++) {
    memset(dp[next], 0, sizeof(dp[next]));
    long long cnt = (m - i - 1) / n + 1;
    vector<int> v;
    for (int l = 0; l < (int)n + 1; l++) v.push_back(pw(C[n][l], cnt));
    for (int j = 0; j < (int)n * i + 1; j++)
      for (int l = 0; l < (int)n + 1; l++) {
        if (j + l > k) break;
        dp[next][j + l] += dp[cur][j] * v[l] % mod;
        dp[next][j + l] %= mod;
      }
    swap(cur, next);
  }
  cout << dp[cur][k] << endl;
  return 0;
}
