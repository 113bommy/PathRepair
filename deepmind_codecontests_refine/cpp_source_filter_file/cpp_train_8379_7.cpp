#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)(1e9 + 7);
const int MAX_N = 100010;
long long dp[MAX_N] = {0, 20};
void init() {
  int tmp = 1;
  for (int i = 2; i < MAX_N; i++) {
    tmp = tmp * 27 % mod;
    dp[i] = (tmp * 20 % mod + 7 * dp[i - 1]) % mod;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  init();
  while (~scanf("%d", &n)) {
    printf("%I64d\n", dp[n]);
  }
  return 0;
}
