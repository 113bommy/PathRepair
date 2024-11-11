#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void solve() {
  int r, c;
  cin >> r >> c;
  vector<vector<int> > ans(r, vector<int>(c));
  int cur = 2;
  if (r == 1 or c == 1) {
    if (r == 1 and c == 1) {
      cout << 0;
      return;
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) cout << cur++ << ' ';
      cout << '\n';
    }
    return;
  }
  for (int i = 0; i < c; i++) {
    ans[0][i] = cur++;
  }
  for (int i = 1; i < r; i++) {
    for (int j = 0; j < c; j++) ans[i][j] = ans[0][j] * cur;
    cur++;
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) cout << ans[i][j] << ' ';
    cout << '\n';
  }
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
