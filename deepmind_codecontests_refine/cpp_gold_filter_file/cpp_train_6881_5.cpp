#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, mod = 1e9 + 7;
int n, k, a[N], L[N], R[N], l, r, pr[N], ma;
int64_t ans, cnt;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i)
    for (L[i] = i - 1; L[i] >= 1 && a[i] >= a[L[i]]; L[i] = L[L[i]])
      ;
  for (int i = n; i >= 1; --i)
    for (R[i] = i + 1; R[i] <= n && a[i] > a[R[i]]; R[i] = R[R[i]])
      ;
  for (int i = 1; i <= n + k; ++i) pr[i] = i / (k - 1);
  for (int i = 1; i <= n; ++i) {
    l = L[i] + 1;
    r = R[i] - 1;
    cnt = 0;
    if (i - l < r - i)
      for (; l <= i; ++l) cnt += pr[r - l] - pr[i - l + k - 2] + 1;
    else
      for (; r >= i; --r) cnt += pr[r - l] - pr[r - i + k - 2] + 1;
    ans = (ans + (cnt - 1) % mod * a[i]) % mod;
    ma = max(ma, a[i]);
  }
  cout << ans;
}
