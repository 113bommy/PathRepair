#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
double fRand(double fMin, double fMax) {
  double f = (double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
int n, m, k, ans[1005][1005];
char condH[1005][1005], condV[1005][1005];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (0); i <= (n - 1); ++i) {
    scanf("%s", condH[i]);
    if (i < n - 1) scanf("%s", condV[i]);
  }
  if (k == 1) {
    int cnt = 0, tot = (n - 1) * m + n * (m - 1);
    for (int i = (0); i <= (n - 1); ++i)
      for (int j = (0); j <= (m - 2); ++j) {
        if (condH[i][j] == 'E') ++cnt;
      }
    for (int i = (0); i <= (n - 2); ++i)
      for (int j = (0); j <= (m - 1); ++j) {
        if (condV[i][j] == 'E') ++cnt;
      }
    if (4 * cnt >= 3 * tot) {
      puts("YES");
      for (int i = (0); i <= (n - 1); ++i) {
        for (int j = (0); j <= (m - 1); ++j) printf("%d ", 1);
        puts("");
      }
    } else
      puts("NO");
  } else {
    if (n * (m - 1) > (n - 1) * m) {
      for (int i = (0); i <= (n - 1); ++i) {
        ans[i][0] = 0;
        for (int j = (1); j <= (m - 1); ++j)
          ans[i][j] = ans[i][j - 1] ^ (condH[i][j - 1] == 'N');
        if (i > 0) {
          int cnt = 0;
          for (int j = (0); j <= (m - 1); ++j) {
            cnt += ((ans[i][j] ^ ans[i - 1][j]) == (condV[i - 1][j] == 'N'));
          }
          if (2 * cnt < m) {
            for (int j = (0); j <= (m - 1); ++j) ans[i][j] ^= 1;
          }
        }
      }
    } else {
      for (int j = (0); j <= (m - 1); ++j) {
        ans[0][j] = 0;
        for (int i = (1); i <= (n - 1); ++i)
          ans[i][j] = ans[i - 1][j] ^ (condV[i - 1][j] == 'N');
        if (j > 0) {
          int cnt = 0;
          for (int i = (0); i <= (n - 1); ++i) {
            cnt += ((ans[i][j] ^ ans[i][j - 1]) == (condH[i][j - 1] == 'N'));
          }
          if (2 * cnt < n) {
            for (int i = (0); i <= (n - 1); ++i) ans[i][j] ^= 1;
          }
        }
      }
    }
    puts("YES");
    for (int i = (0); i <= (n - 1); ++i) {
      for (int j = (0); j <= (m - 1); ++j) printf("%d ", ans[i][j] + 1);
      puts("");
    }
  }
  return 0;
}
