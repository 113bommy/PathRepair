#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], cnt[N];
long long ans[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), ++cnt[a[i]];
  for (int i = 1; i <= N - 1; ++i) cnt[i] += cnt[i - 1];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (a[i] == a[i - 1]) continue;
    for (int k = 1; k <= N / a[i]; ++k) {
      int r = (k + 1) * a[i] - 1, l = k * a[i];
      ans[i] += 1ll * k * (cnt[min(r, N - 1)] - cnt[l == 0 ? 0 : l - 1]);
    }
    ans[i] *= a[i];
  }
  long long res = 0;
  for (int i = 1; i <= n; ++i) res = max(res, ans[i]);
  printf("%lld\n", res);
  return 0;
}
