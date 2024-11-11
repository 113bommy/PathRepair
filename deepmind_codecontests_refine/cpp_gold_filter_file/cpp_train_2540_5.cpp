#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const long long mod = 1e9 + 7;
int n, ent[N], foi[N], dp[N][N];
long long mult(int a, int b) {
  long long c = 1ll * a * 1ll * b;
  c %= mod;
  return c;
}
int solve(int tot, int caga) {
  if (caga < 0 || tot < 0 || tot < caga) return 0;
  if (tot == 0 && caga == 0) return 1;
  int &ret = dp[tot][caga];
  if (ret != -1) return ret;
  ret = 0;
  if (caga) {
    if (caga > 1) (ret += mult(solve(tot - 1, caga - 2), caga - 1)) %= mod;
    (ret += mult(solve(tot - 1, caga - 1), tot - caga)) %= mod;
  }
  if (caga == 0) (ret += mult(solve(tot - 1, caga), tot)) %= mod;
  return ret;
}
int main() {
  memset((dp), (-1), sizeof(dp));
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); (i)++) {
    scanf("%d", &ent[i]);
    if (ent[i] > 0) ent[i]--;
  }
  for (int(i) = (0); (i) < (n); (i)++) {
    if (ent[i] >= 0) foi[ent[i]] = 1;
  }
  int tot = 0, caga = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    if (!foi[i]) tot++;
    if (!foi[i] && ent[i] < 0) caga++;
  }
  printf("%d\n", solve(tot, caga));
}
