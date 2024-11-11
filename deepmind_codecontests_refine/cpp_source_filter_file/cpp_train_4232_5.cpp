#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n, dp[N][N], mod = 1e9 + 7;
char a[N];
int calc(int i, int f) {
  if (f < 0) return 0;
  if (i == n) return 1;
  int &ret = dp[i][f];
  if (ret != -1) return ret % mod;
  if (a[i] == 'f')
    ret = 1LL * calc(i + 1, f + 1);
  else
    ret = (1LL * calc(i + 1, f) % mod + 1LL * calc(i, f - 1) % mod) % mod;
  return ret % mod;
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c", &a[i]);
  }
  cout << calc(1, 0);
  return 0;
}
