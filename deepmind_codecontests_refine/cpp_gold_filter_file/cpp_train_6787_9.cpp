#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
using namespace std;
int dp[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  dp[0] = dp[1] = 2;
  for (int i = 2; i <= max(n, m); i++) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  printf("%d\n", (dp[m] + dp[n] - 2) % mod);
  return 0;
}
