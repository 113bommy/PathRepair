#include <bits/stdc++.h>
using namespace std;
const int maxn = 250 + 14;
int n, m, a[maxn][maxn], r[maxn], c[maxn];
struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    if (a.first - a.second != b.first - b.second)
      return a.first - a.second > b.first - b.second;
    return a.first < b.first;
  }
};
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      r[i] = max(r[i], x);
      c[j] = max(c[j], x);
    }
  sort(r, r + n);
  sort(c, c + m);
  set<pair<int, int>, cmp> up, down;
  int cr = n - 1, cc = m - 1;
  for (int i = n * m; i >= 1; i--) {
    if (binary_search(r, r + n, i) && binary_search(c, c + m, i)) {
      for (int i = cc + 1; i < m; i++) up.insert({cr, i});
      for (int i = cr + 1; i < n; i++) down.insert({i, cc});
      a[cr--][cc--] = i;
    } else if (binary_search(r, r + n, i)) {
      for (int i = cc + 2; i < m; i++) up.insert({cr, i});
      a[cr--][cc + 1] = i;
    } else if (binary_search(c, c + m, i)) {
      for (int i = cr + 2; i < n; i++) down.insert({i, cc});
      a[cr + 1][cc--] = i;
    } else {
      if (up.size()) {
        a[up.begin()->first][up.begin()->second] = i;
        up.erase(up.begin());
      } else if (down.size()) {
        a[down.rbegin()->first][down.rbegin()->second] = i;
        down.erase(--down.end());
      } else
        assert(false);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
    cout << '\n';
  }
}
