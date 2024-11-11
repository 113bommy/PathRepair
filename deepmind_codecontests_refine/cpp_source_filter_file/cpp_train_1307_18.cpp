#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int n, m;
string a[60][60];
int ai, aj, ai1, aj1;
bool check() {
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      for (int i1 = 0; i1 < n - 2; i1++) {
        for (int j1 = 0; j1 < m - 2; j1++) {
          if (abs(i - i1) < 3 && (abs)(j - j1) < 3) continue;
          char mast = a[i][j][1];
          bool f1 = true;
          bool f2 = true;
          for (int q = i; q < i + 3; q++) {
            for (int x = j; x < j + 3; x++) {
              if (a[q][x][1] != mast) {
                f1 = false;
                break;
              }
            }
          }
          mast = a[i1][j1][1];
          for (int q = i1; q < i1 + 3; q++) {
            for (int x = j1; x < j1 + 3; x++) {
              if (a[q][x][1] != mast) {
                f2 = false;
                break;
              }
            }
          }
          map<char, int> u1, u2;
          if (f1 == false) {
            f1 = true;
            for (int q = i; q < i + 3; q++) {
              for (int x = j; x < j + 3; x++) {
                if (++u1[a[q][x][0]] > 1) {
                  f1 = false;
                  break;
                }
              }
            }
          }
          if (f2 == false) {
            f2 = false;
            for (int q = i1; q < i1 + 3; q++) {
              for (int x = j1; x < j1 + 3; x++) {
                if (++u2[a[q][x][0]] > 1) {
                  f2 = false;
                  break;
                }
              }
            }
          }
          if (f1 && f2) {
            ai = i;
            aj = j;
            ai1 = i1;
            aj1 = j1;
            return true;
          }
        }
      }
    }
  }
  return false;
}
int main() {
  int x1 = -1;
  int y1 = -1;
  int x2 = -1;
  int y2 = -1;
  string s = "23456789TJQKA";
  string t = "CDHS";
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      mp[s.substr(i, 1) + t.substr(j, 1)] = 1;
    }
  }
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string cur;
      cin >> cur;
      a[i][j] = cur;
      mp[cur] = 0;
      if (cur == "J1") {
        x1 = i;
        y1 = j;
      }
      if (cur == "J2") {
        x2 = i;
        y2 = j;
      }
    }
  }
  if (x1 == -1 && x2 == -1) {
    if (check()) {
      cout << "Solution exists." << endl;
      cout << "There are no jokers." << endl;
      cout << "Put the first square to (" << ai + 1 << ", " << aj + 1 << ")."
           << endl;
      cout << "Put the second square to (" << ai1 + 1 << ", " << aj1 + 1 << ")."
           << endl;
      return 0;
    } else {
      cout << "No solution.";
      return 0;
    }
  }
  if (x1 != -1 && x2 == -1) {
    for (int i = 0; i < 13; i++) {
      for (int j = 0; j < 4; j++) {
        if (mp[s.substr(i, 1) + t.substr(j, 1)] == 0 || s[i] == 'J') continue;
        a[x1][y1] = s.substr(i, 1) + t.substr(j, 1);
        if (check()) {
          cout << "Solution exists." << endl;
          cout << "Replace J1 with " << s.substr(i, 1) + t.substr(j, 1) << "."
               << endl;
          cout << "Put the first square to (" << ai + 1 << ", " << aj + 1
               << ")." << endl;
          cout << "Put the second square to (" << ai1 + 1 << ", " << aj1 + 1
               << ")." << endl;
          return 0;
        }
      }
    }
    cout << "No solution.";
    return 0;
  }
  if (x1 == -1 && x2 != -1) {
    for (int i = 0; i < 13; i++) {
      for (int j = 0; j < 4; j++) {
        if (mp[s.substr(i, 1) + t.substr(j, 1)] == 0 || s[i] == 'J') continue;
        a[x2][y2] = s.substr(i, 1) + t.substr(j, 1);
        if (check()) {
          cout << "Solution exists." << endl;
          cout << "Replace J2 with " << s.substr(i, 1) + t.substr(j, 1) << "."
               << endl;
          cout << "Put the first square to (" << ai + 1 << ", " << aj + 1
               << ")." << endl;
          cout << "Put the second square to (" << ai1 + 1 << ", " << aj1 + 1
               << ")." << endl;
          return 0;
        }
      }
    }
    cout << "No solution.";
    return 0;
  }
  vector<string> notused;
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      if (mp[s.substr(i, 1) + t.substr(j, 1)] == 1) {
        notused.push_back(s.substr(i, 1) + t.substr(j, 1));
      }
    }
  }
  if (x1 != -1 && x2 != -1) {
    for (int i = 0; i < notused.size(); i++) {
      for (int j = 0; j < notused.size(); j++) {
        if (i == j) continue;
        a[x1][y1] = notused[i];
        a[x2][y2] = notused[j];
        if (check()) {
          cout << "Solution exists." << endl;
          cout << "Replace J1 with " << notused[i] << " and J2 with "
               << notused[j] << "." << endl;
          cout << "Put the first square to (" << ai + 1 << ", " << aj + 1
               << ")." << endl;
          cout << "Put the second square to (" << ai1 + 1 << ", " << aj1 + 1
               << ")." << endl;
          return 0;
        }
      }
    }
    cout << "No solution." << endl;
  }
  return 0;
}
