#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int K = 105;
const int mod = (int)1e9 + 7;
int n, m;
int a[N];
int b[K][N];
int fact[N];
int dp[N][K];
int add(int a, int b) {
  int ret = a + b;
  if (ret >= mod) ret -= mod;
  return ret;
}
int sub(int a, int b) {
  int ret = a - b;
  if (ret < 0) ret += mod;
  return ret;
}
int mul(int a, int b) { return (long long)a * b % mod; }
int main() {
  fact[0] = 1;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < min(i + 1, K); j++) {
      if (j == 0 || j == i)
        dp[i][j] = 1;
      else
        dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j]);
    }
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  while (m--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    l--;
    r--;
    b[k + 1][l] = add(b[k + 1][l], 1);
    for (int i = k + 1; i > 0; i--)
      b[i][r + 1] = sub(b[i][r + 1], dp[r - l + 1 + k - i][k + 1 - i]);
  }
  for (int i = 100; i >= 0; i--)
    for (int j = 0; j < n; j++)
      b[i][j] = add(b[i][j], add(j > 0 ? b[i][j - 1] : 0, b[i + 1][j]));
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%d", add(a[i], b[1][i]));
  }
  putchar('\n');
  return 0;
}
