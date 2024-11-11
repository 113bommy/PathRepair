#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N][N], b[N][N], c[N][N], d[N][N], lenc[N], lend[N];
int n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      c[i][j] = a[i][j];
      b[j][i] = a[i][j];
      d[j][i] = b[j][i];
    }
  }
  for (int i = 0; i < n; ++i) {
    sort(c[i], c[i] + m);
    lenc[i] = unique(c[i], c[i] + m) - c[i];
  }
  for (int i = 0; i < m; ++i) {
    sort(d[i], d[i] + n);
    lend[i] = unique(d[i], d[i] + n) - d[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int posa = lower_bound(c[i], c[i] + lenc[i], a[i][j]) - c[i];
      int posb = lower_bound(d[j], d[j] + lend[j], a[i][j]) - d[j];
      int diffa = 0, diffb = 0;
      if (posa < posb)
        diffb = posb - posa;
      else
        diffa = posa - posb;
      cout << max(lenc[i] + diffa, lend[j] + diffb) << " ";
    }
    cout << endl;
  }
  return 0;
}
