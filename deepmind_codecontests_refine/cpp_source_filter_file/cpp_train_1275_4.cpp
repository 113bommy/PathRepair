#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[51][51];
bool mark[51][51] = {false};
void dfs(char arr[51][51], int i, int j) {
  if ((arr[i][j] == '#') || (arr[i][j] == 'B'))
    return;
  else if (mark[i][j] == true) {
    return;
  } else {
    mark[i][j] = true;
    if (j - 1 >= 0) dfs(arr, i, j - 1);
    if (j + 1 < m) dfs(arr, i, j + 1);
    if (i + 1 < n) dfs(arr, i + 1, j);
    if (i - 1 >= 0) dfs(arr, i - 1, j);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<pair<int, int>> good;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        cin >> arr[i][j];
        mark[i][j] = false;
        if (arr[i][j] == 'G') good.push_back(make_pair(i, j));
      }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (arr[i][j] == 'B') {
          if (j - 1 >= 0) {
            if (arr[i][j - 1] == 'G') {
              cout << "NO" << endl;
              goto last;
            } else if (arr[i][j - 1] == '.') {
              arr[i][j - 1] = '#';
            }
          }
          if (j + 1 < m) {
            if (arr[i][j + 1] == 'G') {
              cout << "NO" << endl;
              goto last;
            } else if (arr[i][j + 1] == '.') {
              arr[i][j + 1] = '#';
            }
          }
          if (i + 1 < n) {
            if (arr[i + 1][j] == 'G') {
              cout << "NO" << endl;
              goto last;
            } else if (arr[i + 1][j] == '.') {
              arr[i + 1][j] = '#';
            }
          }
          if (i - 1 >= 0) {
            if (arr[i - 1][j] == 'G') {
              cout << "NO" << endl;
              goto last;
            } else if (arr[i - 1][j] == '.') {
              arr[i - 1][j] = '#';
            }
          }
        }
      }
    dfs(arr, n - 1, m - 1);
    for (int k = 0; k < good.size(); ++k) {
      int i = good[k].first, j = good[k].second;
      int check = 0;
      if (j - 1 >= 0) {
        if (mark[i][j - 1] == true) check = 1;
      }
      if (j + 1 < m) {
        if (mark[i][j + 1] == true) check = 1;
      }
      if (i + 1 < n)
        if (mark[i + 1][j] == true) check = 1;
      if (i - 1 >= 0)
        if (mark[i][j - 1] == true) check = 1;
      if (check == 0) {
        cout << "NO" << endl;
        goto last;
      }
    }
    cout << "YES" << endl;
  last:;
  }
  return 0;
}
