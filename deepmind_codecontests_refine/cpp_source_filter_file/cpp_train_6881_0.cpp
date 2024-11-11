#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e6 + 5;
int n, k, top;
int a[N], l[N], r[N], s[N];
long long ans;
long long calc(int l, int r) {
  if (l > r || r - l + 1 < k) return 0;
  int m = (r - l + 2 - k) / (k - 1);
  long long ret = 1LL * (m + 1) * (r - l + 2 - k) % mod -
                  1LL * (1 + m) * m / 2 % mod * (k - 1) % mod;
  return ret;
}
int main() {
  int i;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (i = 1; i <= n; ++i) {
    while (top && a[s[top]] < a[i]) --top;
    l[i] = s[top] + 1, s[++top] = i;
  }
  top = 0, s[top] = n + 1;
  for (i = n; i; --i) {
    while (top && a[s[top]] < a[i]) --top;
    r[i] = s[top] - 1, s[++top] = i;
  }
  for (i = 1; i <= n; ++i)
    ans = (ans +
           (calc(l[i], r[i]) - calc(l[i], i - 1) - calc(i + 1, r[i])) * a[i]) %
          mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}
