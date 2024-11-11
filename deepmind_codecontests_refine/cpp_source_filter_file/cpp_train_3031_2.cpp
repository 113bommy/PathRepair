#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const long long int INFLL = 0x3f3f3f3f3f3f3f3fll;
long long int getint() {
  long long int ret = 0;
  bool f = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f ^= 1;
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return f ? -ret : ret;
}
using namespace std;
const int MAXD = 50;
int a[3], b[3], c[3];
int dp[MAXD][4][MAXD][4][MAXD][4];
int dfs(int p0, int s0, int p1, int s1, int p2, int s2) {
  int &val = dp[p0][s0][p1][s1][p2][s2];
  if (~val) return val;
  if (!s0 && !s1 && !s2) return val = max(p0, max(p1, p2));
  int p[3], s[3];
  p[0] = p0;
  p[1] = p1;
  p[2] = p2;
  s[0] = s0;
  s[1] = s1;
  s[2] = s2;
  for (int i = 0; i < 3; ++i)
    if (s[i] & 1) {
      s[i] ^= 1;
      for (int j = -b[i]; j <= b[i]; ++j) {
        p[i] += j;
        if (p[i] <= 0 || p[i] == p[(i + 1) % 3] || p[i] == p[(i + 2) % 3]) {
          p[i] -= j;
          continue;
        }
        val = max(val, dfs(p[0], s[0], p[1], s[1], p[2], s[2]));
        p[i] -= j;
      }
      s[i] ^= 1;
    }
  for (int i = 0; i < 3; ++i)
    if (s[i] & 2) {
      s[i] ^= 2;
      val = max(val, dfs(p[0], s[0], p[1], s[1], p[2], s[2]));
      for (int j = 0; j < 2; ++j) {
        int t = (i + j) % 3;
        if (abs(p[i] - p[t]) > 1) continue;
        int q = 3 - i - j;
        for (int k = -c[i]; k <= c[i]; ++k)
          if (k && p[i] + k != p[q] && p[i] + k > 0) {
            int c = p[t];
            p[t] = p[i] + k;
            val = max(val, dfs(p[0], s[0], p[1], s[1], p[2], s[2]));
            p[t] = c;
          }
        if (s[t] & 2 && abs(p[q] - p[t]) == 1) {
          int cc = p[t], d = p[q];
          p[t] = p[i] + c[i];
          p[q] = p[i] + c[i] + c[t];
          s[t] ^= 2;
          val = max(val, dfs(p[0], s[0], p[1], s[1], p[2], s[2]));
          s[t] ^= 2;
          p[t] = cc;
          p[q] = d;
        }
      }
      s[i] ^= 2;
    }
  return val;
}
int main() {
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < 3; ++i) a[i] = getint(), b[i] = getint(), c[i] = getint();
  printf("%d\n", dfs(a[0], 3, a[1], 3, a[2], 3));
  return 0;
}
