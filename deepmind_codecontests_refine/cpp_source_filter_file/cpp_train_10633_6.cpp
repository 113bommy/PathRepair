#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int64_t m, n, i, j, k;
  cin >> n >> m;
  vector<vector<int64_t>> v1(n + m - 1), v2(n + m - 1);
  int64_t a[n][m], b[n][m];
  for (int64_t i = int64_t(0); i < int64_t(n); ++i)
    for (int64_t j = int64_t(0); j < int64_t(m); ++j) cin >> a[i][j];
  for (int64_t i = int64_t(0); i < int64_t(n); ++i)
    for (int64_t j = int64_t(0); j < int64_t(n); ++j) cin >> b[i][j];
  for (int64_t k = int64_t(0); k < int64_t(n + m - 1); ++k) {
    for (i = (k < n) ? k : n - 1, j = (k < n) ? 0 : k - n + 1;
         i + j == k && i >= 0 && j < m; i--, j++) {
      v1[k].push_back(a[i][j]);
      v2[k].push_back(b[i][j]);
    }
    sort(v1[k].begin(), v1[k].end());
    sort(v2[k].begin(), v2[k].end());
    for (auto it1 = v1[k].begin(), it2 = v2[k].begin();
         it1 != v1[k].end() && it2 != v2[k].end(); ++it1, ++it2) {
      if (*it1 != *it2) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  return 0;
}
