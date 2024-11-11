#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1061109567;
const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int a[16][16], n, dp[1 << 16], d[16];
void floyd() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
}
int solve() {
  floyd();
  for (int i = 0; i < n; i++) {
    if (a[0][i] == inf && d[i]) return -1;
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int s = 0; s < (1 << n); s++) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (d[i] % 2 && (s >> i & 1)) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      dp[s] = 0;
    }
    for (int i = 0; i < n; i++) {
      if (d[i] % 2 && !(s >> i & 1)) {
        for (int j = i + 1; j < n; j++) {
          if (d[j] % 2 && !(s >> j & 1) && a[i][j] != inf) {
            int tmp = s | (1 << j) | (1 << i);
            dp[tmp] = min(dp[tmp], dp[s] + a[i][j]);
          }
        }
      }
    }
  }
  return dp[(1 << n) - 1] == inf ? -1 : dp[(1 << n) - 1];
}
int main() {
  int m, x, y, w, sum = 0;
  cin >> n >> m;
  memset(a, 0x3f, sizeof(a));
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &x, &y, &w);
    x--, y--;
    d[x]++, d[y]++;
    sum += w;
    a[x][y] = min(a[x][y], w);
    a[y][x] = a[x][y];
  }
  for (int i = 0; i < n; i++) a[i][i] = 0;
  int tmp = solve();
  if (tmp == -1) {
    puts("-1");
  } else {
    cout << tmp + sum << endl;
  }
  return 0;
}
