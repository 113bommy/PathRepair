#include <bits/stdc++.h>
using namespace std;
int n, a[110];
long long f[110][110][110][2];
char s[110];
long long dp(int l, int r, int k, int t) {
  if (l > r) {
    return a[k];
  }
  if (f[l][r][k][t] != -1) {
    return f[l][r][k][t];
  }
  long long res = 0;
  if (!k || t == s[l]) {
    res = max(res, dp(l + 1, r, k + 1, s[l]));
  }
  for (int i = l; i < r; i++) {
    res = max(res, dp(l, i, 0, '0') + dp(i + 1, r, k, t));
  }
  for (int i = 1; i <= k; i++) {
    res = max(res, dp(l, r, k - i, t) + a[i]);
  }
  f[l][r][k][t] = res;
  return res;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  memset(f, -1, sizeof(f));
  cout << dp(1, n, 0, '0') << endl;
  return 0;
}
