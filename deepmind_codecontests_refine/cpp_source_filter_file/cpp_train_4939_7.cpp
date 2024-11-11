#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;
const int MOD = 1e9 + 7;
const int MAXN = 110;
const double PI = acos(-1.0);
int ipt[MAXN][MAXN];
int main() {
  int n, m, k;
  while (~scanf("%d%d%d", &n, &m, &k)) {
    for (int i = 0; i < (n); ++i)
      for (int j = 0; j < (m); ++j) scanf("%d", &ipt[i][j]);
    if (n > m) {
      for (int i = 0; i < (n); ++i)
        for (int j = (i + 1); j < (m); ++j) swap(ipt[i][j], ipt[j][i]);
      swap(n, m);
    }
    if (n > k) {
      int ans = INF;
      for (int i = 0; i < (n); ++i) {
        int tans = 0;
        for (int j = 0; j < (n); ++j) {
          int cnt = 0;
          if (i == j) continue;
          for (int k = 0; k < (m); ++k) {
            if (ipt[i][k] != ipt[j][k]) cnt++;
          }
          tans += min(cnt, m - cnt);
        }
        ans = min(ans, tans);
      }
      printf("%d\n", ans <= k ? ans : -1);
    } else {
      int ans = INF;
      for (int i = 0; i < (n); ++i) {
        int all = 1 << m;
        for (int q = 0; q < all; q++) {
          int diff = 0;
          for (int t = 0, l = 1; t < m; l <<= 1, t++)
            if (((q & l) != 0) != ipt[i][t]) diff++;
          if (diff > k) continue;
          int tans = 0;
          for (int j = 0; j < (n); ++j) {
            if (i == j) continue;
            int cnt = 0;
            for (int t = 0, l = 1; t < m; t++, l <<= 1)
              if ((((q & l) != 0)) != ipt[j][t]) cnt++;
            tans += min(cnt, m - cnt);
          }
          ans = min(ans, diff + tans);
        }
      }
      printf("%d\n", ans <= k ? ans : -1);
    }
  }
  return 0;
}
