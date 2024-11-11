#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 11;
const int MAXN = 5e7 + 1;
const int BITMAX = 18;
const int INF = 1e9 + 2;
const long long LLINF = 1e17 + 3;
const int MOD = 1e9 + 7;
const long double Pi = acos(-1);
int n, l, r;
int dp[MAX][4];
int solve(int id, int md) {
  if (id == n) return md == 0;
  int &ret = dp[id][md];
  if (ret != -1) return ret;
  ret = 0;
  int tmp1 = md + r;
  int r1 = (r - l + 3) / 3;
  int tmp2 = md + r - 1;
  int r2 = (r - l + 2) / 3;
  int tmp3 = md + r - 2;
  int r3 = (r - l + 1) / 3;
  ret = (1ll * (r1)*solve(id + 1, tmp1 % 3) + ret) % MOD;
  ret = (1ll * (r2)*solve(id + 1, tmp2 % 3) + ret) % MOD;
  ret = (1ll * (r3)*solve(id + 1, tmp3 % 3) + ret) % MOD;
  return ret;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &l);
  scanf("%d", &r);
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(0, 0));
  return 0;
}
