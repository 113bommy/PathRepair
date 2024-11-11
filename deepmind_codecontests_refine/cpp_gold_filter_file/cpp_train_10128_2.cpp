#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m;
char maze[102][102];
struct ope {
  int x, y, xx, yy, xxx, yyy;
  ope(int a, int b, int c, int d, int f, int e) {
    x = a;
    y = b;
    xx = c;
    yy = d;
    xxx = f;
    yyy = e;
  }
};
int a[102][102];
vector<ope> v;
void clean(int x, int y) {
  if (a[x][y] + a[x][y + 1] + a[x + 1][y + 1] + a[x + 1][y] == 0) return;
  if (a[x][y] + a[x][y + 1] + a[x + 1][y + 1] + a[x + 1][y] == 3) {
    vector<pair<int, int> > vv;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        if (a[i + x][j + y] != 0) {
          a[i + x][j + y] = 0;
          vv.push_back(make_pair(i + x, j + y));
        }
    v.push_back(ope(vv[0].first, vv[0].second, vv[1].first, vv[1].second,
                    vv[2].first, vv[2].second));
    return;
  }
  if (a[x][y] + a[x][y + 1] + a[x + 1][y + 1] + a[x + 1][y] == 4) {
    a[x][y] ^= 1;
    a[x + 1][y] ^= 1;
    a[x][y + 1] ^= 1;
    v.push_back(ope(x, y, x + 1, y, x, y + 1));
    clean(x, y);
    return;
  }
  if (a[x][y] + a[x][y + 1] + a[x + 1][y + 1] + a[x + 1][y] == 2) {
    if (a[x][y] == a[x][y + 1]) {
      if (a[x][y] == 0) {
        v.push_back(ope(x, y, x + 1, y, x, y + 1));
        a[x][y] ^= 1;
        a[x][y + 1] ^= 1;
        a[x + 1][y] ^= 1;
        clean(x, y);
      } else {
        v.push_back(ope(x, y, x + 1, y + 1, x + 1, y));
        a[x][y] ^= 1;
        a[x + 1][y + 1] ^= 1;
        a[x + 1][y] ^= 1;
        clean(x, y);
      }
    } else {
      if (a[x][y] == a[x + 1][y + 1]) {
        if (a[x][y] == 0) {
          v.push_back(ope(x, y, x + 1, y + 1, x, y + 1));
          a[x][y] ^= 1;
          a[x][y + 1] ^= 1;
          a[x + 1][y + 1] ^= 1;
          clean(x, y);
        } else {
          v.push_back(ope(x, y, x + 1, y, x, y + 1));
          a[x][y] ^= 1;
          a[x + 1][y] ^= 1;
          a[x][y + 1] ^= 1;
          clean(x, y);
        }
      } else {
        if (a[x][y] == 0) {
          v.push_back(ope(x, y, x + 1, y, x, y + 1));
          a[x][y] ^= 1;
          a[x][y + 1] ^= 1;
          a[x + 1][y] ^= 1;
          clean(x, y);
        } else {
          v.push_back(ope(x, y, x + 1, y + 1, x, y + 1));
          a[x][y] ^= 1;
          a[x + 1][y + 1] ^= 1;
          a[x][y + 1] ^= 1;
          clean(x, y);
        }
      }
    }
    return;
  }
  if (a[x][y] + a[x][y + 1] + a[x + 1][y + 1] + a[x + 1][y] == 1) {
    if (a[x][y]) {
      v.push_back(ope(x, y, x, y + 1, x + 1, y + 1));
      a[x][y] ^= 1;
      a[x][y + 1] ^= 1;
      a[x + 1][y + 1] ^= 1;
    } else if (a[x + 1][y + 1]) {
      v.push_back(ope(x, y, x, y + 1, x + 1, y + 1));
      a[x][y] ^= 1;
      a[x][y + 1] ^= 1;
      a[x + 1][y + 1] ^= 1;
    } else if (a[x][y + 1]) {
      v.push_back(ope(x, y, x, y + 1, x + 1, y + 1));
      a[x][y] ^= 1;
      a[x + 1][y + 1] ^= 1;
      a[x][y + 1] ^= 1;
    } else if (a[x + 1][y]) {
      v.push_back(ope(x, y, x, y + 1, x + 1, y));
      a[x][y] ^= 1;
      a[x + 1][y] ^= 1;
      a[x][y + 1] ^= 1;
    }
    clean(x, y);
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> maze[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = maze[i][j] - '0';
  v.clear();
  for (int i = 1; i <= n - 2; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        if (j == 1) {
          a[i][j] ^= 1;
          a[i + 1][j] ^= 1;
          a[i + 1][j + 1] ^= 1;
          v.push_back(ope(i, j, i + 1, j + 1, i + 1, j));
        } else {
          a[i][j] ^= 1;
          a[i + 1][j] ^= 1;
          a[i + 1][j - 1] ^= 1;
          v.push_back(ope(i, j, i + 1, j, i + 1, j - 1));
        }
      }
    }
  }
  if (m % 2 == 1) {
    int i = n - 1, j = m;
    if (a[n - 1][m]) {
      a[i][j] ^= 1;
      a[i][j - 1] ^= 1;
      a[i + 1][j] ^= 1;
      v.push_back(ope(i, j, i, j - 1, i + 1, j));
    }
    i = n, j = m;
    if (a[n][m]) {
      a[i][j] ^= 1;
      a[i][j - 1] ^= 1;
      a[i - 1][j - 1] ^= 1;
      v.push_back(ope(i, j, i, j - 1, i - 1, j - 1));
    }
  }
  for (int j = 1; j < m; j += 2) {
    clean(n - 1, j);
  }
  cout << v.size() << endl;
  assert(v.size() <= n * m);
  for (auto it : v) {
    cout << it.x << ' ' << it.y << ' ' << it.xx << ' ' << it.yy << ' ' << it.xxx
         << ' ' << it.yyy << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
