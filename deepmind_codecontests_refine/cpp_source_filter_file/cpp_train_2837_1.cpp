#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<bool> r(n, true), c(m, true);
    for (int i = (0); i < (n); ++i) {
      for (int j = (0); j < (m); ++j) {
        int u;
        cin >> u;
        if (u == 1) {
          r[i] = false;
          c[j] = false;
        }
      }
    }
    int rows = 0, columns = 0;
    for (auto u : r)
      if (u) rows++;
    for (auto u : c)
      if (u) columns++;
    if (min(rows, columns) % 2)
      cout << "Vivek" << '\n';
    else
      cout << "Ashish" << '\n';
  }
  return 0;
}
