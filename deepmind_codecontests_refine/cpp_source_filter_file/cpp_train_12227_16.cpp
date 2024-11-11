#include <bits/stdc++.h>
using namespace std;
int n, m, w[500][500], x[500];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 500; ++i)
    for (int j = 0; j < 500; ++j) w[i][j] = -1;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> x[i];
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    cin >> w[--u][--v];
    w[v][u] = w[u][v];
  }
  long long z = 0, y = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (j != i && w[i][j] != -1) {
        if (y == 0 || (y * (x[i] + x[j]) > z * w[i][j])) {
          z = x[i] + x[j];
          y = w[i][j];
        }
      }
  if (y == 0) {
    cout << "0\n";
    return 0;
  }
  cout << setprecision(9) << ((double)z / y) << '\n';
  return 0;
}
