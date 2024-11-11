#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > v(m);
  int x;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> x;
      v[i].push_back(x);
    }
  }
  vector<int> color(n + 1, 0);
  color[v[0][0]] = 1;
  color[v[0][1]] = 2;
  color[v[0][2]] = 3;
  int c2, c1, c0, p, q;
  for (int i = 1; i < m; i++) {
    c0 = color[v[i][0]];
    c1 = color[v[i][1]];
    c2 = color[v[i][2]];
    if (c1 == 0 && c2 == 0 && c0 == 0) {
      color[v[i][0]] = 1;
      color[v[i][1]] = 2;
      color[v[i][2]] = 3;
    } else if (c0 != 0 && c1 == 0 && c2 == 0) {
      if (c0 == 2) {
        color[v[i][1]] = 1;
        color[v[i][2]] = 3;
      } else {
        color[v[i][1]] = (6 - c0) / 2;
        color[v[i][2]] = 6 - color[v[i][0]] - color[v[i][1]];
      }
    } else if (c0 == 0 && c1 != 0 && c2 == 0) {
      if (c1 == 2) {
        color[v[i][0]] = 1;
        color[v[i][2]] = 3;
      } else {
        color[v[i][0]] = (6 - c1) / 2;
        color[v[i][2]] = 6 - color[v[i][0]] - color[v[i][1]];
      }
    } else if (c0 == 0 && c1 == 0 && c2 != 0) {
      if (c2 == 2) {
        color[v[i][1]] = 1;
        color[v[i][0]] = 3;
      } else {
        color[v[i][1]] = (6 - c2) / 2;
        color[v[i][0]] = 6 - color[v[i][2]] - color[v[i][1]];
      }
    } else if (c0 != 0 && c1 != 0 && c2 == 0) {
      color[v[i][2]] = 6 - c0 - c1;
    } else if (c0 != 0 && c1 == 0 && c2 != 0) {
      color[v[i][1]] = 6 - c0 - c2;
    } else if (c0 == 0 && c1 != 0 && c2 != 0) {
      color[v[i][0]] = 6 - c1 - c2;
    } else {
      color[v[i][2]] = c2;
      color[v[i][1]] = c1;
      color[v[i][0]] = c0;
    }
  }
  for (int i = 1; i <= n; i++) cout << color[i] << " ";
}
