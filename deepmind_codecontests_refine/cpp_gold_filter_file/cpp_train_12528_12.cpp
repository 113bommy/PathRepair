#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
int used[50][50];
int tot = 0;
class Solution {
 public:
  int n, m;
  void dfs(int x, int y) {
    used[x][y] = 1;
    tot++;
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx * dy == 0 && dx + dy != 0) {
          int xx = x + dx;
          int yy = y + dy;
          if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            if (!used[xx][yy] && grid[xx][yy] == '#') {
              dfs(xx, yy);
            }
          }
        }
      }
    }
  }
  void solve(std::istream& in, std::ostream& out) {
    in >> n >> m;
    string s;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      in >> s;
      grid.push_back(s);
      for (int i = 0; i <= (int)s.size() - 1; i++)
        if (s[i] == '#') cnt++;
    }
    if (cnt <= 2) {
      out << -1 << '\n';
    } else {
      for (int i = 0; i <= n - 1; i++) {
        for (int j = 0; j <= m - 1; j++) {
          if (grid[i][j] == '#') {
            bool flag = true;
            for (int dx = -1; dx <= 1; dx++) {
              for (int dy = -1; dy <= 1; dy++) {
                if (dx * dy == 0 && dx + dy != 0) {
                  int x = i + dx;
                  int y = j + dy;
                  if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (grid[x][y] == '#') {
                      tot = 0;
                      grid[i][j] = '.';
                      memset(used, 0, sizeof(used));
                      dfs(x, y);
                      grid[i][j] = '#';
                      if (tot <= cnt - 2) {
                        out << 1 << '\n';
                        return;
                      } else
                        flag = false;
                      break;
                    }
                  }
                }
              }
              if (!flag) break;
            }
          }
        }
      }
      out << 2 << '\n';
    }
    return;
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
