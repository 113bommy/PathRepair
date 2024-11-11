#include <bits/stdc++.h>
using namespace std;
const int maxn = 200009;
long long a[maxn], c[maxn], n, K;
long long flag, sum, t, ans;
int main() {
  scanf("%I64d%I64d", &n, &K);
  for (long long i = 0; i <= n; i++) {
    scanf("%I64d", &a[i]);
    c[i] = a[i];
  }
  for (long long i = 0; i <= n - 1; i++) {
    a[i + 1] += a[i] / 2LL;
    a[i] %= 2LL;
  }
  for (long long i = 0; i <= n; i++)
    if (a[i]) {
      flag = i;
      break;
    }
  for (long long i = n; i >= 0; i--) {
    sum = (sum << 1) + a[i];
    if (abs(sum) > 2 * K) break;
    if (i <= flag) {
      t = abs(c[i] - sum);
      if (t <= K && !(i == n && t == 0)) {
        ans++;
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
