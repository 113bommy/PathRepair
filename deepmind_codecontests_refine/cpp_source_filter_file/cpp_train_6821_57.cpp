#include <bits/stdc++.h>
using namespace std;
pair<int, int> rs[5001];
pair<int, int> cs[5001];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int r, a;
      cin >> r >> a;
      rs[r] = {a, i};
    } else {
      int c, a;
      cin >> c >> a;
      cs[c] = {a, i};
    }
  }
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= m; x++) {
      pair<int, int> r = rs[y];
      pair<int, int> c = cs[x];
      if (r.second >= c.second) {
        cout << r.first << " ";
      } else {
        cout << c.first << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
