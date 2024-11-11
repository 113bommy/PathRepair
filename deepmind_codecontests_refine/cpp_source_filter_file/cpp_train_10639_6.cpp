#include <bits/stdc++.h>
using namespace std;
struct note {
  int l, r;
} a[100];
bool cmp(note a, note b) { return a.l == b.l ? a.r < b.r : a.l < b.l; }
const int N = 2e5 + 5;
int dp[N];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= m; i++) dp[i] = 0x3f3f3f3f;
  int ma = 0;
  for (int i = 1; i <= n; i++) {
    int x, s;
    scanf("%d %d", &x, &s);
    a[i].l = max(x - s, 1);
    a[i].r = min(x + s, m);
    ma = max(ma, a[i].r);
    for (int j = a[i].l; j <= a[i].r; j++) {
      dp[j] = 0;
    }
  }
  for (int i = m; i > 0; i--) dp[i] = m - i + 1;
  sort(a + 1, a + 1 + n, cmp);
  dp[m + 1] = 0;
  for (int i = m; i >= 1; i--) {
    if (dp[i] == 0)
      dp[i] = dp[i + 1];
    else {
      for (int j = 1; j <= n; j++) {
        if (a[j].l > i) {
          int dis = a[j].l - i;
          int R = min(a[j].r + dis, m);
          dp[i] = min(dp[i], dis + dp[R + 1]);
        }
      }
    }
  }
  printf("%d\n", dp[1]);
}
