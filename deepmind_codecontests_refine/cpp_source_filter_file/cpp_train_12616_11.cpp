#include <bits/stdc++.h>
using namespace std;
int n, k;
const int mod = 1000000007;
int PW1[255];
int PW2[255];
void pw(int k) {
  PW1[0] = PW2[0] = 1;
  for (int i = 1; i < 254; i++) {
    PW1[i] = ((k - 1) * 1ll * PW1[i - 1]) % mod;
    PW2[i] = ((k)*1ll * PW1[i - 1]) % mod;
  }
}
int pw(int a, int p) {
  if (p == 0) return 1;
  int r = pw(a, p / 2);
  r = (r * 1ll * r) % mod;
  if (p % 2) return (a * 1ll * r) % mod;
  return r;
}
int c[255][255];
int dp[255][255];
int C(int i, int j) {
  if (i < 0) return 0;
  if (i < j) return 0;
  if (i == j) return 1;
  if (j == 0) return 1;
  if (c[i][j] != -1) return c[i][j];
  return c[i][j] = (C(i - 1, j) + C(i - 1, j - 1)) % mod;
}
int sol(int i, int col) {
  if (i == n) {
    if (col == n) return 1;
    return 0;
  }
  if (dp[i][col] != -1) return dp[i][col];
  int ans = 0;
  int lSeg = (PW2[col] - PW1[col] + mod) % mod;
  int rSeg = PW1[n - col];
  ans = (((lSeg * 1ll * rSeg) % mod) * 1ll * sol(i + 1, col)) % mod;
  for (int j = 1; j <= n - col; j++) {
    ans += (((C(n - col, j) * 1ll * PW2[col]) % mod) * 1ll *
            ((PW1[n - col - j] * 1ll * sol(i + 1, col + j)) % mod)) %
           mod;
    ans %= mod;
  }
  return dp[i][col] = ans;
}
int main() {
  memset(c, -1, sizeof(c));
  memset(dp, -1, sizeof(dp));
  scanf("%d %d", &n, &k);
  pw(k);
  printf("%d\n", sol(0, 0));
}
