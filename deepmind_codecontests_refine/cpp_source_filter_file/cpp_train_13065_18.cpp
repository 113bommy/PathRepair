#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  int v[n + 1][m + 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * m; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (2 * m); j += 2) {
      if (v[i][j] == 1 || v[i][j + 1] == 1) ans++;
    }
  }
  cout << ans;
}
