#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int tab[n][m];
  int arr[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) arr[i][j] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) tab[i][j] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char a;
      cin >> a;
      if (a == '*') arr[i][j] = 1;
    }
  }
  vector<pair<pair<int, int>, int> > v;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (arr[i][j] == 1) {
        int r = 1, d = 0, d2 = 0, d3;
        while (r + i < n && i - r >= 0) {
          if (arr[i + r][j] == 1 && arr[i - r][j] == 1)
            d++;
          else
            break;
          r++;
        }
        r = 1;
        while (r + j < m && j - r >= 0) {
          if (arr[i][j + r] == 1 && arr[i][j - r] == 1)
            d2++;
          else
            break;
          r++;
        }
        d3 = min(d, d2);
        if (d3 == 0) continue;
        v.push_back(make_pair(make_pair(i, j), d3));
        for (int k = i - d3; k <= i + d3; k++) tab[k][j] = 1;
        for (int k = j - d3; k <= j + d3; k++) tab[i][k] = 1;
      }
    }
  }
  int bo = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (arr[i][j] == 1 && tab[i][j] == 0) {
        cout << "-1\n";
        return 0;
      }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    pair<int, int> a = v[i].first;
    int b = v[i].second, a2 = a.first, b2 = a.second;
    cout << a2 + 1 << " " << b2 + 1 << " " << b << endl;
  }
}
