#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 123;
const long long INF = (long long)1e18 + 123;
const int inf = (int)1e9 + 123;
int n, m, q, up[1111][1111], down[1111][1111], lleefftt[1111][1111],
    rriigghhtt[1111][1111];
int c[1111][1111];
int l[1111], r[1111];
vector<pair<int, int> > res;
long long mx;
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &c[i][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!c[i][j])
        up[i][j] = 0;
      else
        up[i][j] = up[i - 1][j] + 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      if (!c[i][j])
        down[i][j] = 0;
      else
        down[i][j] = down[i + 1][j] + 1;
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (!c[i][j])
        rriigghhtt[j][i] = 0;
      else
        rriigghhtt[j][i] = rriigghhtt[j - 1][i] + 1;
    }
  }
  for (int j = m; j >= 1; j--) {
    for (int i = 1; i <= n; i++) {
      if (!c[i][j])
        lleefftt[j][i] = 0;
      else
        lleefftt[j][i] = lleefftt[j + 1][i] + 1;
    }
  }
  for (int it = 1; it <= q; it++) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      c[x][y] ^= 1;
      for (int i = 1; i <= n; i++) {
        if (!c[i][y])
          up[i][y] = 0;
        else
          up[i][y] = up[i - 1][y] + 1;
      }
      for (int i = n; i >= 1; i--) {
        if (!c[i][y])
          down[i][y] = 0;
        else
          down[i][y] = down[i + 1][y] + 1;
      }
      for (int j = 1; j <= m; j++) {
        if (!c[x][j])
          rriigghhtt[j][x] = 0;
        else
          rriigghhtt[j][x] = rriigghhtt[j - 1][x] + 1;
      }
      for (int j = m; j >= 1; j--) {
        if (!c[x][j])
          lleefftt[j][x] = 0;
        else
          lleefftt[j][x] = lleefftt[j + 1][x] + 1;
      }
    }
    if (op == 2) {
      mx = 0;
      res.clear();
      for (int j = 1; j <= m; j++) {
        l[j] = j;
        while ((int)(res.size()) > 0 && res.back().first >= up[x][j]) {
          l[j] = res.back().second;
          res.pop_back();
        }
        res.push_back(make_pair(up[x][j], l[j]));
      }
      res.clear();
      for (int j = m; j >= 1; j--) {
        r[j] = j;
        while ((int)(res.size()) > 0 && res.back().first >= up[x][j]) {
          r[j] = res.back().second;
          res.pop_back();
        }
        res.push_back(make_pair(up[x][j], l[j]));
      }
      for (int j = 1; j <= m; j++) {
        if (l[j] <= y && y <= r[j]) {
          mx = max(mx, 1ll * (r[j] - l[j] + 1) * up[x][j]);
        }
      }
      res.clear();
      for (int j = 1; j <= m; j++) {
        l[j] = j;
        while ((int)(res.size()) > 0 && res.back().first >= down[x][j]) {
          l[j] = res.back().second;
          res.pop_back();
        }
        res.push_back(make_pair(down[x][j], l[j]));
      }
      res.clear();
      for (int j = m; j >= 1; j--) {
        r[j] = j;
        while ((int)(res.size()) > 0 && res.back().first >= down[x][j]) {
          r[j] = res.back().second;
          res.pop_back();
        }
        res.push_back(make_pair(down[x][j], r[j]));
      }
      for (int j = 1; j <= m; j++) {
        if (l[j] <= y && y <= r[j]) {
          mx = max(mx, 1ll * (r[j] - l[j] + 1) * down[x][j]);
        }
      }
      res.clear();
      for (int i = 1; i <= n; i++) {
        l[i] = i;
        while ((int)(res.size()) > 0 && res.back().first >= rriigghhtt[y][i]) {
          l[i] = res.back().second;
          res.pop_back();
        }
        res.push_back(make_pair(rriigghhtt[y][i], l[i]));
      }
      res.clear();
      for (int i = n; i >= 1; i--) {
        r[i] = i;
        while ((int)(res.size()) > 0 && res.back().first >= rriigghhtt[y][i]) {
          r[i] = res.back().second;
          res.pop_back();
        }
        res.push_back(make_pair(rriigghhtt[y][i], r[i]));
      }
      for (int i = 1; i <= n; i++) {
        if (l[i] <= x && x <= r[i]) {
          mx = max(mx, 1ll * (r[i] - l[i] + 1) * rriigghhtt[y][i]);
        }
      }
      res.clear();
      for (int i = 1; i <= n; i++) {
        l[i] = i;
        while ((int)(res.size()) > 0 && res.back().first >= lleefftt[y][i]) {
          l[i] = res.back().second;
          res.pop_back();
        }
        res.push_back(make_pair(lleefftt[y][i], l[i]));
      }
      res.clear();
      for (int i = n; i >= 1; i--) {
        r[i] = i;
        while ((int)(res.size()) > 0 && res.back().first >= lleefftt[y][i]) {
          r[i] = res.back().second;
          res.pop_back();
        }
        res.push_back(make_pair(lleefftt[y][i], r[i]));
      }
      for (int i = 1; i <= n; i++) {
        if (l[i] <= x && x <= r[i]) {
          mx = max(mx, 1ll * (r[i] - l[i] + 1) * lleefftt[y][i]);
        }
      }
      printf("%I64d\n", mx);
    }
  }
  return 0;
}
