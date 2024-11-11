#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const double eps = 1e-6;
const double PI = acos(-1);
int n, R, F[N], S[N], up;
double P[N];
double dp[50 + 7][50 * 100 + 7];
double dfs(int i, int j, double x) {
  if (i == n) {
    if (j <= R)
      return 0;
    else
      return x;
  }
  if (dp[i][j] + eps > 0) return dp[i][j];
  double T1 = P[i + 1] * (dfs(i + 1, j + F[i + 1], x) + F[i + 1]) +
              (1 - P[i + 1]) * (dfs(i + 1, j + S[i + 1], x) + S[i + 1]);
  dp[i][j] = min(T1, x);
  return dp[i][j];
}
bool check(double x) {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= up; j++) dp[i][j] = -1;
  if (dfs(0, 0, x) < x)
    return true;
  else
    return false;
}
int main() {
  scanf("%d%d", &n, &R);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%lf", &F[i], &S[i], &P[i]);
    P[i] /= 100;
    up += S[i];
  }
  double low = n, high = 5e8;
  for (int o = 1; o <= 50; o++) {
    double mid = (low + high) / 2;
    if (check(mid))
      high = mid;
    else
      low = mid;
  }
  printf("%.12f\n", (low + high) / 2);
  return 0;
}
