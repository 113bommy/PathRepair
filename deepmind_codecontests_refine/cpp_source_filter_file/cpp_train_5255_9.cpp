#include <bits/stdc++.h>
using namespace std;
long long a[105][105], v[105], u[105], i, j, n, m, MOD;
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> a[i][j];
  for (i = 1; i <= m; i++) v[i] = a[n][i];
  for (i = 1; i < n; i++) {
    u[i] = a[i][1] - v[1];
    for (j = 2; j <= m; j++)
      if (u[i] + v[j] != a[i][j]) MOD = abs(u[i] + v[j] - a[i][j]);
  }
  if (!MOD) MOD = 2000000000;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (((long long)u[i] + v[j]) % MOD != a[i][j]) {
        cout << "NO";
        return 0;
      }
  cout << "YES" << endl << MOD << endl;
  for (i = 1; i <= n; i++) cout << (u[i] + MOD) % MOD << ' ';
  cout << endl;
  for (i = 1; i <= m; i++) cout << (v[i] + MOD) % MOD << ' ';
  return 0;
}
