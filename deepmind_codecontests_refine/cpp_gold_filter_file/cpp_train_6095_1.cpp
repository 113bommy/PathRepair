#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[66][66];
set<int> X, Y;
vector<pair<int, int>> v;
int main() {
  cin >> n;
  m = n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> c[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (c[i][j] == '1') {
        v.push_back({i, j});
        X.insert(i);
        Y.insert(j);
      }
  if (X.size() != 2 || Y.size() != 2) {
    cout << "no" << endl;
    return 0;
  }
  for (int i = 0; i < v.size(); i++)
    for (int j = 0; j < i; j++) {
      if (v[i].first == v[j].first) {
        for (int k = 1 + min(v[i].second, v[j].second);
             k < max(v[i].second, v[j].second); k++)
          if (c[v[i].first][k] != '2') {
            cout << "no" << endl;
            return 0;
          }
      } else if (v[i].second == v[j].second) {
        for (int k = 1 + min(v[i].first, v[j].first);
             k < max(v[i].first, v[j].first); k++)
          if (c[k][v[i].second] != '2') {
            cout << "no" << endl;
            return 0;
          }
      }
    }
  int minX = *X.begin();
  X.erase(minX);
  int maxX = *X.begin();
  int minY = *Y.begin();
  Y.erase(minY);
  int maxY = *Y.begin();
  for (int i = minX + 1; i < maxX; i++)
    for (int j = minY + 1; j < maxY; j++)
      if (c[i][j] != '4') {
        cout << "no" << endl;
        return 0;
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (minX <= i && i <= maxX && minY <= j && j <= maxY) continue;
      if (c[i][j] != '0') {
        cout << "no" << endl;
        return 0;
      }
    }
  if ((maxX - minX - 1) * (maxY - minY - 1) == 0)
    cout << "no" << endl;
  else
    cout << "yes" << endl;
  return 0;
}
