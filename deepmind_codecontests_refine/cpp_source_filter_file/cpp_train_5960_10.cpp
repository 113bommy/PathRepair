#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const int mod = 1e9 + 7;
int main() {
  int n, m, k, x, y;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> x >> y;
  for (int i = 0; i < k; i++) cin >> x >> y;
  string res;
  for (int i = 1; i <= m - 1; i++) res.push_back('R');
  for (int i = 1; i <= n - 1; i++) res.push_back('D');
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      for (int j = 0; j < m - 1; j++) res.push_back('L');
      if (i != n) res.push_back('U');
    } else {
      for (int j = 0; j < m - 1; j++) res.push_back('R');
      if (i != n) res.push_back('U');
    }
  }
  cout << res.size() << res;
  return 0;
}
