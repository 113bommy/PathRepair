#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const int base = 2e5 + 1;
const long long MAX = 1e15 + 1;
const double EPS = 1e-9;
const double PI = acos(-1.);
const int MAXN = 2 * 1e5 + 47;
char res[1000][1000];
vector<vector<pair<int, int> > > v;
int n, was[1000][1000];
void dfs(int i, int j) {
  was[i][j] = 1;
  vector<pair<int, int> > nxt = {make_pair(i - 1, j), make_pair(i + 1, j),
                                 make_pair(i, j - 1), make_pair(i, j + 1)};
  string s = "UDRL";
  for (int k = (0); k < (4); ++k) {
    int x = nxt[k].first, y = nxt[k].second;
    if (x < 0 || y < 0 || x >= n || y >= n || was[x][y]) continue;
    if (v[x][y] == v[i][j]) {
      res[x][y] = s[k];
      dfs(x, y);
    }
  }
}
void f(int i, int j) {
  vector<pair<int, int> > nxt = {make_pair(i - 1, j), make_pair(i + 1, j),
                                 make_pair(i, j - 1), make_pair(i, j + 1)};
  string s = "DURL";
  string t = "UDLR";
  for (int k = (0); k < (4); ++k) {
    int x = nxt[k].first, y = nxt[k].second;
    if (x < 0 || y < 0 || x >= n || y >= n) continue;
    if (v[x][y] == make_pair(-2, -2)) {
      res[i][j] = t[k];
      if (res[x][y] == '?') res[x][y] = s[k];
      break;
    }
  }
}
int main() {
  cin >> n;
  v.resize(n);
  for (int i = (0); i < (n); ++i) {
    v[i].resize(n);
    for (int j = (0); j < (n); ++j) {
      scanf("%d %d", &v[i][j].first, &v[i][j].second);
      v[i][j].first--;
      v[i][j].second--;
      res[i][j] = '?';
    }
  }
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) {
      if (v[i][j] == make_pair(i, j)) {
        res[i][j] = 'X';
        dfs(i, j);
      }
    }
  }
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) {
      if (v[i][j] == make_pair(-2, -2) && res[i][j] == '?') {
        f(i, j);
      }
    }
  }
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) {
      if (res[i][j] == '?') {
        cout << "INVALID\n";
        return 0;
      }
    }
  }
  cout << "VALID\n";
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) {
      cout << res[i][j];
    }
    cout << '\n';
  }
  return 0;
}
