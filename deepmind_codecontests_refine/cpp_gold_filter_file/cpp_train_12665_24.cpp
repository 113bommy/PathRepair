#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<vector<int> > vec(n, vector<int>(n, 0));
  vector<vector<int> > count(n, vector<int>(n, 0));
  char ch;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> ch;
      if (ch == '.') vec[i][j] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n - k; ++j) {
      if (vec[i][j] == 1) {
        int flag = 0;
        for (int z = 0; z < k; ++z)
          if (vec[i][j + z] != 1) flag = 1;
        for (int z = 0; z < k and !flag; ++z) count[i][j + z]++;
      }
    }
  }
  for (int i = 0; i <= n - k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (vec[i][j] == 1) {
        int flag = 0;
        for (int z = 0; z < k; ++z)
          if (vec[i + z][j] != 1) flag = 1;
        for (int z = 0; z < k and !flag; ++z) count[i + z][j]++;
      }
    }
  }
  int max = -2, x = 1, y = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (count[i][j] > max) max = count[i][j], x = i + 1, y = j + 1;
    }
  }
  cout << x << " " << y << '\n';
  return 0;
}
