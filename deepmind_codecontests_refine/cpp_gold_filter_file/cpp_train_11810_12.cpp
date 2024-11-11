#include <bits/stdc++.h>
using namespace std;
template <typename T>
T next_int() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return p * x;
}
string next_token() {
  char ch;
  string ans = "";
  do {
    ch = getchar();
  } while (ch <= ' ');
  while (ch > ' ') {
    ans += ch;
    ch = getchar();
  }
  return ans;
}
const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int MAXN = (int)1e6 + 227 + 1;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-9;
long long bin_pow(long long a, long long b) {
  if (!b) return 1;
  long long ans = bin_pow(a, b / 2);
  ans = ans * ans % MOD;
  if (b % 2) ans = ans * a % MOD;
  return ans;
}
long long dp[2001][8001][2];
int f(int a) { return a & (-a); }
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    a[i] = next_int<int>();
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= 8000; j++)
      for (int k = 0; k < 2; k++) {
        if (a[i] == 0) {
          a[i] = 2;
          dp[i + 1][a[i] + j][max(k, (int)((a[i] + j) >= (1 << m)))] +=
              dp[i][j][k];
          dp[i + 1][a[i] + j][max(k, (int)((a[i] + j) >= (1 << m)))] %= MOD;
          a[i] = 4;
          if (f(j) < a[i]) {
            dp[i + 1][a[i]][max(k, (int)(a[i] >= (1 << m)))] += dp[i][j][k];
            dp[i + 1][a[i]][max(k, (int)(a[i] >= (1 << m)))] %= MOD;
          } else {
            dp[i + 1][a[i] + j][max(k, (int)((a[i] + j) >= (1 << m)))] +=
                dp[i][j][k];
            dp[i + 1][a[i] + j][max(k, (int)((a[i] + j) >= (1 << m)))] %= MOD;
          }
          a[i] = 0;
        } else {
          if (a[i] == 4 && f(j) < a[i]) {
            dp[i + 1][a[i]][max(k, (int)(a[i] >= (1 << m)))] += dp[i][j][k];
            dp[i + 1][a[i]][max(k, (int)(a[i] >= (1 << m)))] %= MOD;
          } else {
            dp[i + 1][a[i] + j][max(k, (int)((a[i] + j) >= (1 << m)))] +=
                dp[i][j][k];
            dp[i + 1][a[i] + j][max(k, (int)((a[i] + j) >= (1 << m)))] %= MOD;
          }
        }
      }
  long long ans = 0;
  for (int j = 0; j <= 8000; j++) ans = (ans + dp[n][j][1]) % MOD;
  cout << ans << "\n";
}
