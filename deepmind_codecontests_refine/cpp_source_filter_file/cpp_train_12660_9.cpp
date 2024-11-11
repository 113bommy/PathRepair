#include <bits/stdc++.h>
using namespace std;
char mmap[255][255];
long long ans[255][255];
bool vis[255][255];
long long tmp[255][255];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main() {
  long long n, m, q, p;
  scanf("%lld%lld%lld%lld", &n, &m, &q, &p);
  for (int i = 0; i < n; i++) scanf("%s", mmap[i]);
  queue<pair<int, int> > que;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mmap[i][j] == '*') continue;
      if (mmap[i][j] <= 'Z' && mmap[i][j] >= 'A') {
        long long ttmp = ((long long)(mmap[i][j] - 'A') + 1) * q;
        int num = log2(ttmp);
        for (int k = 1; k <= num && j + k < m; k++) vis[i][j + k] = 0;
        for (int k = 1; k <= num && j - k >= 0; k++) vis[i][j - k] = 0;
        for (int kk = 1; kk <= num && i + kk < n; kk++) {
          for (int k = 0; k <= num - kk && j + k < m; k++)
            vis[i + kk][j + k] = 0;
          for (int k = 0; k <= num - kk && j - k >= 0; k++)
            vis[i + kk][j - k] = 0;
        }
        for (int kk = 1; kk <= num && i - kk >= 0; kk++) {
          for (int k = 0; k <= num - kk && j + k < m; k++)
            vis[i - kk][j + k] = 0;
          for (int k = 0; k <= num - kk && j - k >= 0; k++)
            vis[i - kk][j - k] = 0;
        }
        ans[i][j] += ttmp;
        tmp[i][j] = ttmp;
        vis[i][j] = 1;
        que.push(make_pair(i, j));
        while (que.size()) {
          pair<int, int> t = que.front();
          que.pop();
          int x = t.first;
          int y = t.second;
          for (int tt = 0; tt < 4; tt++) {
            int nowx = x + dx[tt];
            int nowy = y + dy[tt];
            if (!vis[nowx][nowy] && nowx >= 0 && nowx < n && nowy >= 0 &&
                nowx < m && mmap[nowx][nowy] != '*') {
              vis[nowx][nowy] = 1;
              ans[nowx][nowy] += tmp[x][y] / 2;
              tmp[nowx][nowy] = tmp[x][y] / 2;
              if (tmp[nowx][nowy] >= 2) {
                que.push(make_pair(nowx, nowy));
              }
            }
          }
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (ans[i][j] > p) cnt++;
    }
  printf("%d\n", cnt);
  return 0;
}
