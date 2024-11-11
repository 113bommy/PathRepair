#include <bits/stdc++.h>
using namespace std;
const int mod = 1000003;
int n, m;
vector<string> mat;
vector<int> mkRow;
vector<int> mkCol;
int main() {
  cin >> n >> m;
  string t;
  int ans = 1;
  mkRow = vector<int>(n, 3);
  mkCol = vector<int>(m, 3);
  for (int i = 0; i < n; i++) {
    cin >> t;
    mat.push_back(t);
    for (int j = 0; j < m; j++) {
      switch (mat[i][j]) {
        case '1':
          mkRow[i] &= ~((j & 1) > 0 ? 1 : 2);
          mkCol[j] &= ~((i & 1) > 0 ? 1 : 2);
          break;
        case '2':
          mkRow[i] &= ~((j & 1) > 0 ? 1 : 2);
          mkCol[j] &= ~((i & 1) > 0 ? 2 : 1);
          break;
        case '3':
          mkRow[i] &= ~((j & 1) > 0 ? 2 : 1);
          mkCol[j] &= ~((i & 1) > 0 ? 2 : 1);
          break;
        case '4':
          mkRow[i] &= ~((j & 1) > 0 ? 2 : 1);
          mkCol[j] &= ~((i & 1) > 0 ? 1 : 2);
          break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mkRow[i] == 0 || mkCol[j] == 0) {
        ans = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (mkRow[i] == 3) ans = ans * 2 % mod;
  }
  for (int j = 0; j < m; j++) {
    if (mkCol[j] == 3) ans = ans * 2 % mod;
  }
  cout << ans << endl;
  return 0;
}
