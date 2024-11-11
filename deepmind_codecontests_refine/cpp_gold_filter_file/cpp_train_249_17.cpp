#include <bits/stdc++.h>
using namespace std;
int dp[40005][45], a, b, n;
int calc(int a, int b) {
  if (~dp[a][b]) return dp[a][b];
  if (a == 1 && (1 << b) >= n) return 1;
  if (a * a >= n && b == 1) return 2 - 2 * ((n - a) & 1);
  if (pow(a, b) + 1e-6 >= n) return dp[a][b] = 2;
  return dp[a][b] = 2 - min(calc(a, b + 1), calc(a + 1, b));
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d%d", &a, &b, &n);
  int res = calc(a, b);
  puts(res == 1 ? "Missing" : (res == 2 ? "Masha" : "Stas"));
  return 0;
}
