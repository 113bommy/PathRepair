#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
signed long long GETi() {
  signed long long i;
  scanf("%lld", &i);
  return i;
}
int N, M;
string S[2];
const int sp = 1000;
signed long long dist[2][300000][2][2];
signed long long distsp[300000 / sp][2][2];
void dfs(int type, int sx, int sy) {
  int i;
  if (S[sy][sx] == 'X') return;
  dist[type][sx][sy][sy] = 0;
  queue<int> Q;
  Q.push(sx * 2 + sy);
  while (!Q.empty()) {
    int cx = Q.front() / 2;
    int cy = Q.front() % 2;
    Q.pop();
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    for (i = 0; i < 4; i++) {
      int tx = cx + dx[i];
      int ty = cy + dy[i];
      if (tx < 0 || tx >= N || ty < 0 || ty >= 2) continue;
      if (type == 0 && (tx >= sx + sp || tx < sx)) continue;
      if (type == 1 && (tx > sx || tx <= sx - sp)) continue;
      if (S[ty][tx] == 'X') continue;
      if (dist[type][tx][sy][ty] <= dist[type][cx][sy][cy] + 1) continue;
      dist[type][tx][sy][ty] = dist[type][cx][sy][cy] + 1;
      Q.push(tx * 2 + ty);
    }
  }
}
signed long long dfs2(int sx, int sy, int gx, int gy) {
  int x, y, i;
  int dis[sp][2];
  if (sx == gx && sy == gy) return 0;
  for (x = 0; x < 2; x++)
    for (y = 0; y < sp; y++) dis[y][x] = sp * 5;
  dis[0][sy] = 0;
  queue<int> Q;
  Q.push(sx * 2 + sy);
  while (!Q.empty()) {
    int cx = Q.front() / 2;
    int cy = Q.front() % 2;
    Q.pop();
    int dx[3] = {1, 0, 0}, dy[3] = {0, 1, -1};
    for (i = 0; i < 3; i++) {
      int tx = cx + dx[i];
      int ty = cy + dy[i];
      if (tx > gx || ty < 0 || ty >= 2) continue;
      if (S[ty][tx] == 'X') continue;
      if (dis[tx - sx][ty] <= dis[cx - sx][cy] + 1) continue;
      dis[tx - sx][ty] = dis[cx - sx][cy] + 1;
      if (tx == gx && ty == gy) return dis[cx - sx][cy] + 1;
      Q.push(tx * 2 + ty);
    }
  }
  return 1LL << 40;
}
void solve() {
  int f, i, j, k, l, x, y;
  cin >> N >> M;
  cin >> S[0] >> S[1];
  for (i = 0; i < 2; i++)
    for (x = 0; x < 2; x++)
      for (y = 0; y < 2; y++)
        for (k = 0; k < 300000; k++) dist[i][k][x][y] = 1LL << 40;
  for (i = 0; i < N; i += sp) dfs(0, i, 0), dfs(0, i, 1);
  for (i = 0; i < N; i += sp) dfs(1, i, 0), dfs(1, i, 1);
  for (i = 0; i < N / sp + 1; i++) {
    if (i == 0 || i * sp >= N) continue;
    distsp[i][0][0] = distsp[i][0][1] = distsp[i][1][0] = distsp[i][1][1] =
        1LL << 40;
    if (S[0][i * sp] == '.') {
      distsp[i][0][0] =
          min(dist[0][i * sp - 1][0][0] + dist[1][i * sp - 1][0][0],
              dist[0][i * sp - 1][0][1] + dist[1][i * sp - 1][0][1]);
      distsp[i][1][0] =
          min(dist[0][i * sp - 1][1][0] + dist[1][i * sp - 1][0][0],
              dist[0][i * sp - 1][1][1] + dist[1][i * sp - 1][0][1]);
    }
    if (S[1][i * sp] == '.') {
      distsp[i][0][1] =
          min(dist[0][i * sp - 1][0][0] + dist[1][i * sp - 1][1][0],
              dist[0][i * sp - 1][0][1] + dist[1][i * sp - 1][1][1]);
      distsp[i][1][1] =
          min(dist[0][i * sp - 1][1][0] + dist[1][i * sp - 1][1][0],
              dist[0][i * sp - 1][1][1] + dist[1][i * sp - 1][1][1]);
    }
  }
  for (i = 0; i < M; i++) {
    cin >> x >> y;
    int sx = (x - 1) % N;
    int sy = (x - 1) / N;
    int gx = (y - 1) % N;
    int gy = (y - 1) / N;
    if (gx < sx) swap(sx, gx), swap(sy, gy);
    signed long long ret = 0;
    if (sx / sp == gx / sp) {
      ret = dfs2(sx, sy, gx, gy);
    } else {
      int tx = (sx + (sp - 1)) / sp * sp;
      signed long long hoge[2];
      hoge[0] = dist[1][sx][0][sy];
      hoge[1] = dist[1][sx][1][sy];
      while (tx + sp <= gx) {
        signed long long nhoge[2];
        nhoge[0] = min(hoge[0] + distsp[tx / sp + 1][0][0],
                       hoge[1] + distsp[tx / sp + 1][1][0]);
        nhoge[1] = min(hoge[0] + distsp[tx / sp + 1][0][1],
                       hoge[1] + distsp[tx / sp + 1][1][1]);
        hoge[0] = nhoge[0];
        hoge[1] = nhoge[1];
        tx += sp;
      }
      ret = min(hoge[0] + dist[0][gx][0][gy], hoge[1] + dist[0][gx][1][gy]);
    }
    if (ret >= 1LL << 40)
      (void)printf("-1\n");
    else
      (void)printf("%lld\n", ret);
  }
}
int main(int argc, char** argv) {
  string s;
  if (argc == 1) ios::sync_with_stdio(false);
  for (int i = 1; i < argc; i++) s += argv[i], s += '\n';
  for (int i = s.size() - 1; i >= 0; i--) ungetc(s[i], stdin);
  solve();
  return 0;
}
