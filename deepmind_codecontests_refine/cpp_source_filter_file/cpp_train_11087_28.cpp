#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long a[N];
long long dp[N];
int main() {
  long long n;
  scanf("%lld", &n);
  int max_key = 0;
  int fg = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    dp[i] = max(dp[i + 1], a[i + 1]);
  }
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > dp[i])
      printf("0 ");
    else if (a[i] == dp[i]) {
      printf("1");
    } else
      printf("%lld ", dp[i] - a[i] + 1);
  }
  printf("0\n");
  return 0;
}
