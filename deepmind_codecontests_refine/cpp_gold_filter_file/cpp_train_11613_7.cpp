#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:667772160")
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
vector<pair<int, int> > color[90000 + 7];
int level[300 + 7][300 + 7], row, col, cl, dp[300 + 7][300 + 7];
void bfs(int pre) {
  queue<pair<int, int> > q;
  int tx, ty;
  pair<int, int> tp;
  memset(level, -1, sizeof(level));
  for (int i = 0; i < color[pre].size(); i++) {
    tx = color[pre][i].first;
    ty = color[pre][i].second;
    level[tx][ty] = dp[tx][ty];
    q.push(make_pair(tx, ty));
  }
  while (!q.empty()) {
    tp = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      tx = tp.first + dx[i];
      ty = tp.second + dy[i];
      if (tx >= 0 and tx < row and ty >= 0 and ty < col and
          (level[tx][ty] == -1 or
           level[tx][ty] > level[tp.first][tp.second] + 1)) {
        level[tx][ty] = level[tp.first][tp.second] + 1;
        q.push(make_pair(tx, ty));
      }
    }
  }
}
int main() {
  int a, pre, now;
  pair<int, int> tp;
  scanf("%d %d", &row, &col);
  scanf("%d", &cl);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d", &a);
      color[a].push_back(make_pair(i, j));
      if (a == 1) dp[i][j] = i + j;
      if (a == cl) tp = make_pair(i, j);
    }
  }
  for (int i = 2; i <= cl; i++) {
    now = color[i].size();
    pre = color[i - 1].size();
    if (now * pre < row * col) {
      int mn = 1800000000;
      for (int j = 0; j < now; j++) {
        mn = 1800000000;
        for (int k = 0; k < pre; k++) {
          mn = min(mn, dp[color[i - 1][k].first][color[i - 1][k].second] +
                           abs(color[i][j].first - color[i - 1][k].first) +
                           abs(color[i][j].second - color[i - 1][k].second));
        }
        dp[color[i][j].first][color[i][j].second] = mn;
      }
    } else {
      bfs(i - 1);
      for (int j = 0; j < now; j++)
        dp[color[i][j].first][color[i][j].second] =
            level[color[i][j].first][color[i][j].second];
    }
  }
  deb(dp[tp.first][tp.second]);
  return 0;
}
