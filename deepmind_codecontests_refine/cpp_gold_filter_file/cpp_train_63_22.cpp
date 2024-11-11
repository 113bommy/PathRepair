#include <bits/stdc++.h>
using namespace std;
int n, k, x, ans = INT_MAX;
int main() {
  scanf("%d%d", &n, &k);
  while (n--) {
    scanf("%d", &x);
    if (k % x == 0) ans = min(ans, k / x);
  }
  printf("%d\n", ans);
  return 0;
}
