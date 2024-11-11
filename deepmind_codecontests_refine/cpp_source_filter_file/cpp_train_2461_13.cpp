#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 713;
int dp[maxn][maxn][10][2];
char s[maxn];
int a[maxn];
void add(int &a, int b) { a = 1ll * (a + b) % mod; }
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
  for (int i = 1; i <= 9; i++) dp[0][0][i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 1; k <= 9; k++) {
        for (int l = 0; l < 2; l++) {
          for (int p = 0; p <= (l ? 9 : a[i]); p++) {
            add(dp[i][j + (p >= k)][k][l | (p < a[i])], dp[i - 1][j][k][l]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    int st = 1;
    for (int j = 1; j <= n; j++) {
      ans = ans + 1ll * (dp[n][j][i][0] + dp[n][j][i][1]) * st % mod;
      st = (1ll * st * 10 % mod + 1) % mod;
      ans %= mod;
    }
  }
  printf("%lld", ans);
}
