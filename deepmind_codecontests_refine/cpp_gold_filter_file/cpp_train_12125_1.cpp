#include <bits/stdc++.h>
using namespace std;
int n, m, q, bl, Bf, Bs, k, i, fix[100005][15], x, y;
pair<int, int> dp[100005][15];
char c[100005][15], C, cc;
void dfs(int x, int y) {
  fix[x][y] = 1;
  dp[x][y] = {-1, -1};
  int X = x;
  int Y = y;
  if (c[x][y] == '^') X--;
  if (c[x][y] == '>') Y++;
  if (c[x][y] == '<') Y--;
  if ((X - 1) / bl != (x - 1) / bl || X < 1 || Y < 1 || X > n || Y > m) {
    dp[x][y] = {X, Y};
    return;
  }
  if (!fix[X][Y]) dfs(X, Y);
  dp[x][y] = dp[X][Y];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> q;
  bl = sqrt(n);
  for (k = 1; k <= n; k++) {
    for (i = 1; i <= m; i++) {
      cin >> c[k][i];
    }
  }
  for (k = 1; k <= n; k++) {
    for (i = 1; i <= m; i++) {
      if (!fix[k][i]) {
        dfs(k, i);
      }
    }
  }
  while (q--) {
    cin >> C;
    if (C == 'A') {
      cin >> x >> y;
      while (true) {
        if (dp[x][y].first == -1 || dp[x][y].first < 1 || dp[x][y].first > n ||
            dp[x][y].second > m || dp[x][y].second < 1)
          break;
        int X = x, Y = y;
        x = dp[X][Y].first;
        y = dp[X][Y].second;
      }
      cout << dp[x][y].first << " " << dp[x][y].second << endl;
    } else {
      cin >> x >> y >> cc;
      c[x][y] = cc;
      Bf = (x - 1) / bl * bl + 1;
      Bs = min((x - 1) / bl * bl + bl + 1, n);
      for (k = Bf; k <= Bs; k++) {
        for (i = 1; i <= m; i++) {
          fix[k][i] = 0;
        }
      }
      for (k = Bf; k <= Bs; k++) {
        for (i = 1; i <= m; i++) {
          if (!fix[k][i]) dfs(k, i);
        }
      }
    }
  }
}
