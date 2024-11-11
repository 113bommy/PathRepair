#include <bits/stdc++.h>
using namespace std;
template <typename TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << " = " << h << "\n";
}
template <typename TH, typename... TA>
void _dbg(const char* sdbg, TH h, TA... t) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << " = " << h << ",";
  _dbg(sdbg + 1, t...);
}
const int N = 17 + 2;
const string YES = "Solution exists.";
const string NO = "No solution.";
int n, m;
string a[N][N];
bool b[N][N];
bool CheckPos(int x, int y) {
  map<char, bool> mark;
  bool hasSameRank = false;
  for (int i = x; i <= x + 2; ++i) {
    for (int j = y; j <= y + 2; ++j) {
      if (mark.count(a[i][j][0])) {
        hasSameRank = true;
        break;
      }
      mark[a[i][j][0]] = true;
    }
  }
  if (!hasSameRank) {
    return true;
  }
  mark.clear();
  for (int i = x; i <= x + 2; ++i) {
    for (int j = y; j <= y + 2; ++j) {
      mark[a[i][j][1]] = true;
    }
  }
  return mark.size() == 1;
}
vector<pair<int, int>> Check() {
  vector<pair<int, int>> res;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      b[i][j] = false;
    }
  }
  for (int i = 1; i <= n - 2; ++i) {
    for (int j = 1; j <= m - 2; ++j) {
      if (CheckPos(i, j)) {
        b[i][j] = true;
      }
    }
  }
  for (int i1 = 1; i1 <= n - 2; ++i1) {
    for (int j1 = 1; j1 <= m - 2; ++j1) {
      if (b[i1][j1]) {
        for (int i2 = 1; i2 <= n - 2; ++i2) {
          for (int j2 = 1; j2 <= n - 2; ++j2) {
            if (b[i2][j2]) {
              int x = max(i1, i2), u = min(i1 + 2, i2 + 2), y = max(j1, j2),
                  v = min(j1 + 2, j2 + 2);
              if (x > u || y > v) {
                res.push_back({i1, j1});
                res.push_back({i2, j2});
                return res;
              }
            }
          }
        }
      }
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<char> ranks = {'2', '3', '4', '5', '6', '7', '8',
                        '9', 'T', 'J', 'Q', 'K', 'A'};
  vector<char> suits = {'C', 'D', 'H', 'S'};
  vector<string> cards;
  for (char c1 : ranks) {
    for (char c2 : suits) {
      string s;
      s.push_back(c1);
      s.push_back(c2);
      cards.push_back(s);
    }
  }
  cin >> n >> m;
  vector<pair<int, int>> jokers;
  map<string, bool> mark;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == "J1" || a[i][j] == "J2") {
        jokers.push_back({i, j});
      } else {
        mark[a[i][j]] = true;
      }
    }
  }
  vector<string> unused;
  for (auto s : cards) {
    if (!mark.count(s)) {
      unused.push_back(s);
    }
  }
  if (jokers.size() == 0) {
    vector<pair<int, int>> vec = Check();
    if (vec.size() == 2) {
      cout << YES << '\n';
      cout << "There are no jokers." << '\n';
      cout << "Put the first square to (" << vec[0].first << ", "
           << vec[0].second << ")." << '\n';
      cout << "Put the second square to (" << vec[1].first << ", "
           << vec[1].second << ")." << '\n';
    } else {
      cout << NO << '\n';
    }
  } else if (jokers.size() == 1) {
    string j = a[jokers[0].first][jokers[0].second];
    for (auto s : unused) {
      a[jokers[0].first][jokers[0].second] = s;
      vector<pair<int, int>> vec = Check();
      if (vec.size() >= 2) {
        cout << YES << '\n';
        cout << "Replace " << j << " with " << s << "." << '\n';
        cout << "Put the first square to (" << vec[0].first << ", "
             << vec[0].second << ")." << '\n';
        cout << "Put the second square to (" << vec[1].first << ", "
             << vec[1].second << ")." << '\n';
        return 0;
      }
    }
    cout << NO << '\n';
  } else if (jokers.size() == 2) {
    string j1 = a[jokers[0].first][jokers[0].second];
    string j2 = a[jokers[1].first][jokers[1].second];
    for (int i = 0; i < unused.size(); ++i) {
      for (int j = 0; j < unused.size(); ++j) {
        if (i != j) {
          a[jokers[0].first][jokers[0].second] = unused[i];
          a[jokers[1].first][jokers[1].second] = unused[j];
          vector<pair<int, int>> vec = Check();
          if (vec.size() >= 2) {
            cout << YES << '\n';
            if (j1 == "J1" && j2 == "J2") {
              cout << "Replace " << j1 << " with " << unused[i];
              cout << " and " << j2 << " with " << unused[j] << "." << '\n';
            } else {
              cout << "Replace " << j2 << " with " << unused[j];
              cout << " and " << j1 << " with " << unused[i] << "." << '\n';
            }
            cout << "Put the first square to (" << vec[0].first << ", "
                 << vec[0].second << ")." << '\n';
            cout << "Put the second square to (" << vec[1].first << ", "
                 << vec[1].second << ")." << '\n';
            return 0;
          }
        }
      }
    }
    cout << NO << '\n';
  } else {
    assert(false);
  }
  return 0;
}
