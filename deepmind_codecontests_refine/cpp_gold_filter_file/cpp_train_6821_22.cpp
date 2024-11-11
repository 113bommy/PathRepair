#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, a, b, x;
  cin >> n >> m >> k;
  vector<pair<int, int> > r(n, {0, -1}), c(m, {0, -1});
  for (int i = 0; i < k; i++) {
    cin >> a >> b >> x;
    if (a == 1) r[b - 1] = {x, i};
    if (a == 2) c[b - 1] = {x, i};
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j) cout << " ";
      if (r[i].second < c[j].second)
        cout << c[j].first;
      else
        cout << r[i].first;
    }
    cout << endl;
  }
  return 0;
}
