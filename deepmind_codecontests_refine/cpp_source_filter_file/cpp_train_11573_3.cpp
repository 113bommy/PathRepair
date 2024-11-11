#include <bits/stdc++.h>
using namespace std;
const int D = 1;
const int U = 2;
const int L = 1;
const int R = 2;
const int M = 1000003;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  vector<int> rows(n);
  vector<int> cols(m);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
    for (int j = 0; j < n; ++j) {
      if (g[i][j] == '1') {
        rows[i] |= (j & 1) ? R : L;
        cols[j] |= (i & 1) ? D : U;
      } else if (g[i][j] == '2') {
        rows[i] |= (j & 1) ? R : L;
        cols[j] |= (i & 1) ? U : D;
      } else if (g[i][j] == '3') {
        rows[i] |= (j & 1) ? L : R;
        cols[j] |= (i & 1) ? U : D;
      } else if (g[i][j] == '4') {
        rows[i] |= (j & 1) ? L : R;
        cols[j] |= (i & 1) ? D : U;
      }
    }
  }
  int res = 1;
  for (int i = 0; i < n; ++i) {
    if (rows[i] == 3) do {
        cout << 0 << endl;
        return 0;
      } while (0);
    if (rows[i] == 0) res = (res * 2) % M;
  }
  for (int i = 0; i < m; ++i) {
    if (cols[i] == 3) do {
        cout << 0 << endl;
        return 0;
      } while (0);
    if (cols[i] == 0) res = (res * 2) % M;
  }
  cout << res << endl;
  return 0;
}
