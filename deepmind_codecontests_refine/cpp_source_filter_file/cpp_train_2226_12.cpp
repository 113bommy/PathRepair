#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  long long ans = 1;
  for (int i = 1; i <= k; i++) {
    ans *= i;
    ans %= 1000000007;
  }
  for (int i = k + 1; i <= n; i++) {
    ans *= (n - k);
    ans %= 1000000007;
  }
  printf("%I64d\n", ans);
  return 0;
}
