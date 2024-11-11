#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[25], x[2];
int Dp[1 << 24], Sm[1 << 24];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  x[0] = x[1] = -1;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) scanf("%d", x + i);
  for (int i = 1; i < (1 << n); i++) {
    int j = __builtin_ctz(i);
    Sm[i] = (Sm[i ^ (1 << j)] + a[j]) % 1000000007;
  }
  Dp[0] = 1;
  for (int i = 1; i < (1 << n); i++) {
    if (Sm[i] != x[0] and Sm[i] != x[1])
      for (int j = 0; j < n; j++)
        if (i & (1 << j)) Dp[i] = (Dp[i] + Dp[i ^ (1 << j)]) % 1000000007;
  }
  printf("%d", Dp[(1 << n) - 1]);
  return 0;
}
