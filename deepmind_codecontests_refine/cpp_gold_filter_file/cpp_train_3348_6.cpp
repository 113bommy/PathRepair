#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 3e5 + 7;
const long long MOD = 1e9 + 7;
int n, q, a[N], dp[N][20], nxt[N][20];
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 20; ++j) {
      dp[i][j] = n;
      nxt[i][j] = n;
    }
  }
  for (int i = 0; i < 20; ++i) {
    if ((a[n - 1] >> i) & 1) {
      dp[n - 1][i] = n - 1;
      nxt[n - 1][i] = n - 1;
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < 20; ++j) {
      if ((a[i] >> j) & 1) {
        for (int k = 0; k < 20; ++k) {
          dp[i][k] = min(dp[i][k], dp[nxt[i + 1][j]][k]);
        }
        dp[i][j] = i;
      }
    }
    for (int j = 0; j < 20; ++j) {
      nxt[i][j] = nxt[i + 1][j];
      if ((a[i] >> j) & 1) {
        nxt[i][j] = i;
      }
    }
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    int ok = 0;
    for (int i = 0; i < 20; ++i) {
      ok |= (dp[x][i] <= y && ((a[y] >> i) & 1));
    }
    puts(ok ? "Shi" : "Fou");
  }
  return 0;
}
