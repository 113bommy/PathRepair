#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  long long ans = 0;
  for (register int i = 2; i <= n; ++i) {
    int u = n / i;
    ans += 1ll * (2 + u) * (u - 2 + 1) >> 1;
  }
  printf("%I64d\n", ans << 2);
  return 0;
}
