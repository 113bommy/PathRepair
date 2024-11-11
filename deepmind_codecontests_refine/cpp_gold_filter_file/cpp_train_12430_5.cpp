#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long n, t, ans = 0;
  scanf("%I64d", &n);
  for (t = 1; t <= n * 3 && t > 0; t *= 3) {
    if (n % t != 0) ans = max(ans, n / t + 1);
  }
  printf("%I64d\n", ans);
  return 0;
}
