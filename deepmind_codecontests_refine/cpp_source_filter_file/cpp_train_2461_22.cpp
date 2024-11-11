#include <bits/stdc++.h>
using namespace std;
const int N = 705, P = 1e9 + 7;
int n, a[N];
char s[N];
long long f[N][10][N][2];
long long dp(int i, int j, int k, int less) {
  if (k < 0) return 0;
  if (!i) return k == 0;
  long long& res = f[i][j][k][less];
  if (~res) return res;
  res = 0;
  for (int l = (0); l <= (less ? 9 : a[i]); l++)
    res = (res + dp(i - 1, j, k - (l >= j), less || l < a[i])) % P;
  return res;
}
long long calc(int i, int j, long long res = 0) {
  if (j < 10)
    for (int k = (i); k <= (n); k++) res = (res + dp(n, j, k, 0)) % P;
  return res;
}
int main() {
  scanf("%s", s + 1), n = strlen(s + 1);
  for (int i = (1); i <= (n); i++) a[i] = s[n + 1 - i] - 48;
  memset(f, -1, sizeof f);
  long long ans = 0, ten = 1;
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (9); j++)
      ans = (ans + (calc(i, j) - calc(i, j + 1) + P) * j * ten) % P;
    ten = ten * 10 % P;
  }
  return cout << ans, 0;
}
