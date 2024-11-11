#include <bits/stdc++.h>
using namespace std;
string firsts = "23456789TJQKA";
string seconds = "CDHS";
int n, m;
string a[55][55];
vector<pair<string, string>> cur, ans;
vector<pair<int, int>> wh;
bool go(int x, int y) {
  if (y == m) {
    y = 0;
    ++x;
  }
  if (x == n) {
    vector<pair<int, int>> goods;
    for (int i1 = 0; i1 + 2 < n; ++i1) {
      for (int j1 = 0; j1 + 2 < m; ++j1) {
        set<char> f, s;
        for (int x = 0; x < 3; ++x) {
          for (int y = 0; y < 3; ++y) {
            f.insert(a[i1 + x][j1 + y][0]);
            s.insert(a[i1 + x][j1 + y][1]);
          }
        }
        if (f.size() == 9u || s.size() == 1u) {
          goods.emplace_back(i1, j1);
        }
      }
    }
    for (auto c1 : goods) {
      for (auto c2 : goods) {
        if (abs(c1.first - c2.first) >= 3 || abs(c1.second - c2.second) >= 3) {
          ans = cur;
          wh = {c1, c2};
          return true;
        }
      }
    }
    return false;
  }
  string th = a[x][y];
  if (th != "J1" && th != "J2") return go(x, y + 1);
  for (char f : firsts) {
    for (char s : seconds) {
      string rep = {f, s};
      bool ok = true;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) ok &= a[i][j] != rep;
      if (!ok) continue;
      a[x][y] = rep;
      cur.emplace_back(th, rep);
      if (go(x, y + 1)) return true;
      cur.pop_back();
      a[x][y] = th;
    }
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  if (go(0, 0)) {
    cout << "Solution exists.\n";
    if (ans.empty()) {
      cout << "There are no jokers.\n";
    } else if (ans.size() == 1u) {
      cout << "Replace " << ans[0].first << " with " << ans[0].second << ".\n";
    } else {
      string x = ans[0].second, y = ans[1].second;
      if (ans[0].first != "J1") swap(x, y);
      cout << "Replace J1 with " << x << " and J2 with " << y << ".\n";
    }
    cout << "Put the first square to (" << wh[0].first + 1 << ", "
         << wh[0].second + 1 << ").\n";
    cout << "Put the second square to (" << wh[1].first + 1 << ", "
         << wh[1].second + 1 << ").\n";
  } else {
    cout << "No solution.\n";
  }
}
