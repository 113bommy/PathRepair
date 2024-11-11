#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  vector<vector<int> > v(5, vector<int>(5));
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (v[i][j] == 1) {
        x = i + 1;
        y = i + 2;
      }
    }
  }
  cout << abs(3 - x) + abs(3 - y);
  return 0;
}
