#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
const int maxn = 1006;
double dp[maxn][maxn][3];
int main() {
  int w, b;
  scanf("%d%d", &w, &b);
  for (int i = 0; i <= w; i++) {
    dp[i][0][1] = 1.0;
    dp[i][0][0] = 0.0;
  }
  for (int i = 0; i <= b; i++) {
    dp[0][i][1] = 0.0;
    dp[0][i][0] = 0.0;
  }
  for (int i = 1; i <= w; i++) {
    for (int j = 1; j <= b; j++) {
      double part1 = ((double)i) * dp[i - 1][j - 1][1] / ((double)(i + j - 1));
      double part2 = 0.0;
      if (j >= 2)
        part2 = ((double)(j - 1)) * dp[i][j - 2][1] / (double)((i + j - 1));
      dp[i][j][0] = ((double)j) * (part1 + part2) / ((double)(i + j));
      dp[i][j][1] =
          (double)((double)i + dp[i][j - 1][0] * (double)j) / ((double)(i + j));
    }
  }
  printf("%lf\n", dp[w][b][1]);
  return 0;
}
