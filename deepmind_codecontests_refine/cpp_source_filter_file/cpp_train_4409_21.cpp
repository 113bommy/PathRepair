#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> v(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  pair<int, int> v1;
  pair<int, int> v2;
  pair<int, int> v3;
  bool empty1 = false;
  bool empty2 = false;
  bool empty3 = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '*' && !empty1) {
        v1 = {i, j};
        empty1 = true;
      } else if (v[i][j] == '*' && !empty2) {
        v2 = {i, j};
        empty2 = true;
      } else if (v[i][j] == '*' && !empty3) {
        v3 = {i, j};
        empty3 = true;
      }
    }
  }
  int x = 0, y = 0;
  if (v1.first == v2.first) {
    x = v3.first;
  } else if (v1.first == v3.first) {
    x = v2.first;
  } else {
    x = v1.first;
  }
  if (v1.second == v2.second) {
    y = v3.second;
  } else if (v1.second == v3.second) {
    y = v2.second;
  } else {
    y = v2.second;
  }
  cout << x + 1 << " " << y + 1;
}
