#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long n, m;
int a[102][102];
int maxl[102], minl[102];
int maxc[102], minc[102];
vector<pair<int, int> > v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (j == 1)
        minl[i] = maxl[i] = a[i][j];
      else
        minl[i] = min(minl[i], a[i][j]), maxl[i] = max(maxl[i], a[i][j]);
    }
  for (int j = 1; j <= m; ++j)
    for (int i = 1; i <= n; ++i) {
      if (i == 1)
        minc[j] = maxc[j] = a[i][j];
      else
        minc[j] = min(minc[j], a[i][j]), maxc[i] = max(maxc[j], a[i][j]);
    }
  if (n >= m) {
    for (int i = 1; i <= n; ++i) {
      int minx = minl[i];
      for (int j = 1; j <= m; ++j) minx = min(minx, a[i][j] - minc[j]);
      for (int q = 1; q <= minx; ++q) v.push_back({1, i});
      for (int j = 1; j <= m; ++j) a[i][j] -= minx;
    }
    for (int j = 1; j <= m; ++j) {
      int maxi = 0;
      int mini = 1e9;
      for (int i = 1; i <= n; ++i) {
        maxi = max(maxi, a[i][j]);
        mini = min(mini, a[i][j]);
      }
      if (maxi == mini) {
        for (int i = 1; i <= n; ++i) a[i][j] = 0;
        for (int q = 1; q <= maxi; ++q) v.push_back({2, j});
      } else {
        cout << -1;
        return 0;
      }
    }
  } else {
    for (int i = 1; i <= m; ++i) {
      int minx = minc[i];
      for (int j = 1; j <= n; ++j) minx = min(minx, a[j][i] - minl[j]);
      for (int q = 1; q <= minx; ++q) v.push_back({2, i});
      for (int j = 1; j <= n; ++j) a[j][i] -= minx;
    }
    for (int j = 1; j <= n; ++j) {
      int maxi = 0;
      int mini = 1e9;
      for (int i = 1; i <= m; ++i) {
        maxi = max(maxi, a[j][i]);
        mini = min(mini, a[j][i]);
      }
      if (maxi == mini) {
        for (int i = 1; i <= m; ++i) a[j][i] = 0;
        for (int q = 1; q <= maxi; ++q) v.push_back({2, j});
      } else {
        cout << -1;
        return 0;
      }
    }
  }
  cout << v.size() << '\n';
  for (int i = 0; i < v.size(); ++i) {
    if (v[i].first == 1)
      cout << "row ";
    else
      cout << "col ";
    cout << v[i].second << '\n';
  }
  return 0;
}
