#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int n, m, ans;
int head[MAXN][2];
struct Tnode {
  int v, l, r;
  Tnode() {}
  Tnode(int vv, int ll, int rr) {
    v = vv;
    l = ll;
    r = rr;
  }
  friend bool operator<(Tnode A, Tnode B) { return A.l < B.l; }
};
vector<Tnode> way[MAXN][2];
struct Tp {
  int x, y;
  Tp() {}
  Tp(int xx, int yy) {
    x = xx;
    y = yy;
  }
  friend bool operator<(Tp A, Tp B) { return A.y > B.y; }
};
priority_queue<Tp> q;
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v, l, r;
    scanf("%d%d%d%d", &u, &v, &l, &r);
    for (int j = 0; j < 2; ++j) {
      way[u][j].push_back(Tnode(v, l, r));
      way[v][j].push_back(Tnode(u, l, r));
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 2; ++j) sort(way[i][j].begin(), way[i][j].end());
}
int dij() {
  int now, tim, xx, yy;
  q.push(Tp(1, 0));
  while (!q.empty()) {
    xx = q.top().x;
    yy = now = q.top().y;
    tim = yy & 1;
    q.pop();
    if (xx == n) return yy;
    for (int j = head[xx][tim]; j < way[xx][tim].size(); ++j) {
      Tnode w = way[xx][tim][j];
      if (w.l > now) break;
      head[xx][tim] = j + 1;
      if (w.r < yy) continue;
      now = max(now, w.r);
      if (now - tim & 1) --now;
      int tmp = max(w.l, yy);
      if (tmp % 2 != tim) ++tmp;
      if (tmp + 1 <= w.r && tmp >= w.l) q.push(Tp(w.v, tmp + 1));
    }
  }
  return -1;
}
int main() {
  init();
  printf("%d\n", dij());
  return 0;
}
