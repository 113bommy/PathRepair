#include <bits/stdc++.h>
using namespace std;
char b[20][20 + 1];
int val[8];
int dis[20][20][1 << 8];
struct state {
  int i, j, msk;
  state() {}
  state(int i, int j, int msk) : i(i), j(j), msk(msk) {}
};
int rv[] = {-1, 1, 0, 0};
int cv[] = {0, 0, 1, -1};
struct point {
  int x, y;
  point(){};
  point(int x, int y) : x(x), y(y) {}
  point operator-(point a) { return point(x - a.x, y - a.y); }
  int operator^(point a) { return x * a.y - y * a.x; }
};
const point FAR(42, 43);
point o_pos[8];
int sgn(int x) { return (x > 0) - (x < 0); }
int cross_segment(point a, point b, point p, point q) {
  return sgn((b - a) ^ (p - a)) * sgn((b - a) ^ (q - a)) < 0 &&
         sgn((p - q) ^ (a - q)) * sgn((p - q) ^ (b - q)) < 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int nt = 0, nb = 0;
  int si, sj;
  for (int i = 0; i < n; ++i) {
    scanf("%s", b[i]);
    for (int j = 0; j < m; ++j) {
      if (isdigit(b[i][j])) {
        o_pos[b[i][j] - '1'] = point(j, i);
        ++nt;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j] == 'B') {
        o_pos[nt + nb] = point(j, i);
        ++nb;
      } else if (b[i][j] == 'S')
        si = i, sj = j;
    }
  }
  for (int i = 0; i < nt; ++i) scanf("%d", val + i);
  memset(dis, -1, sizeof dis);
  queue<state> q;
  q.push(state(si, sj, 0));
  dis[si][sj][0] = 0;
  while (!q.empty()) {
    int i = q.front().i, j = q.front().j, msk = q.front().msk;
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int ni = i + rv[d], nj = j + cv[d];
      if (0 <= ni && ni < n && 0 <= nj && nj < m &&
          (b[ni][nj] == '.' || b[ni][nj] == 'S')) {
        int nmsk = 0;
        for (int o = 0; o < nt + nb; ++o) {
          nmsk |=
              (msk & (1 << o)) ^
              (cross_segment(o_pos[o], FAR, point(j, i), point(nj, ni)) << o);
        }
        if (dis[ni][nj][nmsk] == -1) {
          dis[ni][nj][nmsk] = dis[i][j][msk] + 1;
          q.push(state(ni, nj, nmsk));
        }
      }
    }
  }
  int ans = 0;
  for (int msk = 1; msk < (1 << nt); ++msk)
    if (dis[si][sj][msk] != -1) {
      int q = 0;
      for (int i = 0; i < nt; ++i)
        if (msk & (1 << i)) q += val[i];
      ans = max(ans, q - dis[si][sj][msk]);
    }
  printf("%d\n", ans);
  return 0;
}
