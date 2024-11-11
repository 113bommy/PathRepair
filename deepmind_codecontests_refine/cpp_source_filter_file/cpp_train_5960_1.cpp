#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> chips(k);
  vector<pair<int, int>> pos(k);
  int my = 0, mx = 0;
  for (auto &x : chips) {
    cin >> x.first >> x.second;
  }
  for (auto &x : pos) {
    cin >> x.first >> x.second;
  }
  cout << ((n - 1) + (m - 1) + n * (m - 1) + n - 1) << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << 'U';
  }
  for (int j = 0; j < m - 1; j++) {
    cout << 'L';
  }
  int diry = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (diry == -1) {
        cout << 'D';
      } else {
        cout << 'U';
      }
      if (j == m - 2) {
        if (diry == -1)
          diry = 1;
        else
          diry = -1;
      }
    }
    if (i < n - 1) cout << 'R';
  }
}
