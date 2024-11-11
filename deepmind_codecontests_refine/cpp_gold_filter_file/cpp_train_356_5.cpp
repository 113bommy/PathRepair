#include <bits/stdc++.h>
using namespace std;
double DP[705], Pre[705];
int n, k;
double ans = 0;
int main() {
  cin >> n >> k;
  int sq = 700;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sq; j++)
      DP[j] = 1.0 / k / (j + 1) * (Pre[j] * j + Pre[j + 1] + j * (j + 3) / 2) +
              1.0 * (k - 1) / k * Pre[j];
    for (int j = 1; j <= sq; j++) Pre[j] = DP[j];
  }
  printf("%0.12f", DP[1] * k);
}
