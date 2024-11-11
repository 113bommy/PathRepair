#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int mod = 1000000007;
int n;
int a[N];
int s[N];
long long dp[N];
int C[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  C[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  dp[1] = 1;
  for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] * C[s[i] - 1][a[i] - 1] % mod;
  printf("%d\n", dp[n]);
  return 0;
}
