#include <bits/stdc++.h>
using namespace std;
int dp[317][200200];
int n, m, x;
int get(int p, int d, int f) {
  if (f < 0 || d < 0) return 0;
  if (p == m) {
    if (d == 0 && f == 0) return 1;
    return 0;
  }
  if (dp[d][f * m + p] + 1) return dp[d][f * m + p];
  long long ret = 0;
  ret += get(p + 1, d + 1, f - 1);
  ret += get(p + 1, d, f - 1);
  if (p - x) ret += get(p + 1, d - 1, f);
  if (p - x) ret += get(p + 1, d, f);
  return dp[d][f * m + p] = ret % 1000000007;
}
int main() {
  scanf("%d%d%d", &n, &m, &x), x--;
  memset(dp, -1, sizeof(dp));
  long long fa = 1;
  for (int i = 1; i <= n; i++) fa = (fa * i) % 1000000007;
  printf("%I64d\n", (fa * get(0, 0, n)) % 1000000007);
}
