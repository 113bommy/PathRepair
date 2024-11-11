#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[20][20];
map<string, bool> mp;
int j1x = -1, j1y = -1, j2x = -1, j2y = -1;
vector<string> v;
string sui = "CDHS";
string ran = "23456789TJQKA";
inline bool ok(int x, int y) {
  set<char> st;
  bool fl = 1;
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      st.insert(s[i][j][0]);
      if (s[i][j][1] != s[x][y][1]) fl = 0;
    }
  }
  if (!fl && st.size() != 9) return 0;
  return 1;
}
void outj12(int i1, int j1, int i2, int j2, int tr1, int tr2) {
  cout << "Solution exists.\n";
  cout << "Replace J1 with " << v[tr1] << " and J2 with " << v[tr2] << ".\n";
  cout << "Put the first square to (" << i1 + 1 << ", " << j1 + 1 << ").\n";
  cout << "Put the second square to (" << i2 + 1 << ", " << j2 + 1 << ").\n";
  exit(0);
}
void goj12() {
  for (int tr1 = 0; tr1 < v.size(); tr1++) {
    for (int tr2 = 0; tr2 < v.size(); tr2++) {
      if (tr1 == tr2) continue;
      s[j1x][j1y] = v[tr1];
      s[j2x][j2y] = v[tr2];
      for (int i1 = 0; i1 < n - 2; i1++) {
        for (int j1 = 0; j1 < m - 2; j1++) {
          for (int i2 = 0; i2 < n - 2; i2++) {
            for (int j2 = 0; j2 < m - 2; j2++) {
              if (make_pair(i1, j1) >= make_pair(i2, j2)) continue;
              if (abs(i2 - i1) < 3 && abs(j2 - j1) < 3) continue;
              if (ok(i1, j1) && ok(i2, j2)) outj12(i1, j1, i2, j2, tr1, tr2);
            }
          }
        }
      }
    }
  }
  cout << "No solution.\n";
  exit(0);
}
void outj1(int i1, int j1, int i2, int j2, int tr1) {
  cout << "Solution exists.\n";
  cout << "Replace J1 with " << v[tr1] << ".\n";
  cout << "Put the first square to (" << i1 + 1 << ", " << j1 + 1 << ").\n";
  cout << "Put the second square to (" << i2 + 1 << ", " << j2 + 1 << ").\n";
  exit(0);
}
void goj1() {
  for (int tr1 = 0; tr1 < v.size(); tr1++) {
    s[j1x][j1y] = v[tr1];
    for (int i1 = 0; i1 < n - 2; i1++) {
      for (int j1 = 0; j1 < m - 2; j1++) {
        for (int i2 = 0; i2 < n - 2; i2++) {
          for (int j2 = 0; j2 < m - 2; j2++) {
            if (make_pair(i1, j1) >= make_pair(i2, j2)) continue;
            if (abs(i2 - i1) < 3 && abs(j2 - j1) < 3) continue;
            if (ok(i1, j1) && ok(i2, j2)) outj1(i1, j1, i2, j2, tr1);
          }
        }
      }
    }
  }
  cout << "No solution.\n";
  exit(0);
}
void outj2(int i1, int j1, int i2, int j2, int tr2) {
  cout << "Solution exists.\n";
  cout << "Replace J2 with " << v[tr2] << ".\n";
  cout << "Put the first square to (" << i1 + 1 << ", " << j1 + 1 << ").\n";
  cout << "Put the second square to (" << i2 + 1 << ", " << j2 + 1 << ").\n";
  exit(0);
}
void goj2() {
  for (int tr2 = 0; tr2 < v.size(); tr2++) {
    s[j2x][j2y] = v[tr2];
    for (int i1 = 0; i1 < n - 2; i1++) {
      for (int j1 = 0; j1 < m - 2; j1++) {
        for (int i2 = 0; i2 < n - 2; i2++) {
          for (int j2 = 0; j2 < m - 2; j2++) {
            if (make_pair(i1, j1) >= make_pair(i2, j2)) continue;
            if (abs(i2 - i1) < 3 && abs(j2 - j1) < 3) continue;
            if (ok(i1, j1) && ok(i2, j2)) outj2(i1, j1, i2, j2, tr2);
          }
        }
      }
    }
  }
  cout << "No solution.\n";
  exit(0);
}
void out(int i1, int j1, int i2, int j2) {
  cout << "Solution exists.\n";
  cout << "There are no jokers.\n";
  cout << "Put the first square to (" << i1 + 1 << ", " << j1 + 1 << ").\n";
  cout << "Put the second square to (" << i2 + 1 << ", " << j2 + 1 << ").\n";
  exit(0);
}
void go() {
  for (int i1 = 0; i1 < n - 2; i1++) {
    for (int j1 = 0; j1 < m - 2; j1++) {
      for (int i2 = 0; i2 < n - 2; i2++) {
        for (int j2 = 0; j2 < m - 2; j2++) {
          if (make_pair(i1, j1) >= make_pair(i2, j2)) continue;
          if (abs(i2 - i1) < 3 && abs(j2 - j1) < 3) continue;
          if (ok(i1, j1) && ok(i2, j2)) out(i1, j1, i2, j2);
        }
      }
    }
  }
  cout << "No solution.\n";
  exit(0);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
      if (s[i][j][0] != 'J' || !isdigit(s[i][j][1])) {
        mp[s[i][j]] = 1;
        continue;
      }
      if (s[i][j][1] == '1') {
        j1x = i;
        j1y = j;
      } else {
        j2x = i;
        j2y = j;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      string ss = "  ";
      ss[0] = ran[j];
      ss[1] = sui[i];
      if (!mp[ss]) v.push_back(ss);
    }
  }
  if (j1x != -1 && j2x == -1)
    goj1();
  else if (j1x == -1 && j2x != -1)
    goj2();
  else if (j1x != -1 && j2x != -1)
    goj12();
  else
    go();
  return 0;
}
