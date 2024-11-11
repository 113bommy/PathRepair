#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long raw[maxn], pre[maxn], suf[maxn], cnt;
long long ans = 1e17;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &raw[i]);
  sort(raw + 1, raw + n + 1);
  for (int i = 1; i <= n; i++) {
    if (raw[i] != raw[i - 1]) {
      if (cnt >= k) {
        printf("0");
        return 0;
      }
      cnt = 1;
    } else
      cnt++;
  }
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + raw[i];
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + raw[i];
  for (int i = 1; i <= n; i++) {
    if (i <= k)
      ans = min(ans,
                i * raw[i] - pre[i] + suf[i] - (n - i + 1) * raw[i] - (n - k));
    else
      ans = min(ans, i * raw[i] - pre[i] - (i - k));
    if (n - i + 1 <= k)
      ans = min(ans,
                suf[i] - (n - i + 1) * raw[i] + i * raw[i] - pre[i] - (n - k));
    else
      ans = min(ans, suf[i] - (n - i + 1) * raw[i] - (n - i + 1 - k));
  }
  cout << max(ans, 0ll);
  return 0;
}
