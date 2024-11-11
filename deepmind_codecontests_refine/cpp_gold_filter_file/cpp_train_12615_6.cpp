#include <bits/stdc++.h>
using namespace std;
const int maxn = int(2e5 + 7);
const int inf = int(0x7fffffff);
int a[12][2001], w[2001][1 << 12], dp[1 << 12];
struct P {
  int id, key;
  bool operator<(const P& a) const { return key > a.key; }
} p[2001];
int np[12][12];
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
        p[j].id = j;
        p[j].key = max(p[j].key, a[i][j]);
      }
    if (m > n) {
      sort(p, p + m);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) np[i][j] = a[i][p[j].id];
      m = n;
    } else {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) np[i][j] = a[i][j];
    }
    memset(w, 0, sizeof(w));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i) {
      for (int rot = 0; rot < n; ++rot) {
        for (int j = 0; j < (1 << n); ++j) {
          int tot = 0;
          for (int k = 0; k < n; ++k)
            if (j & (1 << k)) {
              tot += np[(k + rot) % n][i];
            }
          w[i][j] = max(w[i][j], tot);
        }
      }
    }
    for (int c = 0; c < m; ++c) {
      for (int i = (1 << n) - 1; i >= 0; --i) {
        int s = ((1 << n) - 1) - i;
        for (int j = s; j > 0; j = s & (j - 1))
          dp[i | j] = max(dp[i | j], dp[i] + w[c][j]);
      }
    }
    printf("%d\n", dp[(1 << n) - 1]);
  }
  return 0;
}
