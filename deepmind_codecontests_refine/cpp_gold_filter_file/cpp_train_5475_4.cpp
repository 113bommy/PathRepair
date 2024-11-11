#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
long long sum[100007], dp[2][5007], x[5007];
pair<long long, long long> p[100007];
int n, m;
void pre(int i) {
  for (int j = 1; j <= n; j++) {
    sum[j] = abs(p[i].first - x[j]) + sum[j - 1];
  }
}
void rec(int i, int jl, int jr, int optl, int optr) {
  if (jl > jr) return;
  int mid = (jl + jr) / 2;
  int _i = i % 2;
  dp[_i][mid] = dp[_i ^ 1][mid];
  int aij = mid;
  long long mn;
  for (int k = min(optr, mid); k >= optl; k--) {
    if (mid - k + 1 <= p[i].second) {
      mn = sum[mid] - sum[k - 1];
      mn += dp[_i ^ 1][k - 1];
      if (dp[_i][mid] > mn) {
        dp[_i][mid] = mn;
        aij = k;
      }
    } else
      break;
  }
  rec(i, jl, mid - 1, optl, aij);
  rec(i, mid + 1, jr, aij, optr);
}
int main() {
  int i;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &x[i]);
  }
  sort(x + 1, x + n + 1);
  for (i = 1; i <= m; i++) {
    scanf("%lld %lld", &p[i].first, &p[i].second);
  }
  sort(p + 1, p + m + 1);
  for (int j = 1; j <= n; j++) dp[0][j] = 1000000000000000LL;
  dp[0][0] = 0;
  for (i = 1; i <= m; i++) {
    pre(i);
    rec(i, 1, n, 1, n);
  }
  long long ans;
  if (dp[m % 2][n] == 1000000000000000LL)
    ans = -1;
  else
    ans = dp[m % 2][n];
  cout << ans << endl;
  return 0;
}
