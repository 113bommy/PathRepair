#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int n;
double dp[102][102][102];
int main() {
  int i, j, t, k;
  int r, s, p;
  scanf("%d %d %d", &r, &s, &p);
  dp[r][s][p] = 1;
  for (i = r; i >= 0; i--) {
    for (j = s; j >= 0; j--) {
      for (k = p; k >= 0; k--) {
        int total = i * j + j * k + k * i;
        if (i && j)
          dp[i][j - 1][k] +=
              (double)(((i * j) / ((double)total)) * dp[i][j][k]);
        if (j && k)
          dp[i][j][k - 1] += (double)((j * k) / ((double)total)) * dp[i][j][k];
        if (i && k)
          dp[i - 1][j][k] += (double)((i * k) / (double)total) * dp[i][j][k];
      }
    }
  }
  double ans1, ans2, ans3;
  ans1 = 0.0;
  ans2 = 0.0;
  ans3 = 0.0;
  for (i = r; i >= 0; i--) {
    for (j = s; j >= 0; j--) {
      for (k = r; k >= 0; k--) {
        if (i && !j && !k) ans1 += dp[i][j][k];
        if (!i && j && !k) ans2 += dp[i][j][k];
        if (!i && !j && k) ans3 += dp[i][j][k];
      }
    }
  }
  printf("%.12lf %.12lf %.12lf\n", ans1, ans2, ans3);
  return 0;
}
