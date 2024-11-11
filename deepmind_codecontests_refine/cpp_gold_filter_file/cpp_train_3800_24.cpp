#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, i, j;
  scanf("%d%d", &n, &x);
  int ans = 0;
  j = sqrt(x);
  for (i = 1; i <= j; i++) {
    if (x % i == 0 && i <= n && (x / i) <= n) {
      ans++;
      if (i != (x / i)) ans++;
    }
  }
  printf("%d", ans);
  return 0;
}
