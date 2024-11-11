#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1010;
int n;
int kamo[MAXN];
long long dp[MAXN];
long long rjesenje = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &kamo[i]);
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = 2;
    for (int j = kamo[i]; j < i; j++) {
      dp[i] = (dp[i] + dp[j] + mod) % mod;
    }
    rjesenje = (rjesenje + dp[i] + mod) % mod;
  }
  printf("%I64d\n", rjesenje);
  return 0;
}
