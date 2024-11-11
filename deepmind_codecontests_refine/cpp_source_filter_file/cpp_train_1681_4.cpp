#include <bits/stdc++.h>
using namespace std;
const long int N = 1e3 + 5;
int a[N][N], b[N], f[N][N], g[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) b[j] = a[i][j];
    sort(b + 1, b + m + 1);
    int cnt = unique(b + 1, b + m + 1) - b - 1;
    for (int j = 1; j <= m; j++) {
      int t = lower_bound(b + 1, b + cnt + 1, a[i][j]) - b;
      f[i][j] = t - 1;
      g[i][j] = cnt - t;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) b[j] = a[j][i];
    sort(b + 1, b + n + 1);
    int cnt = unique(b + 1, b + n + 1) - b - 1;
    for (int j = 1; j <= n; j++) {
      int t = lower_bound(b + 1, b + cnt + 1, a[j][i]) - b - 1;
      f[j][i] = max(f[j][i], t - 1);
      g[j][i] = max(g[j][i], cnt - t);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << endl;
    for (int j = 1; j <= m; j++) cout << (f[i][j] + g[i][j] + 1) << " ";
  }
  return 0;
}
