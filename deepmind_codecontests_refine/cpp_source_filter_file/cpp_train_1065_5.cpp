#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
static const int MAX = 1001;
bool check1(const vector<vector<int>>& matr) {
  int n = matr.size();
  int m = matr[0].size();
  vector<int> x(n), y(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      x[i] |= matr[i][j];
      y[j] |= matr[i][j];
    }
  }
  int x1 = 0, y1 = 0;
  for (int i = 0; i < n; ++i) {
    x1 |= !x[i];
  }
  for (int i = 0; i < m; ++i) {
    y1 |= !y[i];
  }
  return x1 ^ y1;
}
bool check2(const vector<vector<int>>& matr) {
  int n = matr.size();
  int m = matr[0].size();
  {
    for (int i = 0; i < n; ++i) {
      int dp = 0;
      for (int j = 1; j < m; ++j) {
        if (dp == 0 && matr[i][j] < matr[i][j - 1]) {
          ++dp;
        }
        if (dp == 1 && matr[i][j] > matr[i][j - 1]) {
          return true;
        }
      }
    }
  }
  {
    for (int j = 0; j < m; ++j) {
      int dp = 0;
      for (int i = 1; i < n; ++i) {
        if (dp == 0 && matr[i][j] < matr[i - 1][j]) {
          ++dp;
        }
        if (dp == 1 && matr[i][j] > matr[i - 1][j]) {
          return true;
        }
      }
    }
  }
  return false;
}
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int mask[MAX][MAX];
void dfs(int x, int y, vector<vector<int>>& matr) {
  mask[x][y] = 1;
  for (int dir = 0; dir < 4; ++dir) {
    int curX = x + dx[dir];
    int curY = y + dy[dir];
    if (curX < 0 || curX >= matr.size() || curY < 0 || curY >= matr.size() ||
        !matr[curX][curY] || mask[curX][curY]) {
      continue;
    }
    dfs(curX, curY, matr);
  }
}
void solve(int TEST) {
  int n, m;
  cin >> n >> m;
  char c;
  vector<vector<int>> matr(n, vector<int>(m));
  for (auto& line : matr) {
    for (auto& ch : line) {
      cin >> c;
      ch = c == '#';
    }
  }
  if (check1(matr) || check2(matr)) {
    cout << -1 << endl;
    return;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matr[i][j] && !mask[i][j]) {
        ++res;
        dfs(i, j, matr);
      }
    }
  }
  cout << res << endl;
}
int main() {
  int n = 1;
  int test = 0;
  while (n--) {
    ++test;
    solve(test);
  }
  return 0;
}
