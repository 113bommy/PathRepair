#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 10;
const int Mod = 1e9 + 7;
const long long int Inf = 1LL << 62;
int ar[Max];
int dp[Max];
int main() {
  int n, mn = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
  }
  for (int i = 1; i <= n; i++) {
    mn = min(mn, ar[i] - i);
    dp[i] = i + mn;
  }
  mn = n + 1;
  for (int i = n; i >= 1; i--) {
    mn = min(mn, ar[i] + i);
    dp[i] = min(dp[i], mn - i);
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i - 1], dp[i]);
  }
  printf("%d\n", dp[n]);
  return 0;
}
