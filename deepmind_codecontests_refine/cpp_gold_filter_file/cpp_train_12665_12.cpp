#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<char> t;
  vector<int> t1;
  vector<vector<char> > map;
  vector<vector<int> > ans;
  int n, m;
  char c;
  int xm = 0, ym = 0, max = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) t1.push_back(0);
  for (int i = 0; i < n; i++) {
    t.clear();
    for (int j = 0; j < n; j++) {
      cin >> c;
      t.push_back(c);
    }
    t.push_back('#');
    ans.push_back(t1);
    map.push_back(t);
  }
  t.clear();
  for (int i = 0; i < n; i++) t.push_back('#');
  map.push_back(t);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (map[i][j] == '.') {
        bool hor = true, ver = true;
        for (int k = 0; k < m; k++)
          if (map[i][j + k] == '#') {
            hor = false;
            break;
          }
        for (int k = 0; k < m; k++)
          if (map[i + k][j] == '#') {
            ver = false;
            break;
          }
        if (hor == true)
          for (int k = 0; k < m; k++) ans[i][j + k]++;
        if (ver == true)
          for (int k = 0; k < m; k++) ans[i + k][j]++;
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (ans[i][j] > max) {
        max = ans[i][j];
        xm = i;
        ym = j;
      }
  cout << xm + 1 << " " << ym + 1;
}
