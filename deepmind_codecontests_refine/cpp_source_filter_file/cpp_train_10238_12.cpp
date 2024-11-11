#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int a[2100][2100];
int na[2100][2100];
int x[2100][2100];
int n;
int is_in(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < n); }
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
double pi = 2 * acos(0.0);
int curar = 0;
int sum(int x, int y) {
  if (x >= 0 && y >= 0) return na[x][y];
  return 0;
}
int sum(int lx, int ly, int rx, int ry) {
  return sum(rx, ry) - sum(rx, ly - 1) - sum(lx - 1, ry) + sum(lx - 1, ly - 1);
}
void fill(int tx, int ty, int val) {
  if (x[tx][ty] != 0) return;
  x[tx][ty] = val;
  ++curar;
  for (int i = 0; i < 8; ++i) {
    if (is_in(tx + dx[i], ty + dy[i]) && x[tx + dx[i]][ty + dy[i]] == 0 &&
        a[tx + dx[i]][ty + dy[i]] == 1) {
      fill(tx + dx[i], ty + dy[i], val);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      na[i][j] = a[i][j];
      if (is_in(i, j - 1)) na[i][j] += na[i][j - 1];
      if (is_in(i - 1, j)) na[i][j] += na[i - 1][j];
      if (is_in(i - 1, j - 1)) na[i][j] -= na[i - 1][j - 1];
    }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int res = sum(i - 5, j - 5, i + 5, j + 5);
      int up = min(n - 1, i + 5);
      int lo = max(0, i - 5);
      int rt = min(n - 1, j + 5);
      int lf = max(0, j - 5);
      if ((res + 0.) / (up - lo + 1) / (rt - lf + 1) > 0.6) a[i][j] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int res = sum(i - 5, j - 5, i + 5, j + 5);
      int up = min(n - 1, i + 5);
      int lo = max(0, i - 5);
      int rt = min(n - 1, j + 5);
      int lf = max(0, j - 5);
      if ((res + 0.) / (up - lo + 1) / (rt - lf + 1) < 0.3) a[i][j] = 0;
    }
  }
  vector<int> areas;
  areas.push_back(0);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 1 && x[i][j] == 0) {
        curar = 0;
        fill(i, j, cnt + 1);
        areas.push_back(curar);
        ++cnt;
      }
    }
  }
  vector<int> us(cnt + 1);
  vector<pair<int, int> > up(cnt + 1);
  vector<pair<int, int> > low(cnt + 1);
  vector<pair<int, int> > lf(cnt + 1);
  vector<pair<int, int> > rt(cnt + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j]) {
        us[x[i][j]] = 1;
        up[x[i][j]] = low[x[i][j]] = make_pair(i, j);
        lf[x[i][j]] = rt[x[i][j]] = make_pair(j, i);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j]) {
        up[x[i][j]] = min(up[x[i][j]], make_pair(i, j));
        low[x[i][j]] = max(low[x[i][j]], make_pair(i, j));
        lf[x[i][j]] = min(lf[x[i][j]], make_pair(j, i));
        rt[x[i][j]] = max(rt[x[i][j]], make_pair(j, i));
      }
    }
  }
  for (int i = 0; i <= cnt; ++i) {
    swap(lf[i].first, lf[i].second);
    swap(rt[i].first, rt[i].second);
  }
  int circle = 0;
  int count = 0;
  for (int i = 1; i <= cnt; ++i) {
    if (areas[i] > 120) {
      ++count;
      int tx = (up[i].first + low[i].first) / 2;
      int ty = (lf[i].second + rt[i].second) / 2;
      int diag = sqrt((double)(up[i].first - low[i].first) *
                          (up[i].first - low[i].first) +
                      (up[i].second - low[i].second) *
                          (up[i].second - low[i].second)) /
                 2.;
      int cnt = 0, amount = 0;
      for (int j = tx - diag; j <= tx + diag; ++j) {
        for (int k = ty - diag; k <= ty + diag; ++k) {
          if (is_in(j, k)) {
            if ((j - tx) * (j - tx) + (k - ty) * (k - ty) <= diag * diag) {
              ++amount;
              if (a[j][k] == 1) ++cnt;
            }
          }
        }
      }
      if (cnt > 0.8 * amount) {
        ++circle;
      }
    }
  }
  printf("%d %d\n", circle, count - circle);
  return 0;
}
