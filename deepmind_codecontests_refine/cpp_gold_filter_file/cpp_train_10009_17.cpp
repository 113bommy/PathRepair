#include <bits/stdc++.h>
const int mod = (int)1e9 + 7;
using namespace std;
template <class T>
void smin(T& a, T val) {
  if (a > val) a = val;
}
template <class T>
void smax(T& a, T val) {
  if (a < val) a = val;
}
const int N = (int)1e3 + 10;
int n, m, a[N][N];
vector<int> row[N], col[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      row[i].push_back(x);
      col[j].push_back(x);
      a[i][j] = x;
    }
  }
  for (int i = 0; i < n; ++i) {
    sort(row[i].begin(), row[i].end());
    ((row[i]).erase(unique((row[i]).begin(), (row[i]).end()), (row[i]).end()));
  }
  for (int i = 0; i < m; ++i) {
    sort(col[i].begin(), col[i].end());
    ((col[i]).erase(unique((col[i]).begin(), (col[i]).end()), (col[i]).end()));
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int curr1 = lower_bound(row[i].begin(), row[i].end(), a[i][j]) -
                  row[i].begin() + 1;
      int curr2 = lower_bound(col[j].begin(), col[j].end(), a[i][j]) -
                  col[j].begin() + 1;
      int x =
          (int)(row[i].size()) -
          (upper_bound(row[i].begin(), row[i].end(), a[i][j]) - row[i].begin());
      int y =
          (int)(col[j].size()) -
          (upper_bound(col[j].begin(), col[j].end(), a[i][j]) - col[j].begin());
      cout << max(curr1, curr2) + max(x, y) << ' ';
    }
    cout << '\n';
  }
  return 0;
}
