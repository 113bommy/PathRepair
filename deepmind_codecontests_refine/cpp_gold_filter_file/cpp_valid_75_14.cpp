#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<int, int> > cave(n);
    for (int i = 0; i < n; i++) {
      cin >> m;
      cave[i] = make_pair(0, m);
      for (int j = 0; j < m; j++) {
        cin >> x;
        cave[i].first = max(x - j, cave[i].first);
      }
    }
    int pow = 0, sol = 0;
    sort(cave.begin(), cave.end());
    for (int i = 0; i < n; i++) {
      if (cave[i].first >= pow) {
        sol += cave[i].first - pow + 1;
        pow += cave[i].first - pow + 1;
      }
      pow += cave[i].second;
    }
    cout << sol << '\n';
  }
}
