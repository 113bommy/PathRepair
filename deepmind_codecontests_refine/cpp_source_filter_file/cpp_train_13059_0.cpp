#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  int n, m, i, j;
  cin >> n >> m;
  char second[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> second[i][j];
    }
  }
  string st = "wbw";
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      string cmp = "";
      int a = 0;
      if (m > j + 2) {
        map<char, int> mp;
        mp['A'] = 0;
        mp['B'] = 0;
        mp['C'] = 0;
        mp['D'] = 0;
        cmp += second[i][j];
        cmp += second[i][j + 1];
        cmp += second[i][j + 2];
        if (cmp == st) {
          if (i > 0) {
            mp[second[i - 1][j]] = 1;
            mp[second[i - 1][j + 1]] = 1;
            mp[second[i - 1][j + 2]] = 1;
          }
          if (j > 0) {
            mp[second[i][j - 1]] = 1;
          }
          if (m > j + 3) {
            mp[second[i][j + 3]] = 1;
          }
          char c = ' ';
          for (auto u : mp) {
            if ((u.first == 'A' || u.first == 'B' || u.first == 'C' ||
                 u.first == 'D') &&
                u.second == 0) {
              c = u.first;
              break;
            }
          }
          second[i][j] = c;
          second[i][j + 1] = c;
          second[i][j + 2] = c;
          a = 1;
        }
      }
      if (a == 0 && i + 2 < n) {
        map<char, int> mp;
        cmp = "";
        mp['A'] = 0;
        mp['B'] = 0;
        mp['C'] = 0;
        mp['D'] = 0;
        cmp += second[i][j];
        cmp += second[i + 1][j];
        cmp += second[i + 2][j];
        if (cmp == st) {
          if (j > 0) {
            mp[second[i][j - 1]] = 1;
            mp[second[i + 1][j - 1]] = 1;
            mp[second[i + 2][j - 1]] = 1;
          }
          if (j + 1 < n) {
            mp[second[i][j + 1]] = 1;
            mp[second[i + 1][j + 1]] = 1;
            mp[second[i + 1][j + 1]] = 1;
          }
          if (i > 0) {
            mp[second[i - 1][j]] = 1;
          }
          char c = ' ';
          for (auto u : mp) {
            if ((u.first == 'A' || u.first == 'B' || u.first == 'C' ||
                 u.first == 'D') &&
                u.second == 0) {
              c = u.first;
              break;
            }
          }
          second[i][j] = c;
          second[i + 1][j] = c;
          second[i + 2][j] = c;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (second[i][j] == 'b' || second[i][j] == 'w' || second[i][j] == ' ') {
        cout << "NO"
             << "\n";
        return 0;
      } else if (second[i][j] != '.') {
        second[i][j] = 'a' + (second[i][j] - 'A');
      }
    }
  }
  cout << "YES"
       << "\n";
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << second[i][j];
    }
    cout << "\n";
  }
  return 0;
}
