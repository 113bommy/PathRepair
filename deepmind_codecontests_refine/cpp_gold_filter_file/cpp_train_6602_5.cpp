#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T>
void checkMax(T &a, T b) {
  a = max(a, b);
}
template <class T>
void checkMin(T &a, T b) {
  a = min(a, b);
}
const int N = 100005;
int n, m, x[N], y[N], num[3 * N];
map<int, int> xm, ym;
vector<int> ox, oy, row[3 * N];
int main() {
  int i, j, k;
  while (scanf("%d%d", &n, &m) != EOF) {
    ox.clear();
    oy.clear();
    for (i = 1; i <= m; i++) {
      scanf("%d%d", &x[i], &y[i]);
      if (x[i] - 1 >= 1) ox.push_back(x[i] - 1);
      ox.push_back(x[i]);
      if (x[i] + 1 <= n) ox.push_back(x[i] + 1);
      if (y[i] - 1 >= 1) oy.push_back(y[i] - 1);
      oy.push_back(y[i]);
      if (y[i] + 1 <= n) oy.push_back(y[i] + 1);
    }
    sort(ox.begin(), ox.end());
    sort(oy.begin(), oy.end());
    int nx = 0, ny = 0;
    xm.clear();
    ym.clear();
    for (i = 0; i < ox.size(); i++) {
      if (i == 0 || ox[i] != ox[i - 1]) xm[ox[i]] = ++nx;
    }
    for (i = 0; i < oy.size(); i++) {
      if (i == 0 || oy[i] != oy[i - 1]) ym[oy[i]] = ++ny;
    }
    for (i = 1; i <= m; i++) {
      x[i] = xm[x[i]];
      y[i] = ym[y[i]];
    }
    for (i = 1; i <= nx; i++) row[i].clear();
    for (i = 1; i <= m; i++) row[x[i]].push_back(y[i]);
    for (i = 1; i <= nx; i++) sort(row[i].begin(), row[i].end());
    memset(num, -1, sizeof(num));
    int right = ny;
    if (row[1].size() > 0) right = row[1][0] - 1;
    for (i = 1; i <= right; i++) num[i] = 1;
    for (i = 2; i <= nx; i++) {
      for (j = 0; j < row[i].size(); j++) num[row[i][j]] = -i;
      for (j = 0; j < row[i - 1].size(); j++) {
        if (row[i - 1][j] - 1 >= 1 && num[row[i - 1][j] - 1] == 1) {
          for (k = row[i - 1][j]; k <= ny; k++) {
            if (num[k] == -i || num[k] == 1) break;
            num[k] = 1;
          }
        }
      }
    }
    if (num[ny] == 1)
      printf("%d\n", 2 * (n - 1));
    else
      printf("%d\n", -1);
  }
  return 0;
}
