#include <bits/stdc++.h>
using namespace std;
char mapp[12][12];
bool vis[12][12][4];
int dis[4][2] = {0, 1, 1, 1, 1, 0, 1, -1};
bool dfs(int i, int j, int k) {
  int cnt = 4;
  while (cnt--) {
    vis[i][j][k] = 1;
    i += dis[k][0];
    j += dis[k][1];
    if (i < 1 || j < 1 || i > 10 || j > 10 || mapp[i][j] != 'X') return 0;
  }
  return 1;
}
bool judge() {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      if (mapp[i][j] == 'X') {
        for (int k = 0; k < 4; k++) {
          if (!vis[i][j][k]) {
            bool flag = dfs(i, j, k);
            if (flag) return 1;
          }
        }
      }
    }
  }
  return 0;
}
int main() {
  int sum = 0;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      cin >> mapp[i][j];
      if (mapp[i][j] == 'X') sum++;
    }
    getchar();
  }
  if (sum < 4) {
    cout << "NO" << endl;
    return 0;
  }
  bool flag = 0;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      if (mapp[i][j] == '.') {
        mapp[i][j] = 'X';
        if (judge()) {
          cout << "YES" << endl;
          return 0;
        } else
          mapp[i][j] = '.';
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
