#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, j, k, n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m)), row(n, vector<int>(m)),
      col(n, vector<int>(m));
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) cin >> arr[i][j];
  vector<int> row_max(n), col_max(m);
  for (i = 0; i < n; ++i) {
    vector<pair<int, int>> vec;
    for (j = 0; j < m; ++j) vec.push_back(make_pair(arr[i][j], j));
    sort(vec.begin(), vec.end());
    int elm;
    elm = vec[0].first;
    k = 1;
    for (j = 0; j < vec.size(); j++) {
      if (vec[j].first == elm)
        row[i][vec[j].second] = k;
      else {
        elm = vec[j].first;
        k++;
        row[i][vec[j].second] = k;
      }
    }
    row_max[i] = k;
  }
  for (j = 0; j < m; ++j) {
    vector<pair<int, int>> vec;
    for (i = 0; i < n; ++i) vec.push_back(make_pair(arr[i][j], i));
    sort(vec.begin(), vec.end());
    int elm;
    elm = vec[0].first;
    k = 1;
    for (i = 0; i < vec.size(); ++i) {
      if (vec[i].first == elm)
        col[vec[i].second][j] = k;
      else {
        k++;
        elm = vec[i].first;
        col[vec[i].second][j] = k;
      }
    }
    col_max[j] = k;
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      k = abs(row[i][j] - col[i][j]);
      if (row[i][j] == col[i][j])
        cout << max(row_max[i], col_max[j]) << " ";
      else if (row[i][j] < col[i][j])
        cout << max(row_max[i] + k, col_max[j]) << " ";
      else
        cout << max(row_max[i], col_max[j] + k) << " ";
    }
    cout << "\n";
  }
  return 0;
}
