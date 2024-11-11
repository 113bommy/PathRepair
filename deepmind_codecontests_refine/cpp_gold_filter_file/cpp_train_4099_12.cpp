#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> x, y;
char dir[1005];
int len[1005];
int mat[3105][3105];
bool fll[3105][3105];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int N, M;
void dfs(int x, int y) {
  fll[y][x] = 1;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= M) continue;
    if (ny < 0 || ny >= N) continue;
    if (mat[ny][nx]) continue;
    if (fll[ny][nx]) continue;
    dfs(nx, ny);
  }
}
int tt[300];
int getIdx(long long v, vector<long long> &vv) {
  return lower_bound(vv.begin(), vv.end(), v) - vv.begin();
}
void insert(vector<long long> &v, long long t) {
  v.push_back(t - 1);
  v.push_back(t);
  v.push_back(t + 1);
}
int main() {
  tt['U'] = 3;
  tt['D'] = 1;
  tt['R'] = 0;
  tt['L'] = 2;
  scanf("%d", &n);
  x.push_back(-(1ll << 60)), y.push_back(-(1ll << 60));
  int curX = (1 << 30), curY = (1 << 30);
  insert(x, curX), insert(y, curY);
  for (int i = 0; i < n; ++i) {
    char tmp[5];
    int v;
    scanf("%s%d", tmp, &v);
    dir[i] = tt[tmp[0]], len[i] = v;
    curX += dx[dir[i]] * v;
    curY += dy[dir[i]] * v;
    insert(x, curX), insert(y, curY);
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  sort(y.begin(), y.end());
  y.erase(unique(y.begin(), y.end()), y.end());
  M = x.size(), N = y.size();
  curX = curY = (1 << 30);
  for (int i = 0; i < n; ++i) {
    int nxtX = dx[dir[i]] * len[i] + curX;
    int nxtY = dy[dir[i]] * len[i] + curY;
    int x1 = getIdx(min(curX, nxtX), x);
    int x2 = getIdx(max(curX, nxtX) + 1, x);
    int y1 = getIdx(min(curY, nxtY), y);
    int y2 = getIdx(max(curY, nxtY) + 1, y);
    if (curX == nxtX) {
      for (int j = y1; j < y2; ++j) mat[j][x1] = 1;
    } else {
      for (int j = x1; j < x2; ++j) mat[y1][j] = 1;
    }
    curX = nxtX, curY = nxtY;
  }
  dfs(0, 0);
  long long ans = 0;
  for (int i = 0; i < N - 1; ++i)
    for (int j = 0; j < M - 1; ++j)
      if (!fll[i][j]) {
        ans += (y[i + 1] - y[i]) * (x[j + 1] - x[j]);
      }
  printf("%lld\n", ans);
}
