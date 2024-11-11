#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);
template <class T, class S>
inline void add(T& a, S b) {
  a += b;
  if (a >= mod) a -= mod;
}
template <class T, class S>
inline void sub(T& a, S b) {
  a -= b;
  if (a < 0) a += mod;
}
template <class T, class S>
inline bool chkmax(T& a, S b) {
  return a < b ? a = b, true : false;
}
template <class T, class S>
inline bool chkmin(T& a, S b) {
  return a > b ? a = b, true : false;
}
int n, sx, sy;
int on[N][N];
bool vis[N][N];
set<int> row[N], col[N];
string path;
bool check(int x, int y, int vx, int vy) {
  if (x + vx <= 0 || x + vx > n) return false;
  if (y + vy <= 0 || y + vy > n) return false;
  if (vis[x + vx][y + vy]) return false;
  if (!vy) {
    if (vx == 1)
      return upper_bound((col[y]).begin(), (col[y]).end(), x) != col[y].end();
    else
      return lower_bound((col[y]).begin(), (col[y]).end(), x) != col[y].begin();
  } else {
    if (vy == 1)
      return upper_bound((row[x]).begin(), (row[x]).end(), y) != row[x].end();
    else
      return lower_bound((row[x]).begin(), (row[x]).end(), y) != row[x].begin();
  }
}
void dfs(int x, int y) {
  vis[x][y] = true;
  if (!on[x][y]) {
    path.push_back('1');
    on[x][y] = true;
    row[x].insert(y);
    row[y].insert(x);
  }
  if (check(x, y, 0, 1)) {
    path.push_back('R');
    dfs(x, y + 1);
    path.push_back('L');
  }
  if (check(x, y, 0, -1)) {
    path.push_back('L');
    dfs(x, y - 1);
    path.push_back('R');
  }
  if (check(x, y, 1, 0)) {
    path.push_back('D');
    dfs(x + 1, y);
    path.push_back('U');
  }
  if (check(x, y, -1, 0)) {
    path.push_back('U');
    dfs(x - 1, y);
    path.push_back('D');
  }
  if (on[x][y]) {
    on[x][y] = false;
    path.push_back('2');
    row[x].erase(y);
    col[y].erase(x);
  }
}
int main() {
  cin >> n >> sx >> sy;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> on[i][j];
      if (on[i][j]) {
        row[i].insert(j);
        col[j].insert(i);
      }
    }
  }
  dfs(sx, sy);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (on[i][j]) return puts("NO"), 0;
  cout << "YES"
       << "\n";
  cout << path << "\n";
  return 0;
}
