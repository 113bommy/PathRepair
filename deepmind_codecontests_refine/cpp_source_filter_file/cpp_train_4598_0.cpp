#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
int a[N], up[N], dw[N], mn[N], mx[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) mn[i] = n + 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mn[a[i]] = min(mn[a[i]], i);
    mx[a[i]] = max(mx[a[i]], i);
  }
  dw[0] = 0;
  for (int i = 1; i <= m; i++) {
    if (dw[i - 1] < mn[i]) {
      dw[i] = max(dw[i - 1], mx[i]);
    } else
      dw[i] = n + 2;
  }
  up[m + 1] = n + 1;
  for (int i = m; i >= 1; i--) {
    if (up[i + 1] > mx[i]) {
      up[i] = min(mn[i], up[i + 1]);
    } else
      up[i] = -1;
  }
  int j = 2;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    while (j <= m && (i + 1 >= j || dw[i] > up[j])) ++j;
    if (dw[i] < up[j]) ans += m - j + 2;
  }
  cout << ans;
  return 0;
}
