#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxm = maxn * maxn;
int fa[maxm], sz[maxm], vis[maxn][maxn], mp[maxn][maxn], n, m;
long long k;
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
struct GAO {
  int val, x, y;
  GAO() {}
  GAO(int val, int x, int y) : val(val), x(x), y(y) {}
  bool operator<(const GAO& tmp) const { return tmp.val < val; }
};
vector<GAO> q;
void init() {
  for (int i = 0; i < maxn; i++) {
    fa[i] = i;
    sz[i] = 1;
  }
}
int fnd(int x) { return fa[x] == x ? fa[x] : fa[x] = fnd(fa[x]); }
void mrg(int a, int b) {
  a = fnd(a);
  b = fnd(b);
  if (a != b) {
    fa[a] = b;
    sz[b] += sz[a];
  }
}
bool InMap(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
int gao(int val, int x, int y) {
  int now = (x - 1) * m + y;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0];
    int ny = y + dir[i][1];
    if (InMap(nx, ny) && vis[nx][ny]) {
      int nxt = (nx - 1) * m + ny;
      mrg(now, nxt);
    }
  }
  vis[x][y] = 1;
  return sz[fnd(now)];
}
void bfs(int x, int y, int val, int cnt) {
  memset(vis, 0, sizeof vis);
  queue<pair<int, int> > q;
  pair<int, int> now, nxt;
  q.push(make_pair(x, y));
  vis[x][y] = val;
  --cnt;
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (int i = 0; i < 4 && cnt; i++) {
      nxt.first = now.first + dir[i][0];
      nxt.second = now.second + dir[i][1];
      if (InMap(nxt.first, nxt.second) && !vis[nxt.first][nxt.second] &&
          mp[nxt.first][nxt.second] >= val) {
        --cnt;
        vis[nxt.first][nxt.second] = val;
        q.push(nxt);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d%c", vis[i][j], j == m ? '\n' : ' ');
    }
  }
}
int main() {
  init();
  scanf("%d%d%I64d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &mp[i][j]);
      q.push_back(GAO(mp[i][j], i, j));
    }
  }
  sort(q.begin(), q.end());
  int flag = 0;
  for (int i = 0; i < q.size(); i++) {
    int cnt = gao(q[i].val, q[i].x, q[i].y);
    if (k % q[i].val == 0 && cnt >= k / q[i].val) {
      flag = 1;
      puts("YES");
      bfs(q[i].x, q[i].y, q[i].val, k / q[i].val);
      break;
    }
  }
  if (!flag) puts("NO");
  return 0;
}
