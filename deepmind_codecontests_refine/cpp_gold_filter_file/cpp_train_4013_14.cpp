#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int n, m, sx, sy, ex, ey;
char a[4][1005][1005];
int vs[4][1005][1005];
int D[4][1005][1005];
int t, fl;
queue<pair<int, pair<int, int>>> q;
string su = "+LRU|v";
string sd = "+LRD|^";
string sl = "+ULD->";
string sr = "+RUD-<";
void add(int i, int j, int k, int ii, int jj, int kk) {
  if (vs[kk][ii][jj]) return;
  vs[kk][ii][jj] = 1;
  D[kk][ii][jj] = D[k][i][j] + 1;
  q.push({kk, {ii, jj}});
  if (ii == ex and jj == ey) fl = 1;
}
void u(int i, int j, int k) {
  int ii = max(0, i - 1);
  int jj = j;
  int kk = k;
  for (int x = 0; x < (int)(su.size()); x++) {
    if (su[x] == a[kk][ii][jj]) {
      add(i, j, k, ii, jj, kk);
      return;
    }
  }
}
void d(int i, int j, int k) {
  int ii = min(n - 1, i + 1);
  int jj = j;
  int kk = k;
  for (int x = 0; x < (int)(sd.size()); x++) {
    if (sd[x] == a[kk][ii][jj]) {
      add(i, j, k, ii, jj, kk);
      return;
    }
  }
}
void l(int i, int j, int k) {
  int ii = i;
  int jj = max(0, j - 1);
  int kk = k;
  for (int x = 0; x < (int)(sl.size()); x++) {
    if (sl[x] == a[kk][ii][jj]) {
      add(i, j, k, ii, jj, kk);
      return;
    }
  }
}
void r(int i, int j, int k) {
  int ii = i;
  int jj = min(m - 1, j + 1);
  int kk = k;
  for (int x = 0; x < (int)(sr.size()); x++) {
    if (sr[x] == a[kk][ii][jj]) {
      add(i, j, k, ii, jj, kk);
      return;
    }
  }
}
void g(int i, int j, int k) {
  int ii = i;
  int jj = j;
  int kk = (k + 1) % 4;
  add(i, j, k, ii, jj, kk);
}
int bfs(int x, int y, int z) {
  vs[z][x][y] = 1;
  if (x == ex and y == ey) {
    return 0;
  }
  q.push({z, {x, y}});
  while (!q.empty()) {
    pair<int, pair<int, int>> U = q.front();
    q.pop();
    int i = U.second.first, j = U.second.second, k = U.first;
    if (a[k][i][j] == '+') {
      u(i, j, k);
      d(i, j, k);
      l(i, j, k);
      r(i, j, k);
    } else if (a[k][i][j] == '^') {
      u(i, j, k);
    } else if (a[k][i][j] == '>') {
      r(i, j, k);
    } else if (a[k][i][j] == 'v') {
      d(i, j, k);
    } else if (a[k][i][j] == '<') {
      l(i, j, k);
    } else if (a[k][i][j] == '-') {
      l(i, j, k);
      r(i, j, k);
    } else if (a[k][i][j] == '|') {
      u(i, j, k);
      d(i, j, k);
    } else if (a[k][i][j] == 'L') {
      u(i, j, k);
      d(i, j, k);
      r(i, j, k);
    } else if (a[k][i][j] == 'U') {
      d(i, j, k);
      l(i, j, k);
      r(i, j, k);
    } else if (a[k][i][j] == 'R') {
      u(i, j, k);
      d(i, j, k);
      l(i, j, k);
    } else if (a[k][i][j] == 'D') {
      u(i, j, k);
      l(i, j, k);
      r(i, j, k);
    }
    if (a[k][i][j] != '*') {
      g(i, j, k);
    }
    if (fl) {
      return D[k][i][j] + 1;
    }
  }
  return -1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[0][i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[0][i][j] == '+')
        a[1][i][j] = '+', a[2][i][j] = '+', a[3][i][j] = '+';
      else if (a[0][i][j] == '-')
        a[1][i][j] = '|', a[2][i][j] = '-', a[3][i][j] = '|';
      else if (a[0][i][j] == '|')
        a[1][i][j] = '-', a[2][i][j] = '|', a[3][i][j] = '-';
      else if (a[0][i][j] == '^')
        a[1][i][j] = '>', a[2][i][j] = 'v', a[3][i][j] = '<';
      else if (a[0][i][j] == '>')
        a[1][i][j] = 'v', a[2][i][j] = '<', a[3][i][j] = '^';
      else if (a[0][i][j] == 'v')
        a[1][i][j] = '<', a[2][i][j] = '^', a[3][i][j] = '>';
      else if (a[0][i][j] == '<')
        a[1][i][j] = '^', a[2][i][j] = '>', a[3][i][j] = 'v';
      else if (a[0][i][j] == 'L')
        a[1][i][j] = 'U', a[2][i][j] = 'R', a[3][i][j] = 'D';
      else if (a[0][i][j] == 'U')
        a[1][i][j] = 'R', a[2][i][j] = 'D', a[3][i][j] = 'L';
      else if (a[0][i][j] == 'R')
        a[1][i][j] = 'D', a[2][i][j] = 'L', a[3][i][j] = 'U';
      else if (a[0][i][j] == 'D')
        a[1][i][j] = 'L', a[2][i][j] = 'U', a[3][i][j] = 'R';
      else if (a[0][i][j] == '*')
        a[1][i][j] = '*', a[2][i][j] = '*', a[3][i][j] = '*';
    }
  }
  cin >> sx >> sy >> ex >> ey;
  sx--, sy--, ex--, ey--;
  int ans = bfs(sx, sy, 0);
  cout << ans << endl;
  return 0;
}
