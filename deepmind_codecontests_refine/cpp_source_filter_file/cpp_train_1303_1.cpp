#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1 << 30;
int n, m;
int ans;
bool vis[N];
int num[N];
struct Frog {
  int id, pos, jump, tim;
  int nxt;
  int lst;
  void upd(int x) {
    if (x <= tim) return;
    pos = (pos + 1LL * jump * (x - tim) - 1) % m + 1;
    tim = x;
  }
} frog[N];
ostream& operator<<(ostream& o, Frog x) {
  o << "id:" << x.id << " pos:" << x.pos << " tim:" << x.tim
    << " jump:" << x.jump << " nxt:" << x.nxt << endl;
}
struct Point {
  int tim;
  int fo, to;
  Point(int x, int y, int z) {
    tim = x;
    fo = y;
    to = z;
  }
};
bool cmp(int x, int y) { return frog[x].pos < frog[y].pos; }
int getdis(int x, int y) { return (y - x + m) % m; }
int cal(Frog x, Frog y) {
  if (x.id < y.id) {
    x.upd(y.tim);
    y.upd(x.tim);
  } else {
    x.upd(y.tim - 1);
    y.upd(x.tim + 1);
  }
  if (getdis(x.pos, y.pos) <= x.jump) return x.tim + 1;
  if (x.jump <= y.jump) return INF;
  return (getdis(x.pos, y.pos) - 1) / (x.jump - y.jump) + 1 + x.tim;
}
struct qcmp {
  bool operator()(Point a, Point b) {
    if (a.tim == b.tim)
      return a.fo > b.fo;
    else
      return a.tim > b.tim;
  }
};
priority_queue<Point, vector<Point>, qcmp> q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    frog[i].id = i;
    frog[i].tim = 0;
    scanf("%d%d", &frog[i].pos, &frog[i].jump);
    num[i] = i;
  }
  sort(num + 1, num + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    frog[num[i]].nxt = num[i % n + 1];
    frog[frog[num[i]].nxt].lst = num[i];
  }
  for (int i = 1; i <= n; i++)
    q.push(Point(cal(frog[i], frog[frog[i].nxt]), i, frog[i].nxt));
  ans = n;
  while (ans >= 2) {
    Point p = q.top();
    q.pop();
    if (p.tim == INF) break;
    int x = p.fo;
    if (vis[x] || frog[x].nxt != p.to) continue;
    int y;
    int jump = frog[x].jump;
    for (y = frog[x].nxt; y != x; y = frog[y].nxt) {
      int t = cal(frog[x], frog[y]);
      if (t == p.tim) {
        ans--;
        vis[y] = 1;
        jump--;
      } else {
        frog[x].upd(p.tim);
        frog[x].jump = max(0, jump);
        frog[x].nxt = y;
        frog[y].lst = x;
        q.push(Point(cal(frog[x], frog[y]), x, y));
        q.push(Point(cal(frog[frog[x].lst], frog[x]), frog[x].lst, x));
        break;
      }
    }
  }
  while (!q.empty()) {
    Point p = q.top();
    q.pop();
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      ans--;
      printf("%d%c", i, ans ? ' ' : 10);
    }
  }
  return 0;
}
