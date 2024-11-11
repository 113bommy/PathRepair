#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
long long a[N], b[N], pre[N];
long long ta[N], tb[N];
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i], ta[i] = a[i];
  for (int i = 1; i <= n; i++) cin >> b[i], tb[i] = b[i];
  long long ans = 0;
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  if (!k) {
    for (int i = 1; i <= n; i++) ans = max(ans, pre[n] - pre[i - 1] - b[i]);
    return cout << ans << '\n', 0;
  }
  if (k == 1) {
    for (int i = 1; i < n; i++) ans = max(ans, pre[n - 1] - b[i]);
    if (b[n] < a[n]) ans += a[n] - b[n];
    sort(ta + 2, ta + 1 + n - 2), sort(tb + 2, tb + 1 + n - 2);
    ans = max(ans, pre[n] - b[1] - ta[2]);
    ans = max(ans, pre[n] - b[1] - tb[2]);
    ans = max(ans, pre[n] - tb[2] - tb[3]);
    for (int i = 2; i <= n; i++) ans = max(ans, pre[n] - pre[i - 1] - b[i]);
    cout << ans << '\n';
  } else {
    for (int i = 1; i < n; i++) ans = max(ans, pre[n] - b[i]);
    ans = max(ans, a[n] - b[n]);
    return cout << ans << '\n', 0;
  }
  return 0;
}
