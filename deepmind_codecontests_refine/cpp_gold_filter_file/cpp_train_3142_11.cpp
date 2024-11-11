#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int mp[maxn][maxn];
long long dp[1 << maxn][maxn];
int lowbit(int x) {
  for (int i = 0;; i++) {
    if ((x >> i) & 1) return i;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    mp[x][y] = 1;
    mp[y][x] = 1;
  }
  for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
  long long ans = 0;
  for (int s = 1; s < (1 << n); s++)
    for (int i = 0; i < n; i++) {
      if (!dp[s][i]) continue;
      int p = lowbit(s);
      for (int j = p; j < n; j++) {
        if (!mp[i][j]) continue;
        if (s & (1 << j)) {
          if (j == p) ans += dp[s][i];
        } else {
          dp[s | 1 << j][j] += dp[s][i];
        }
      }
    }
  cout << (ans - m) / 2LL << endl;
  return 0;
}
