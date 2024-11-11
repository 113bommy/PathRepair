#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 110;
int n;
long long ans, dp[N][N][2];
pair<int, int> a[N];
int main() {
  n = read();
  for (register int i = (1); i <= (n); i++) a[i] = make_pair(read(), read());
  sort(a + 1, a + 1 + n,
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  a[0].second = -1e9;
  for (register int i = (0); i <= (n); i++)
    for (register int j = (0); j <= (i); j++)
      for (register int k = (0); k <= (1); k++) {
        ans = max(ans, dp[i][j][k]);
        int r1 = a[j].second + k * a[j].first, nxtr = -1e9, nxtj = 0, nxtk = 0;
        for (register int l = (i + 1); l <= (n); l++)
          for (register int t = (0); t <= (1); t++) {
            int r2 = a[l].second + t * a[l].first;
            if (r2 > nxtr) nxtr = r2, nxtj = l, nxtk = t;
            dp[l][nxtj][nxtk] =
                max(dp[l][nxtj][nxtk],
                    dp[i][j][k] + min(a[l].first, r2 - r1) + nxtr - r2);
          }
      }
  printf("%lld\n", ans);
}
