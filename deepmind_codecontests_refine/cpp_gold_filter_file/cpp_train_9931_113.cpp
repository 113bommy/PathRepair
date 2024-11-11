#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int maxN = 2000;
const int S_CNT = 9;
const int M_CNT = 25;
const int DIST = 60 * 60;
int n, m;
int a[maxN][maxN];
int t[maxN][maxN];
int used[maxN][maxN];
int rc[maxN][maxN];
int is_in(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
int get(int x, int y) {
  int cnt = 0;
  for (int i = x - 2; i <= x + 2; ++i) {
    for (int j = y - 2; j <= y + 2; ++j) {
      if (is_in(i, j)) {
        cnt += a[i][j];
      }
    }
  }
  return cnt;
}
pair<int, int> choose_max(int x, int y) {
  pair<int, int> res = make_pair(-1, -1);
  int rs = -1;
  for (int i = x - 2; i <= x + 2; ++i) {
    for (int j = y - 2; j <= y + 2; ++j) {
      if (is_in(i, j)) {
        if (t[i][j] > rs) {
          rs = t[i][j];
          res = make_pair(i, j);
        }
      }
    }
  }
  return res;
}
void change_used(int x, int y, int num) {
  for (int i = x - 2; i <= x + 2; ++i) {
    for (int j = y - 2; j <= y + 2; ++j) {
      if (is_in(i, j)) {
        used[i][j] = num;
      }
    }
  }
}
int dist(pair<int, int> a, pair<int, int> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
pair<int, int> choose_long(int cx, int cy, int x, int y, int step) {
  pair<int, int> res = make_pair(cx, cy);
  int rs = -1;
  for (int i = cx - 2; i <= cx + 2; ++i) {
    for (int j = cy - 2; j <= cy + 2; ++j) {
      if (is_in(i, j) && a[i][j] && used[i][j] != step) {
        if (dist(make_pair(i, j), make_pair(x, y)) > rs) {
          rs = dist(make_pair(i, j), make_pair(x, y));
          res = make_pair(i, j);
        }
      }
    }
  }
  return res;
}
void dfs(int x, int y, int color) {
  if (rc[x][y] != 0) return;
  rc[x][y] = color;
  if (is_in(x + 1, y) && a[x + 1][y]) dfs(x + 1, y, color);
  if (is_in(x - 1, y) && a[x - 1][y]) dfs(x - 1, y, color);
  if (is_in(x, y + 1) && a[x][y + 1]) dfs(x, y + 1, color);
  if (is_in(x, y - 1) && a[x][y - 1]) dfs(x, y - 1, color);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  int c_col = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] && !rc[i][j]) {
        ++c_col;
        dfs(i, j, c_col);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j]) {
        t[i][j] = get(i, j);
      }
    }
  }
  vector<pair<int, int> > cur;
  int step = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] && !used[i][j] && t[i][j] == S_CNT) {
        ++step;
        int cx = i, cy = j;
        pair<int, int> buf1, buf2;
        for (int iter = 0; iter < 10; ++iter) {
          pair<int, int> nw = choose_long(cx, cy, i, j, step);
          change_used(cx, cy, step);
          cx = nw.first, cy = nw.second;
        }
        cur.push_back(make_pair(cx, cy));
      }
    }
  }
  vector<int> col(cur.size(), 0);
  for (int i = 0; i < col.size(); ++i) {
    col[i] = rc[cur[i].first][cur[i].second];
  }
  map<int, int> res;
  for (int i = 0; i < col.size(); ++i) {
    ++res[col[i]];
  }
  cout << res.size() << endl;
  vector<int> ans;
  for (map<int, int>::iterator it = res.begin(); it != res.end(); ++it) {
    ans.push_back(it->second);
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
