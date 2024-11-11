#include <bits/stdc++.h>
using namespace std;
long long n, ans, m;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%I64", &n);
    ans = n * (n + 1) / 2;
    for (m = 1; 2 * m <= n; m *= 2)
      ;
    ans -= 2 * (2 * m - 1);
    printf("%I64\n", ans);
  }
}
