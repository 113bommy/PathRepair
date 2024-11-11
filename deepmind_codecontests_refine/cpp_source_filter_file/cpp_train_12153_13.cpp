#include <bits/stdc++.h>
using namespace std;
bool checkempty(vector<vector<char>> &a, int i, int j) {
  if (i - 1 >= 0) {
    if (a[i - 1][j] == '*') {
      return false;
    }
  }
  if (i + 1 < a.size()) {
    if (a[i + 1][j] == '*') {
      return false;
    }
  }
  if (j - 1 >= 0) {
    if (a[i][j - 1] == '*') {
      return false;
    }
  }
  if (j + 1 < a[0].size()) {
    if (a[i][j + 1] == '*') {
      return false;
    }
  }
  if (i - 1 >= 0 && (j + 1 < a[0].size())) {
    if (a[i - 1][j + 1] == '*') {
      return false;
    }
  }
  if (i + 1 < a.size() && (j + 1 < a[0].size())) {
    if (a[i + 1][j + 1] == '*') {
      return false;
    }
  }
  if (i + 1 < a.size() && (j - 1 >= 0)) {
    if (a[i + 1][j - 1] == '*') {
      return false;
    }
  }
  if (i - 1 >= 0 && (j - 1 >= 0)) {
    if (a[i - 1][j - 1] == '*') {
      return false;
    }
  }
  return true;
}
bool checkK(vector<vector<char>> &a, int i, int j, int k) {
  int cb = 0;
  if (i - 1 >= 0) {
    if (a[i - 1][j] == '*') {
      cb++;
    }
  }
  if (i + 1 < a.size()) {
    if (a[i + 1][j] == '*') {
      cb++;
    }
  }
  if (j - 1 >= 0) {
    if (a[i][j - 1] == '*') {
      cb++;
    }
  }
  if (j + 1 < a[0].size()) {
    if (a[i][j + 1] == '*') {
      cb++;
    }
  }
  if (i - 1 >= 0 && (j + 1 < a[0].size())) {
    if (a[i - 1][j + 1] == '*') {
      cb++;
    }
  }
  if (i + 1 < a.size() && (j + 1 < a[0].size())) {
    if (a[i + 1][j + 1] == '*') {
      cb++;
    }
  }
  if (i + 1 < a.size() && (j - 1 >= 0)) {
    if (a[i + 1][j - 1] == '*') {
      cb++;
    }
  }
  if (i - 1 >= 0 && (j - 1 >= 0)) {
    if (a[i - 1][j - 1] == '*') {
      cb++;
    }
  }
  if (cb == k) {
    return true;
  }
  return false;
}
void solver() {
  long long int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        if (!checkempty(a, i, j)) {
          cout << "NO\n";
          exit(0);
        }
      } else if (a[i][j] == '*') {
        continue;
      } else {
        int k = a[i][j] - 48;
        if (!checkK(a, i, j, k)) {
          cout << "N0\n";
          exit(0);
        }
      }
    }
  }
  cout << "YES\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solver();
  }
  return 0;
}
