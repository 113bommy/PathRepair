#include <bits/stdc++.h>
using namespace std;
int n, k, m[3005];
long long _a[1010000], *ta = _a, *a[3005], s[3005], ans, h[15][3005];
void solve(int l, int r, int dep) {
  if (l == r) {
    for (int i = 0; i <= min(m[l], k); i++)
      ans = max(ans, a[l][i] + h[dep][k - i]);
    return;
  }
  int mid = (l + r) >> 1;
  for (int j = 0; j <= k; j++) h[dep + 1][j] = h[dep][j];
  for (int i = mid + 1; i <= r; i++)
    for (int j = k; j >= m[i]; j--)
      h[dep + 1][j] = max(h[dep + 1][j], h[dep + 1][j - m[i]] + s[i]);
  solve(l, mid, dep + 1);
  for (int j = 0; j <= k; j++) h[dep + 1][j] = h[dep][j];
  for (int i = l; i <= mid; i++)
    for (int j = k; j >= m[i]; j--)
      h[dep + 1][j] = max(h[dep + 1][j], h[dep + 1][j - m[i]] + s[i]);
  solve(mid + 1, r, dep + 1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m[i]);
    a[i] = ta;
    ta += m[i] + 2;
    for (int j = 1; j <= m[i]; j++) {
      scanf("%d", &a[i][j]);
      a[i][j] += a[i][j - 1];
    }
    s[i] += a[i][m[i]];
  }
  solve(1, n, 0);
  printf("%lld", ans);
  return 0;
}
