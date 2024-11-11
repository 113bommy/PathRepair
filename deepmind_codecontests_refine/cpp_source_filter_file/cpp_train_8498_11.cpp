#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const long double EPS = 1e-9;
bool ok[10005];
int dp[10005];
int a[10005], b[10005];
int ic[10005], uc[10005];
int main() {
  int n, h, mi = 0, mu = 0;
  int l, r;
  int ans = 0;
  scanf("%d%d%d", &n, &l, &r);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d", &a[i]);
    h += a[i];
  }
  l = h - l;
  r = h - r;
  swap(l, r);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &b[i]);
  for (int i = 0; i < (int)(n); i++)
    if (b[i])
      ic[mi++] = a[i];
    else
      uc[mu++] = a[i];
  sort(ic, ic + mi);
  reverse(ic, ic + mi);
  for (int i = 0; i <= h; i++) dp[i] = -INF;
  dp[0] = 0;
  for (int i = 0; i < (int)(mu); i++)
    for (int j = h; j >= uc[i]; j--) dp[j] = max(dp[j], dp[j - uc[i]]);
  for (int i = 0; i < (int)(mi); i++)
    for (int j = h; j >= ic[i]; j--)
      dp[j] = max(dp[j], dp[j - ic[i]] + (j >= l && j <= r));
  for (int i = 0; i <= h; i++) ans = max(ans, dp[i]);
  printf("%d\n", ans);
  return 0;
}
