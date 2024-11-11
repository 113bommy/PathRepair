#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main() {
  int i;
  vector<pair<int, int> > v(3), v1;
  for (i = 0; i < 3; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  v1.push_back(make_pair(v[0].first, v[0].second));
  a[v[0].first][v[0].second] = 1;
  int x = v[0].first;
  while (x < v[1].first) {
    x++;
    v1.push_back(make_pair(x, v[0].second));
    a[x][v[0].second] = 1;
  }
  int y = v[0].second;
  if (y < v[1].second) {
    while (y < v[1].second) {
      y++;
      v1.push_back(make_pair(x, y));
      a[x][y] = 1;
    }
  } else {
    while (y > v[1].second) {
      y--;
      v1.push_back(make_pair(x, y));
      a[x][y] = 1;
    }
  }
  if (y < v[2].second) {
    while (y < v[2].second) {
      y++;
      if (a[x][y] == 0) {
        v1.push_back(make_pair(x, y));
      }
      a[x][y] = 1;
    }
  } else {
    while (y > v[2].second) {
      y--;
      if (a[x][y] == 0) {
        v1.push_back(make_pair(x, y));
      }
      a[x][y] = 1;
    }
  }
  while (x < v[2].first) {
    x++;
    if (a[x][y] == 0) {
      v1.push_back(make_pair(x, y));
    }
    a[x][y] = 1;
  }
  int n = v1.size();
  cout << n << "\n";
  for (i = 0; i < n; i++) {
    cout << v1[i].first << " " << v1[i].second << "\n";
  }
}
