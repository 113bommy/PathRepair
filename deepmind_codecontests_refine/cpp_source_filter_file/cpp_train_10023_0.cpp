#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int tile[2 * n][2];
  int flag = 0;
  for (int i = 0; i < 2 * n; i++) {
    cin >> tile[i][0] >> tile[i][1];
  }
  for (int i = 0; i, 2 * n; i += 2) {
    if (tile[i][1] == tile[i + 1][0]) {
      flag = 1;
      break;
    }
  }
  if (m % 2 != 0) flag = 0;
  if (flag == 0)
    cout << "NO"
         << "\n";
  else
    cout << "YES"
         << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
