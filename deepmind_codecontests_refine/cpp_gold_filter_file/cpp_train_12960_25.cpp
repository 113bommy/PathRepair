#include <bits/stdc++.h>
using namespace std;
const int N = 105;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int n, dp[N][N][2], ans;
struct line {
  int x, p;
} l[N];
bool operator<(line a, line b) {
  if (a.x != b.x) return a.x < b.x;
  return a.p < b.p;
}
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) l[i].x = read(), l[i].p = read();
  sort(l + 1, l + n + 1), l[0].x = -1e9;
  for (register int i = 0; i <= n; i++) {
    for (register int j = 0; j <= i; j++) {
      for (register int s = 0; s <= 1; s++) {
        ans = max(ans, dp[i][j][s]);
        int r = l[j].x + s * l[j].p, x, y, mx = -1e9;
        for (register int k = i + 1; k <= n; k++) {
          for (register int t = 0; t <= 1; t++) {
            int tmp = l[k].x + t * l[k].p;
            if (tmp > mx) mx = tmp, x = k, y = t;
            dp[k][x][y] =
                max(dp[k][x][y], dp[i][j][s] + min(l[k].p, tmp - r) + mx - tmp);
          }
        }
      }
    }
  }
  printf("%d", ans);
}
