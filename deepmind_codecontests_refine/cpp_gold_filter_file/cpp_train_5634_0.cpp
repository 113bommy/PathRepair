#include <bits/stdc++.h>
using namespace std;
int n, m, result[1000][1000];
char arr[1000][1000];
bool checkGrid(int i, int j) {
  for (int l = i; l <= i + 2; l++) {
    for (int k = j; k <= j + 2; k++) {
      if (arr[l][k] != '#' && !(l == i + 1 && k == j + 1)) return false;
    }
  }
  return true;
}
bool checkResult() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '#' && result[i][j] == 0) return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      result[i][j] = 0;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '#') {
        if (i + 2 < n && j + 2 < m) {
          bool check = checkGrid(i, j);
          if (check) {
            for (int l = i; l <= i + 2; l++) {
              for (int k = j; k <= j + 2; k++) {
                if (!(l == i + 1 && k == j + 1)) result[l][k] = 1;
              }
            }
          }
        }
      }
    }
  if (checkResult())
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
