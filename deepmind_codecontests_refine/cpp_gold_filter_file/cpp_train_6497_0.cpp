#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  scanf("%d%d", &k, &n);
  vector<int> a(k);
  for (int i = 0; i < k; i++) scanf("%d", &a[i]);
  long long l = -1;
  long long r = 1LL << 33;
  vector<int> dp(k, 0);
  while (l < r - 1) {
    long long m = (l + r) >> 1;
    for (int i = 0; i < k; i++) {
      dp[i] = i;
      for (int j = 0; j < i; j++) {
        if (abs(a[i] - a[j]) <= m * (i - j))
          dp[i] = min(dp[i], dp[j] + i - j - 1);
      }
    }
    int tmp = k + 1;
    for (int i = 0; i < k; i++) tmp = min(tmp, dp[i] + k - i - 1);
    if (tmp <= n)
      r = m;
    else
      l = m;
  }
  printf("%I64d\n", r);
  return 0;
}
