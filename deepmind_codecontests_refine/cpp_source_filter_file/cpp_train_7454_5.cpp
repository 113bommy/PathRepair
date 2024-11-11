#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> mp;
  map<char, int> np;
  int n, m;
  cin >> n >> m;
  char c[n + 1][m + 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  if (n % 3 != 0 && m % 3 != 0) {
    cout << "NO";
    return 0;
  }
  int flag = 0;
  if (n % 3 == 0) {
    for (int i = 0; i < n / 3; i++) {
      for (int j = 0; j < m; j++) {
        if (!mp[c[i][j]]) mp[c[i][j]] = 1;
        if (c[i][j] == c[i + n / 3][j] || c[i][j] == c[i + 2 * n / 3][j] ||
            mp[c[i + 2 * n / 3][j]] == 1 || mp[c[i + n / 3][j]] == 1) {
          flag = 1;
          break;
        }
      }
    }
    for (int i = n - 1; i >= 2 * n / 3; i--) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] == c[i - n / 3][j] || c[i][j] == c[i - 2 * n / 3][j]) {
          flag = 1;
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (c[i][j] != c[i][j - 1]) {
          flag = 1;
          break;
        }
      }
    }
  }
  if (flag == 1 && m % 3 != 0) {
    cout << "NO";
    return 0;
  } else if (flag == 0 && n % 3 == 0) {
    cout << "YES";
    return 0;
  } else {
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] != c[i - 1][j]) {
          cout << "NO";
          return 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m / 3; j++) {
        if (!np[c[i][j]]) np[c[i][j]] = 1;
        if (c[i][j] == c[i][j + m / 3] || c[i][j] == c[i][j + 2 * m / 3] ||
            np[c[i][j + 2 * m / 3]] == 1 || np[c[i][j + m / 3]] == 1) {
          cout << "NO";
          return 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j >= 2 * m / 3; j--) {
        if (c[i][j] == c[i][j - m / 3] || c[i][j] == c[i][j - 2 * m / 3]) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
  return 0;
}
