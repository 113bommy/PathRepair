#include <bits/stdc++.h>
using namespace std;
long long T[42];
long long T1[22], T2[22];
long long dp1[1 << 20], dp2[1 << 20];
int n, m;
bool clique1(long long mask, int v) {
  long long neighs = (1LL << m) - 1;
  for (int i = 0; i < m; i++)
    if (mask & (1 << i)) neighs &= T1[i];
  return neighs & (1LL << v);
}
bool clique2(long long mask, int v) {
  long long neighs = (1LL << (n - m)) - 1;
  for (int i = 0; i < n - m; i++)
    if (mask & (1 << i)) neighs &= T2[i];
  return neighs & (1LL << v);
}
int main() {
  int k;
  scanf("%d%d", &n, &k);
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      long long x;
      scanf("%lld", &x);
      T[i] += (x << j);
    }
  m = n / 2;
  long long mask1 = (1LL << m) - 1;
  for (int i = 0; i < m; i++) T1[i] = T[i] & mask1;
  for (int i = m; i < n; i++) T2[i - m] = T[i] >> m;
  for (int i = 0; i < (1 << m); i++)
    for (int j = 0; j < m; j++) {
      if (((i & (1 << j)) == 0 or
           __builtin_popcount(dp1[i - (1 << j)]) < __builtin_popcount(dp1[i])))
        continue;
      if (clique1(dp1[i - (1 << j)], j))
        dp1[i] = dp1[i - (1 << j)] + (1 << j);
      else
        dp1[i] = dp1[i - (1 << j)];
    }
  for (int i = 0; i < (1 << (n - m)); i++)
    for (int j = 0; j < n - m; j++) {
      if (((i & (1 << j)) == 0 or
           __builtin_popcount(dp2[i - (1 << j)]) < __builtin_popcount(dp2[i])))
        continue;
      if (clique2(dp2[i - (1 << j)], j))
        dp2[i] = dp2[i - (1 << j)] + (1 << j);
      else
        dp2[i] = dp2[i - (1 << j)];
    }
  int ans = 0;
  for (int i = 0; i < (1 << m); i++) {
    long long neighs = (1 << n) - 1;
    for (int j = 0; j < m; j++)
      if (dp1[i] & (1 << j)) neighs &= T[j];
    neighs >>= m;
    ans =
        max(ans, __builtin_popcount(dp1[i]) + __builtin_popcount(dp2[neighs]));
  }
  printf("%.8f\n", 1. * (ans - 1) * k * k / (2 * ans));
  return 0;
}
