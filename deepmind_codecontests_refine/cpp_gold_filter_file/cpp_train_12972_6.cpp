#include <bits/stdc++.h>
using namespace std;
const int maxn = 2500 + 5;
const int mo = 998244353;
int readint() {
  int x = 0, f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    (s = getchar());
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    (s = getchar());
  }
  return x * f;
}
struct zz {
  double x, y;
} s[maxn];
double dp[maxn][maxn][2];
double getdis(const zz &a, const zz &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
  int n = readint();
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &s[i].x, &s[i].y);
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 0; l < n; l++) {
      int r = (l + len - 1) % n;
      dp[l][r][0] = max(dp[(l + 1) % n][r][0] + getdis(s[(l + 1) % n], s[l]),
                        dp[(l + 1) % n][r][1] + getdis(s[l], s[r]));
      dp[l][r][1] =
          max(dp[l][(r - 1 + n) % n][1] + getdis(s[(r - 1 + n) % n], s[r]),
              dp[l][(r - 1 + n) % n][0] + getdis(s[l], s[r]));
    }
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, max(dp[i][(i + n - 1) % n][0], dp[i][(i + n - 1) % n][1]));
  }
  printf("%.10f", ans);
  return 0;
}
