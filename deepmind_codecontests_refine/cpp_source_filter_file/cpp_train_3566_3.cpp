#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N] = {0};
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      if (i % 2 == 1) {
        ans += a[i];
      }
    }
    long long sum1 = 0, sum2 = 0, maxnum = 0;
    for (int i = 2; i <= n; i += 2) {
      sum1 = max(0ll, sum1 + a[i] - a[i - 1]);
      maxnum = max(maxnum, sum1);
    }
    for (int i = 3; i <= n; i += 2) {
      sum2 = max(0ll, sum2 + a[i] - a[i - 1]);
      maxnum = max(maxnum, sum2);
    }
    ans += maxnum;
    printf("%lld\n", ans);
  }
  return 0;
}
