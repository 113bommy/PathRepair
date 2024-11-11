#include <bits/stdc++.h>
using namespace std;
map<int, vector<pair<int, int> > > mp;
char a[255][255];
int sum[255][255];
int xx[5] = {1, -1, 0, 0};
int yy[5] = {0, 0, 1, -1};
int n, m;
int vis[255][255];
struct loc {
  int x, y, val;
};
int main() {
  int qq, p;
  cin >> n >> m >> qq >> p;
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
    for (int j = 0; j < m; j++) {
      if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
        mp[a[i][j] - 'A'].push_back(make_pair(i, j));
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
        cnt++;
        vis[i][j] = cnt;
        queue<loc> q;
        q.push(loc{i, j, (int)(a[i][j] - 'A' + 1) * qq});
        while (!q.empty()) {
          int x = q.front().x;
          int y = q.front().y;
          int val = q.front().val;
          q.pop();
          sum[x][y] += val;
          if (val < 2) continue;
          for (int k = 0; k < 4; k++) {
            int nowx = x + xx[k];
            int nowy = y + yy[k];
            if (nowx >= 0 && nowx < n && nowy >= 0 && nowy < m) {
              if (a[nowx][nowy] != '*' && vis[nowx][nowy] != cnt) {
                q.push(loc{nowx, nowy, val / 2});
                vis[nowx][nowy] = cnt;
              }
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (sum[i][j] > p) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
