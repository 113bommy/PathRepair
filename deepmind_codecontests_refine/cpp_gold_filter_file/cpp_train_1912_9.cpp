#include <bits/stdc++.h>
using namespace std;
const int NMAX = 105, MMAX = 1e4 + 5;
int n, m;
string table[NMAX];
int idx[NMAX][MMAX];
int main() {
  cin >> n >> m;
  for (int r = 0; r < n; ++r) {
    cin >> table[r];
    memset(idx[r], MMAX, sizeof(idx[r]));
    bool ok = false;
    for (int c = 0; c < m; ++c) {
      if (table[r][c] == '1') {
        idx[r][c] = 0;
        ok = true;
      }
    }
    if (!ok) {
      puts("-1");
      return 0;
    }
    for (int i = 1; i <= 2 * m; ++i)
      idx[r][i % m] = min(idx[r][i % m], idx[r][(i - 1) % m] + 1);
    for (int i = 2 * m; i >= 1; --i)
      idx[r][i % m] = min(idx[r][i % m], idx[r][(i + 1) % m] + 1);
  }
  int ans = NMAX * MMAX;
  for (int c = 0; c < m; ++c) {
    int res = 0;
    for (int r = 0; r < n; ++r) res += idx[r][c];
    ans = min(ans, res);
  }
  cout << ans << '\n';
}
