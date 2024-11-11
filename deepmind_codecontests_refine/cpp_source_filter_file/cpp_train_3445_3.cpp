#include <bits/stdc++.h>
using namespace std;
const int N = 110;
long long a[N], b[N], g[N][N];
int main() {
  int n, m;
  cin >> n >> m;
  long long xx = -1, yy = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (xx == -1)
      xx = a[i];
    else
      xx ^= a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    if (yy == -1)
      yy = a[i];
    else
      yy ^= a[i];
  }
  if (xx != yy) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 1; i < n; ++i) g[i][m] = a[i];
  for (int i = 1; i < m; ++i) g[n][i] = b[i];
  g[n][m] = (xx ^ a[n] ^ b[m]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cout << g[i][j] << " ";
    cout << endl;
  }
  return 0;
}
