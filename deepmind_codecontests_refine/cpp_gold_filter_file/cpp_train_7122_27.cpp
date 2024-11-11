#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
pair<int, int> a[1000009];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n >> m && n != 0) {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < m; i++) {
      cin >> x >> y >> z;
      a[x].first += z;
      a[y].second += z;
    }
    long long sol = 0;
    for (int i = 0; i <= n; i++) {
      if (a[i].first > a[i].second) sol += a[i].first - a[i].second;
    }
    cout << sol << endl;
  }
  return 0;
}
