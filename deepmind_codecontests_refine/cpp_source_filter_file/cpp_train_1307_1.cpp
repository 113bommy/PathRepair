#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
pair<int, int> a[120][120];
bool use[100][100];
pair<int, int> J[5];
bool u1[120], u2[120];
vector<pair<int, int> > v;
pair<pair<int, int>, pair<int, int> > res;
char f1(int k) {
  if (k < 10)
    return '0' + k;
  else if (k == 10)
    return 'T';
  else if (k == 11)
    return 'J';
  else if (k == 12)
    return 'Q';
  else if (k == 13)
    return 'K';
  else if (k == 14)
    return 'A';
  return 'A';
}
char f2(int k) {
  if (k == 0) return 'C';
  if (k == 1) return 'D';
  if (k == 2) return 'H';
  if (k == 3) return 'S';
  return 'S';
}
pair<pair<int, int>, pair<int, int> > f() {
  memset(u1, 0, sizeof(u1));
  memset(u2, 0, sizeof(u2));
  v.clear();
  for (int i = 0; i <= n - 3; i++)
    for (int j = 0; j <= m - 3; j++) {
      memset(u1, 0, sizeof(u1));
      memset(u2, 0, sizeof(u2));
      bool ok1, ok2;
      ok1 = ok2 = true;
      u2[a[i][j].second] = true;
      for (int t = 0; t < 3; t++)
        for (int l = 0; l < 3; l++) {
          if (u1[a[i + t][j + l].first]) ok1 = false;
          if (a[i + t][j + l].second != a[i][j].second) ok2 = false;
          u1[a[i + t][j + l].first] = true;
        }
      if (ok1 || ok2) v.push_back(make_pair(i, j));
    }
  for (int i = 0; i < v.size(); i++)
    for (int j = i + 1; j < v.size(); j++)
      if (abs(v[i].first - v[j].first) > 2 ||
          abs(v[i].second - v[j].second) > 2)
        return make_pair(v[i], v[j]);
  return make_pair(make_pair(-1, -1), make_pair(-1, -1));
}
int main() {
  memset(use, 0, sizeof(use));
  cin >> n >> m;
  int col = 0;
  J[0].first = -1;
  J[1].first = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> s;
      if (s[0] >= '2' && s[0] <= '9')
        a[i][j].first = s[0] - '0';
      else if (s[0] == 'T')
        a[i][j].first = 10;
      else if (s[0] == 'J' && s[1] != '1' && s[1] != '2')
        a[i][j].first = 11;
      else if (s[0] == 'Q')
        a[i][j].first = 12;
      else if (s[0] == 'K')
        a[i][j].first = 13;
      else if (s[0] == 'A')
        a[i][j].first = 14;
      else {
        a[i][j].first = s[1] - '0' - 1;
        col++;
        J[a[i][j].first].first = i;
        J[a[i][j].first].second = j;
      }
      if (s[1] == 'C') a[i][j].second = 0;
      if (s[1] == 'D') a[i][j].second = 1;
      if (s[1] == 'H') a[i][j].second = 2;
      if (s[1] == 'S') a[i][j].second = 3;
      if (a[i][j].first > 1) use[a[i][j].first][a[i][j].second] = true;
    }
  if (col == 0) {
    res = f();
    if (res.first.first != -1) {
      cout << "Solution exists." << endl << "There are no jokers." << endl;
      cout << "Put the first square to (" << res.first.first + 1 << ", "
           << res.first.second + 1 << ")." << endl;
      cout << "Put the second square to (" << res.second.first + 1 << ", "
           << res.second.second + 1 << ")." << endl;
      return 0;
    } else {
      cout << "No solution.";
      return 0;
    }
  } else if (col == 1) {
    int t = 0;
    if (J[0].first == -1) t = 1;
    for (int i = 2; i < 15; i++)
      for (int j = 0; j < 4; j++)
        if (!use[i][j]) {
          a[J[t].first][J[t].second] = make_pair(i, j);
          res = f();
          if (res.first.first != -1) {
            cout << "Solution exists." << endl
                 << "Replace J" << t << " with " << f1(i) << f2(j) << "."
                 << endl;
            cout << "Put the first square to (" << res.first.first + 1 << ", "
                 << res.first.second + 1 << ")." << endl;
            cout << "Put the second square to (" << res.second.first + 1 << ", "
                 << res.second.second + 1 << ")." << endl;
            return 0;
          }
        }
  } else if (col == 2) {
    for (int i = 2; i < 15; i++)
      for (int j = 0; j < 4; j++)
        if (!use[i][j]) {
          use[i][j] = true;
          a[J[0].first][J[0].second] = make_pair(i, j);
          for (int t = 2; t < 15; t++)
            for (int l = 0; l < 4; l++)
              if (!use[t][l]) {
                a[J[1].first][J[1].second] = make_pair(t, l);
                res = f();
                if (res.first.first != -1) {
                  cout << "Solution exists." << endl
                       << "Replace J1"
                       << " with " << f1(i) << f2(j) << " and J2 with " << f1(t)
                       << f2(l) << "." << endl;
                  cout << "Put the first square to (" << res.first.first + 1
                       << ", " << res.first.second + 1 << ")." << endl;
                  cout << "Put the second square to (" << res.second.first + 1
                       << ", " << res.second.second + 1 << ")." << endl;
                  return 0;
                }
              }
          use[i][j] = false;
        }
  }
  cout << "No solution.";
  return 0;
}
