#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> k;
  int n, m;
  n = m = 0;
  bool ok = false;
  for (int i = 5; i * i <= k; i++) {
    if (k % i == 0) {
      int p = k / i;
      if (p >= 5) {
        n = i;
        m = p;
        ok = 1;
        break;
      }
    }
  }
  if (!ok) {
    cout << -1;
    return 0;
  }
  vector<char> h;
  h.push_back('a');
  h.push_back('e');
  h.push_back('o');
  h.push_back('u');
  h.push_back('i');
  for (int i = 5; i < m; i++) {
    h.push_back(h[i % 5]);
  }
  vector<vector<char>> ans(n, vector<char>(m));
  for (int i = 0; i < 5; i++) {
    int j = i;
    int tmp = 0;
    while (j < 5) {
      ans[i][tmp] = h[j];
      j++;
      tmp++;
    }
    j = 0;
    while (j < i) {
      ans[i][tmp] = h[j];
      j++;
      tmp++;
    }
  }
  for (int i = 5; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[i][j] = ans[0][j];
    }
  }
  for (int i = 5; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ans[j][i] = ans[j][0];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j];
    }
  }
  return 0;
}
