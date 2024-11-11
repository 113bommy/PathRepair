#include <bits/stdc++.h>
using namespace std;
pair<int, int> cx[5005], cy[5005];
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    int t, x, c;
    cin >> t >> x >> c;
    if (t == 1) {
      cx[x - 1] = {c, i};
    } else {
      cy[x - 1] = {c, i};
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (cx[i].second > cy[j].second ? cx[i].first : cy[j].first) << ' ';
    }
    cout << '\n';
  }
}
