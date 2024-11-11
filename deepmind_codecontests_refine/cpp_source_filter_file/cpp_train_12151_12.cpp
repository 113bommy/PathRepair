#include <bits/stdc++.h>
using namespace std;
int n, m;
bool isValid(int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < n) return true;
  return false;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  string arr[n];
  int i, j;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (arr[i][j] > '0' && arr[i][j] < '9') {
        int cnt = 0;
        if (isValid(i - 1, j - 1) && arr[i - 1][j - 1] == '*') cnt++;
        if (isValid(i, j - 1) && arr[i][j - 1] == '*') cnt++;
        if (isValid(i + 1, j - 1) && arr[i + 1][j - 1] == '*') cnt++;
        if (isValid(i - 1, j) && arr[i - 1][j] == '*') cnt++;
        if (isValid(i + 1, j) && arr[i + 1][j] == '*') cnt++;
        if (isValid(i - 1, j + 1) && arr[i - 1][j + 1] == '*') cnt++;
        if (isValid(i, j + 1) && arr[i][j + 1] == '*') cnt++;
        if (isValid(i + 1, j + 1) && arr[i + 1][j + 1] == '*') cnt++;
        if ((cnt + '0') != arr[i][j]) {
          cout << "NO";
          return 0;
        }
      }
      if (arr[i][j] == '.') {
        int cnt = 0;
        if (isValid(i - 1, j - 1) && arr[i - 1][j - 1] == '*') cnt++;
        if (isValid(i, j - 1) && arr[i][j - 1] == '*') cnt++;
        if (isValid(i + 1, j - 1) && arr[i + 1][j - 1] == '*') cnt++;
        if (isValid(i - 1, j) && arr[i - 1][j] == '*') cnt++;
        if (isValid(i + 1, j) && arr[i + 1][j] == '*') cnt++;
        if (isValid(i - 1, j + 1) && arr[i - 1][j + 1] == '*') cnt++;
        if (isValid(i, j + 1) && arr[i][j + 1] == '*') cnt++;
        if (isValid(i + 1, j + 1) && arr[i + 1][j + 1] == '*') cnt++;
        if (cnt) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
  return 0;
}
