#include <bits/stdc++.h>
using namespace std;
long long i, k, n, m, l, a[100005], b[100005], qqq = 1, j, cnt = 1, aaa;
int main() {
  scanf("%lld%lld", &n, &k);
  for (i = 0; i < k; i++) qqq *= 10;
  for (i = 0; i < n / k; i++) scanf("%lld", &a[i]);
  for (i = 0; i < n / k; i++) scanf("%lld", &b[i]);
  for (i = 0; i < n / k; i++) {
    j = (qqq - 1) / a[i] + 1;
    j -= (qqq / 10 * (b[i] + 1) - 1) / a[i];
    j += (qqq / 10 * b[i] - 1) / a[i];
    if (b[i] == 0) {
      j = (qqq - 1) / a[i] - (qqq / 10 - 1) / a[i];
    }
    cnt = (cnt * j) % 1000000007;
  }
  printf("%lld", cnt);
  return 0;
}
