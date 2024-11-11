#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e5 + 10;
const int base = 20;
int n, m;
int f[maxN][20];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int l, r;
    cin >> l >> r;
    f[l][0] = max(f[l][0], r);
  }
  for (int i = 1; i <= maxN - 1; ++i)
    if (f[i - 1][0] && f[i - 1][0] > f[i][0]) f[i][0] = f[i - 1][0];
  for (int i = 1; 1 << i < maxN; ++i)
    for (int j = 0; j < maxN; ++j)
      if (f[j][i - 1]) f[j][i] = f[f[j][i - 1]][i - 1];
  for (int i = 1; i <= m; ++i) {
    int l, r;
    cin >> l >> r;
    if (f[l][base] < r) {
      cout << -1 << endl;
      continue;
    }
    int res = 0;
    for (int i = base; i >= 0; --i) {
      if (f[l][i] < r && f[l][i]) {
        res += (1 << i);
        l = f[l][i];
      }
    }
    cout << res + 1 << endl;
  }
  return 0;
}
