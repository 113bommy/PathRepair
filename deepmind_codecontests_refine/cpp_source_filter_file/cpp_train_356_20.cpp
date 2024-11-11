#include <bits/stdc++.h>
using namespace std;
const int inft = 1000000009;
const int MAXN = 100005;
const int MAGIC = 500;
vector<double> dp[2];
int main() {
  for (int i = 0; i < (2); ++i) dp[i].resize(MAGIC);
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < MAGIC && j + i <= n + 1; j++)
      dp[1][j] = 1. * (k - 1) / k * dp[0][j] +
                 1. / k / (j + 1) *
                     (1. * j * dp[0][j] + 1. * j * (j + 3) / 2 + dp[0][j + 1]);
    swap(dp[0], dp[1]);
  }
  printf("%.12lf\n", dp[0][1] * k);
  return 0;
}
