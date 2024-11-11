#include <bits/stdc++.h>
using namespace std;
bool br;
long long t, k, n, m, sum, x, y, z, mini, maxi, w, l;
bool a[(int)1e3][(int)1e3], up[(int)1e3][(int)1e3], down[(int)1e3][(int)1e3],
    le[(int)1e3][(int)1e3], r[(int)1e3][(int)1e3];
void solve() {
  cin >> n >> m;
  k = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
      r[i][j] = up[i][j] = le[i][j] = down[i][j] = a[i][j];
    }
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      if (i) up[i][j] |= up[i - 1][j];
      if (j) le[i][j] |= le[i][j - 1];
      if (up[i][j] && a[i][j] == 0) k++;
      if (le[i][j] && a[i][j] == 0) k++;
    }
  for (long long i = n; i >= 0; i--)
    for (long long j = m; j >= 0; j--) {
      if (i + 1 < n) down[i][j] |= down[i + 1][j];
      if (j + 1 < m) r[i][j] |= r[i][j + 1];
      if (down[i][j] && a[i][j] == 0) k++;
      if (r[i][j] && a[i][j] == 0) k++;
    }
  cout << k << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
