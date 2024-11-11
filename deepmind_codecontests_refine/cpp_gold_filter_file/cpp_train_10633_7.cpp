#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int LINF = LONG_MAX;
const double eps = 10e-15;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > a(n + m);
  vector<vector<int> > b(n + m);
  int x;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> x;
      a[i + j].push_back(x);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> x;
      b[i + j].push_back(x);
    }
  }
  for (int i = 0; i < n + m; ++i) {
    sort(a[i].begin(), a[i].end());
    sort(b[i].begin(), b[i].end());
    if (a[i] != b[i]) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}
