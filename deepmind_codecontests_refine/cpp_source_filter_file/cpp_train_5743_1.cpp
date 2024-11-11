#include <bits/stdc++.h>
using namespace std;
int n, m;
int rowcheck(int n, int m, vector<vector<int> > a) {
  int flag = 0;
  for (int i = 0; i < n; i++) {
    int k = a[i][0];
    for (int j = 1; j < m; j++) {
      if (a[i][j] <= k) {
        flag = 1;
        break;
      } else {
        k = a[i][j];
      }
    }
    if (flag) break;
  }
  return flag;
}
int colcheck(int n, int m, vector<vector<int> > a) {
  int flag = 0;
  for (int i = 0; i < m; i++) {
    int k = a[0][i];
    for (int j = 1; j < n; j++) {
      if (a[j][i] <= k) {
        flag = 1;
        break;
      } else {
        k = a[j][i];
      }
    }
    if (flag) break;
  }
  return flag;
}
int main() {
  cin >> n >> m;
  vector<vector<int> > a(n);
  vector<vector<int> > b(n);
  vector<vector<int> > c(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k;
      cin >> k;
      a[i].push_back(k);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k;
      cin >> k;
      b[i].push_back(k);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i].push_back(min(a[i][j], b[i][j]));
      b[i][j] = max(a[i][j], b[i][j]);
    }
  }
  if (rowcheck(n, m, c) == 0 and colcheck(n, m, c) == 0 and
      rowcheck(n, m, b) == 0 and colcheck(n, m, b) == 0)
    cout << "possible" << endl;
  else
    cout << "impossible" << endl;
  return 0;
}
