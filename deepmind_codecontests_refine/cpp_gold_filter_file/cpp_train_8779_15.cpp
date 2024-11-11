#include <bits/stdc++.h>
using namespace std;
int n, m;
char ch[505];
int a[505][505];
struct state {
  int x, y, val;
  state(int _x, int _y, int _v) {
    x = _x;
    y = _y;
    val = _v;
  }
  state() { x = y = val = 0; }
  bool operator<(const state& a) const {
    if (val == a.val) {
      return make_pair(x, y) < make_pair(a.x, a.y);
    }
    return val < a.val;
  }
};
set<state> e[505];
state dp[505][655];
int pre[505][655];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", ch);
    for (int j = 0; j < m; ++j) {
      a[i][j] = ch[j] - 'a';
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      for (int k = 0; k < 26; ++k) {
        if (j == k) continue;
        int now = 0;
        for (int o = 0; o < m; ++o) {
          if (o & 1) {
            now += a[i][o] != k;
          } else {
            now += a[i][o] != j;
          }
        }
        e[i].insert(state(j, k, now));
      }
    }
  }
  set<state>::iterator it;
  for (int i = 0; i < n; ++i) {
    it = e[i].begin();
    for (int j = 0; j < 650; ++j, ++it) {
      dp[i][j] = (*it);
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 650; ++j) {
      int now = 55555555;
      for (int k = 0; k < 650; ++k) {
        if (dp[i][j].x == dp[i - 1][k].x || dp[i][j].y == dp[i - 1][k].y)
          continue;
        if (dp[i - 1][k].val < now) {
          now = dp[i - 1][k].val;
          pre[i][j] = k;
        }
      }
      dp[i][j].val += now;
    }
  }
  int ans = 55555555, pos;
  for (int i = 0; i < 650; ++i) {
    if (dp[n - 1][i].val < ans) {
      ans = dp[n - 1][i].val;
      pos = i;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      if (j & 1) {
        a[i][j] = dp[i][pos].y;
      } else {
        a[i][j] = dp[i][pos].x;
      }
    }
    pos = pre[i][pos];
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%c", a[i][j] + 'a');
    }
    puts("");
  }
}
