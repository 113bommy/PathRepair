#include <bits/stdc++.h>
using namespace std;
int n, m, a, i, j, ans, f[11];
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a;
    f[a]++;
  }
  for (i = 1; i < m; i++)
    for (j = i + 1; j <= m; j++) ans += f[i] * f[j];
  cout << ans << endl;
  return 0;
}
