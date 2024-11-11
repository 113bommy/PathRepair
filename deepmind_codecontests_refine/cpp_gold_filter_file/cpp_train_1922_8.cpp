#include <bits/stdc++.h>
using namespace std;
long long f[5005][5005], d[5005], n, m, k;
int main() {
  cin >> n >> m >> k;
  ;
  for (int i = 1; i <= n; ++i) scanf("%d", &d[i]), d[i] += d[i - 1];
  for (int i = m; i <= n; ++i)
    for (int j = 1; j <= i / m; ++j)
      f[i][j] = max(f[i - 1][j], f[i - m][j - 1] + d[i] - d[i - m]);
  cout << f[n][k];
}
