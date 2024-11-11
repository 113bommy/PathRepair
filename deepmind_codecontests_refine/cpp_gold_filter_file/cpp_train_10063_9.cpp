#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    c[i] = a[i].first;
    a[i].second = i;
  }
  vector<vector<int>> b(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (a[x].first > a[y].first) b[x].push_back(y);
    if (a[y].first > a[x].first) b[y].push_back(x);
  }
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(c.begin(), c.end(), a[i].first);
    int k = it - c.begin();
    r[a[i].second] = max(0, int(k - b[a[i].second].size()));
  }
  for (int i = 0; i < n; i++) cout << r[i] << " ";
  cout << endl;
}
