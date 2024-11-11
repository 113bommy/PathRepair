#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
inline long long FIX(long long a) { return (a % Mod + Mod) % Mod; }
long long dp[100 + 5];
int main() {
  int n;
  long long k;
  cin >> n >> k;
  dp[n + 1] = 1;
  for (int i = n; i >= 1; i--) {
    dp[i] = dp[i + 1] + dp[i + 2];
  }
  long long tmp = k;
  int cur = 1;
  while (cur <= n) {
    if (dp[cur + 1] >= tmp) {
      printf("%d ", cur);
      cur++;
    } else {
      printf("%d %d ", cur + 1, cur);
      tmp -= dp[cur + 1];
      cur += 2;
    }
  }
  return 0;
}
