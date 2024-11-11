#include <bits/stdc++.h>
using namespace std;
const int maxN = 510, modP = 1e9 + 7;
int f[maxN][maxN][2], res, n, a[maxN][maxN];
int dp(int i, int j, int t) {
  if (f[i][j][t] != -1) return f[i][j][t];
  if (i == j - 1 && t) return 1;
  if (i == j) return 1;
  int tmp = 0;
  for (int k = i + 1; k <= j - 1; ++k)
    if (a[i][k]) tmp = (tmp + (1ll * dp(i, k, 1) * dp(k, j, t)) % modP) % modP;
  if (t) tmp = (tmp + dp(i + 1, j, 0)) % modP;
  if (a[i][j] && !t) tmp = (tmp + dp(i, j, 1)) % modP;
  return (f[i][j][t] = tmp);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
  memset(f, 255, sizeof(f));
  cout << dp(1, n, 0) << endl;
}
