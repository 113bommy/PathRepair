#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > res;
int a[1000][1000];
int main() {
  int p, m, n;
  cin >> n >> m >> p;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  }
  if (p == 0) {
    for (int i = 0; i < m - 1; ++i) {
      for (int j = i + 1; j < m; ++j) {
        bool added = false;
        for (int k = 0; k < n; ++k)
          if (a[k][i] > a[k][j]) {
            added = true;
            swap(a[k][i], a[k][j]);
          }
        if (added) res.push_back(make_pair(i + 1, j + 1));
      }
    }
  } else {
    for (int i = 0; i < m - 1; ++i) {
      for (int j = i + 1; j < m; ++j) {
        bool added = false;
        for (int k = 0; k < n; ++k)
          if (a[k][i] < a[k][j]) {
            added = true;
            swap(a[k][i], a[k][j]);
          }
        if (added) res.push_back(make_pair(j + 1, i + 1));
      }
    }
  }
  cout << res.size() << endl;
  for (vector<pair<int, int> >::iterator it = res.begin(); it != res.end();
       ++it)
    cout << (*it).first << ' ' << (*it).second << endl;
  return 0;
}
