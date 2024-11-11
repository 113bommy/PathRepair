#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
long long sum[maxn], d[maxn];
pair<long long, int> a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i].first), a[i].second = i;
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i].first;
  long long k;
  cin >> k;
  long long cnt = 0;
  for (int i = 1; i <= k; i++) {
    cnt += (2 * i - 1 - k) * a[i].first;
  }
  long long ans = cnt, idx = 1;
  for (int i = 1; i <= n - k; i++) {
    d[i] = 1ll * (k - 1) * (a[k + i].first + a[i].first) -
           2 * (sum[k + i - 1] - sum[i]);
    cnt += d[i];
    if (cnt < ans) {
      ans = cnt;
      idx = i + 1;
    }
  }
  for (int i = 0; i < k; i++) printf("%d ", a[idx + i].second);
  return 0;
}
