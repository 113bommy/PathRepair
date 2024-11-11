#include <bits/stdc++.h>
using namespace std;
int n, m;
bool check(vector<vector<int>> &a, int x, int y) {
  for (int i = 0; i < m; i++) {
    if (a[i][0] != x && a[i][0] != y && a[i][1] != x && a[i][1] != y)
      return false;
  }
  return true;
}
int main() {
  cin >> n >> m;
  int i, j, k;
  vector<vector<int>> a(m);
  for (i = 0; i < m; i++) {
    cin >> j >> k;
    a[i].push_back(j);
    a[i].push_back(k);
  }
  vector<int> v;
  for (i = 0; i < m - 1; i++) {
    if (a[0][0] != a[i + 1][0] && a[0][0] != a[i + 1][1] &&
        a[0][1] != a[i + 1][0] && a[0][1] != a[i + 1][1]) {
      v.push_back(a[i][0]);
      v.push_back(a[i][1]);
      v.push_back(a[i + 1][0]);
      v.push_back(a[i + 1][1]);
      break;
    }
  }
  if (v.size() == 0) {
    cout << "YES" << endl;
    return 0;
  }
  for (i = 0; i < v.size(); i++) {
    for (j = i + 1; j < v.size(); j++) {
      if (check(a, v[i], v[j])) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
