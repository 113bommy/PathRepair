#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005, MOD = 1e9 + 7;
int add(int first, int second) {
  first += second;
  if (first >= MOD) first -= MOD;
  return first;
}
int mult(long long first, long long second) { return first * second % MOD; }
int pot(int n, int k) {
  if (k == 0) return 1;
  int ret = pot(n, k / 2);
  ret = mult(ret, ret);
  if (k & 1) ret = mult(ret, n);
  return ret;
}
int divide(int first, int second) { return mult(first, pot(second, MOD - 2)); }
int n;
int A[maxn];
int dp1[maxn][maxn];
int dp2[2 * maxn][2];
int dp3[2 * maxn][2];
int ans[maxn];
int pref[maxn];
int rek1(int first, int second) {
  if (second == 0) return dp1[first][second] = 1;
  if (dp1[first][second] != -1) return dp1[first][second];
  int ret = 0;
  if (first + 1 < n) ret = mult(rek1(first + 1, second - 1), A[first]);
  return dp1[first][second] = ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) scanf("%d", A + i);
  pref[0] = 1;
  for (int i = 1; i < n; i++) pref[i] = mult(pref[i - 1], A[i - 1]);
  memset(dp1, -1, sizeof dp1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) rek1(i, j);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      for (int k = 0; k < 2; k++) {
        if (j == 0) {
          dp3[j][k] = 1;
          continue;
        }
        if (i) dp3[j][k] = dp2[j - 1][1];
        if (k && j <= n)
          dp3[j][k] = add(dp3[j][k], mult(dp1[i + 1][j - 1], A[i] - 1));
        if (k == 0) ans[j] = add(ans[j], mult(dp3[j][k], pref[i]));
      }
    }
    for (int j = 0; j < 2 * n - 1; j++)
      for (int k = 0; k < 2; k++) dp2[j][k] = dp3[j][k];
  }
  for (int j = 0; j < n; j++)
    for (int i = 0; i < n; i++) ans[j] = add(ans[j], mult(dp1[i][j], pref[i]));
  for (int i = 1; i < 2 * n - 1; i++) printf("%d ", divide(ans[i], 2));
  printf("\n");
  return 0;
}
