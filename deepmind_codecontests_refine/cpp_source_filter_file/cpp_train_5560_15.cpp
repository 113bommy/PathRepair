#include <bits/stdc++.h>
using namespace std;
const int max_n = 1005;
const long long mod = 1000000007ll;
int n;
int a[max_n];
long long dp[max_n][max_n];
bool x[max_n], y[max_n];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] != -1) {
      x[i] = 1;
      y[a[i] - 1] = 1;
    }
  }
  long long F = 1;
  for (int i = 1; i <= n; i++) {
    F *= (long long)i;
    F %= mod;
    dp[i][0] = F;
    dp[i][1] = F * (long long)i;
  }
  for (int j = 2; j <= n; j++)
    for (int i = 0; i <= n; i++) {
      dp[i][j] = ((long long)i * dp[i][j - 1]) % mod;
      dp[i][j] += (long long)(j - 1) * dp[i + 1][j - 2];
      dp[i][j] %= mod;
    }
  int A = 0, B = 0;
  for (int i = 0; i < n; i++)
    if (!y[i]) {
      if (!x[i])
        B++;
      else
        A++;
    }
  cout << dp[A][B] << "\n";
  return 0;
}
