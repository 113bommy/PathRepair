#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a, b, c, d;
  long long int ans;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ans += (d - b + 1) * (c - a + 1);
  }
  printf("%lld\n", ans);
  return 0;
}
