#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N], pre[N], suf[N], cnt[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  for (int i = 1; i <= n; i++) pre[i] = i * a[i] - pre[i];
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
  for (int i = n; i >= 1; i--) suf[i] = suf[i] - a[i] * (n - i + 1);
  for (int i = 1; i <= n; i++) cnt[i] = (a[i] == a[i - 1] ? cnt[i - 1] + 1 : 1);
  long long ans = 0x3f3f3f3f3f3f3f3fll;
  for (int i = 1; i <= n; i++)
    if (cnt[i] >= k) {
      printf("0\n");
      return 0;
    }
  for (int i = 1; i <= n; i++) {
    if (i < k)
      ans = min(ans, pre[i] + suf[i] - (n - k));
    else
      ans = min(ans, pre[i] - (i - k));
    if (i > n - k + 1)
      ans = min(ans, suf[i] + pre[i] - (n - k));
    else
      ans = min(ans, suf[i] - (n - i + 1 - k));
  }
  printf("%lld\n", ans);
  return 0;
}
