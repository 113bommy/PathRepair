#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
double dp[2005][2005];
double p;
int n, t;
double call(int n1, int t1) {
  if (n1 == 0) return 0;
  if (t1 == 1) return p;
  if (dp[n1][t1] != -1) return dp[n1][t1];
  double res = p * (call(n1 - 1, t1 - 1) + 1) + (1 - p) * (call(n1, t1 - 1));
  return dp[n1][t1] = res;
}
int main() {
  int i, j;
  for (i = 0; i <= 2004; i++) {
    for (j = 0; j <= 2004; j++) {
      dp[i][j] = -1;
    }
  }
  scanf("%d %lf %d", &n, &p, &t);
  double res = call(n, t);
  printf("%.6lf\n", res);
  return 0;
}
