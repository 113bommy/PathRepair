#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using LL = long long;
LL a[N];
LL sum[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    LL k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    LL ans = -1;
    for (LL i = 0; i <= n - 1; i++) {
      LL x = ceil((double)(i * a[1] + sum[n - i] - k) / (double)(i + 1));
      if (x < 0) x = 0;
      if (ans == -1)
        ans = x + i;
      else
        ans = min(ans, x + i);
    }
    printf("%lld\n", ans);
  }
}
