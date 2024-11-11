#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long long n, k;
int main() {
  scanf("%lld%lld", &n, &k);
  if (k >= n / 2) {
    printf("%lld", (n - 1) * n / 2);
  } else {
    int ans = 0;
    for (int i = 1; i <= k; i++) {
      ans += 2 * n - 3;
      n -= 2;
    }
    printf("%lld", ans);
  }
}
