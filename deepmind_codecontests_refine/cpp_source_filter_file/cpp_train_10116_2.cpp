#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
const int INF = 0x3f3f3f3f;
int n, dp[61][maxn];
long long a1[maxn], a2[maxn], a[maxn];
int s0[maxn], s1[maxn];
inline void init(int k) {
  if (k >= 0) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] & (1LL << k))
        a2[++cnt2] = a[i];
      else
        a1[++cnt1] = a[i];
    }
    for (int i = 1; i <= cnt1; i++) a[i] = a1[i];
    for (int i = 1; i <= cnt2; i++) a[i + cnt1] = a2[i];
  }
  s0[0] = s1[0] = 0;
  for (int i = 1; i <= n; i++) {
    s0[i] = s0[i - 1];
    s1[i] = s1[i - 1];
    if (a[i] & (1LL << (k + 1)))
      s1[i]++;
    else
      s0[i]++;
  }
}
inline void upmin(int &x, int y) { x = min(x, y); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) a[i] = a[n] - a[i];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i <= 58; i++) {
    init(i - 1);
    for (int j = 0; j <= n; j++) {
      int w = s1[n - j] + s0[n] - s0[n - j];
      int nxt = s1[n] - s1[n - j];
      upmin(dp[i + 1][nxt], dp[i][j] + w);
      w = s0[n - j] + s1[n] - s1[n - j];
      nxt = s1[n - j] + j;
      upmin(dp[i + 1][nxt], dp[i][j] + w);
    }
  }
  int Ans = INF;
  for (int i = 0; i <= n; i++) {
    upmin(Ans, dp[59][i] + i);
  }
  printf("%d\n", Ans);
  return 0;
}
