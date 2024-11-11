#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  int rw[n][m], clm[n][m], mxrw[n], mxclm[m];
  for (int j = 0; j < m; j++) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = make_pair(a[i][j], i);
    }
    sort(v.begin(), v.end());
    int k = 1;
    for (int i = 0; i < n; i++) {
      if (i and v[i].first != v[i - 1].first) k++;
      clm[v[i].second][j] = k;
    }
    mxclm[j] = k;
  }
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> v(m);
    for (int j = 0; j < m; j++) {
      v[j] = make_pair(a[i][j], j);
    }
    sort(v.begin(), v.end());
    int k = 1;
    for (int j = 0; j < m; j++) {
      if (j and v[j].first != v[j - 1].first) k++;
      rw[i][v[j].second] = k;
    }
    mxrw[i] = k;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int y = mxrw[i], x = mxclm[j];
      if (rw[i][j] > clm[i][j])
        x += rw[i][j] - clm[i][j];
      else
        y += clm[i][j] - rw[i][j];
      cout << max(x, y) << " ";
    }
    cout << endl;
  }
  return 0;
}
