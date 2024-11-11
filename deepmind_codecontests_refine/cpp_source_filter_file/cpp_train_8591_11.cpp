#include <bits/stdc++.h>
using namespace std;
int T, loc[4][2];
int ans[4][2];
int res;
int ord[24][4];
void update(int k, vector<int> p[]) {
  for (int i = 0; i < 24; i++) {
    int len = 0;
    bool flag = true;
    for (int j = 0; j < 4; j++) {
      int des[2] = {p[0][j & 1], p[1][j >> 1]};
      int tmp = (k >> ord[i][j]) & 1;
      if (loc[ord[i][j]][tmp] != des[tmp]) {
        flag = false;
        break;
      }
      len = max(len, abs(loc[ord[i][j]][1 - tmp] - des[1 - tmp]));
    }
    if (flag) {
      if (len < res) {
        res = len;
        for (int j = 0; j < 4; j++) {
          ans[ord[i][j]][0] = p[0][j & 1];
          ans[ord[i][j]][1] = p[1][j >> 1];
        }
      }
    }
  }
}
void solve(int k) {
  vector<int> p[2];
  int rf[2][4];
  memset(rf, 0, sizeof(rf));
  for (int i = 0; i < 4; i++) {
    int tmp = (k >> i) & 1;
    bool flag = true;
    for (int j = 0; j < p[tmp].size(); j++) {
      if (loc[i][tmp] == p[tmp][j]) {
        flag = false;
        rf[tmp][j]++;
        if (rf[tmp][j] > 1) {
          return;
        }
        break;
      }
    }
    if (flag) {
      p[tmp].push_back(loc[i][tmp]);
    }
  }
  if (p[0].size() > 2 || p[1].size() > 2 ||
      (p[0].size() != 2 && p[1].size() != 2)) {
    return;
  }
  if (p[0].size() == 2 && p[1].size() == 2) {
    if (abs(p[0][0] - p[0][1] == abs(p[1][0] - p[1][1]))) {
      update(k, p);
    }
    return;
  }
  for (int i = 0; i < 2; i++) {
    if (p[i].size() == 1) {
      int d = p[1 - i][0] - p[1 - i][1];
      p[i].push_back(p[i][0] + d);
      update(k, p);
      p[i][1] -= 2 * d;
      update(k, p);
    } else if (p[i].size() == 0) {
      vector<int> q[2];
      for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 2; b++) {
          if (loc[a][1 - i] == p[1 - i][b]) {
            q[b].push_back(loc[a][i]);
          }
        }
      }
      for (int _ = 0; _ < 2; _++) {
        if (q[_][0] > q[_][1]) {
          swap(q[_][0], q[_][1]);
        }
      }
      vector<int> ax;
      int d = abs(p[1 - i][0] - p[1 - i][1]);
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          ax.push_back(q[a][b] + (b ? 0 : d));
        }
      }
      sort(ax.begin(), ax.end());
      int tt = (ax[0] + ax[3]) / 2;
      p[i].push_back(tt - d);
      p[i].push_back(tt);
      update(k, p);
    }
  }
}
void dfs(int a[], int k, int& n) {
  if (k == 4) {
    for (int i = 0; i < 4; i++) {
      ord[n][i] = a[i];
    }
    n++;
    return;
  }
  for (int i = k; i < 4; i++) {
    swap(a[k], a[i]);
    dfs(a, k + 1, n);
    swap(a[k], a[i]);
  }
}
void init() {
  int tmp[4] = {0, 1, 2, 3};
  int n = 0;
  dfs(tmp, 0, n);
}
int main() {
  init();
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < 4; i++) {
      scanf("%d%d", &loc[i][0], &loc[i][1]);
    }
    res = 0x7fffffff;
    for (int i = 0; i < 16; i++) {
      solve(i);
    }
    if (res == 0x7fffffff) {
      res = -1;
    }
    printf("%d\n", res);
    if (res != -1) {
      for (int i = 0; i < 4; i++) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
      }
    }
  }
  return 0;
}
