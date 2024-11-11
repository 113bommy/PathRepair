#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
const int INF = 0x4f4f4f4f;
struct node {
  int v;
  int w;
} a[MAXN];
int dp[MAXN][4];
int main() {
  int n;
  cin >> n;
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].v);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].w);
  }
  for (int i = 1; i <= n; i++) {
    dp[i][1] = a[i].w;
    for (int k = 2; k <= 3; k++) {
      for (int j = 1; j < i; j++) {
        if (a[j].v < a[i].v) {
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + a[i].w);
        }
      }
    }
  }
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, dp[i][3]);
  }
  if (ans == INF) {
    cout << -1 << endl;
  } else
    cout << ans << endl;
  return 0;
}
