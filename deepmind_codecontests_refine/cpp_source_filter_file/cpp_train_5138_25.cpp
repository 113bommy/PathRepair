#include <bits/stdc++.h>
using namespace std;
struct node {
  int f, ch[2], x, y;
  void Init(int _x, int _y, int _f) {
    x = _x;
    f = _f;
    ch[0] = ch[1] = 0;
    y = _y;
  }
} pt[1020304];
int now = 0;
struct Splay {
  int root;
  void Init() { root = 0; }
  void zig(int x, bool w) {
    int y = pt[x].f;
    if (root == y) root = x;
    pt[y].ch[!w] = pt[x].ch[w];
    if (pt[x].ch[w]) pt[pt[x].ch[w]].f = y;
    pt[x].f = pt[y].f;
    if (root != x) pt[pt[x].f].ch[y == pt[pt[y].f].ch[1]] = x;
    pt[x].ch[w] = y;
    pt[y].f = x;
  }
  void splay(int x) {
    while (root != x) {
      if (root == pt[x].f)
        zig(x, x == pt[root].ch[0]);
      else {
        int y = pt[x].f, z = pt[y].f;
        if (y == pt[z].ch[0])
          if (x == pt[y].ch[0]) {
            zig(y, 1);
            zig(x, 1);
          } else {
            zig(x, 0);
            zig(x, 1);
          }
        else if (x == pt[y].ch[0]) {
          zig(x, 1);
          zig(x, 0);
        } else {
          zig(y, 0);
          zig(x, 0);
        }
      }
    }
  }
  void Ins(int x, int y) {
    if (root == 0) {
      pt[root = ++now].Init(x, y, 0);
      return;
    }
    int t = root;
    bool s;
    while (1) {
      if (pt[t].ch[s = x > pt[t].x] == 0)
        break;
      else
        t = pt[t].ch[s];
    }
    ++now;
    pt[now].Init(x, y, t);
    pt[t].ch[s] = now;
    splay(now);
  }
  void Del(int t) {
    while (pt[t].ch[0] + pt[t].ch[1])
      if (pt[t].ch[0])
        zig(pt[t].ch[0], 1);
      else
        zig(pt[t].ch[1], 0);
    if (root == t) {
      root = 0;
      return;
    }
    pt[pt[t].f].ch[t == pt[pt[t].f].ch[1]] = 0;
    splay(pt[t].f);
  }
  int Ask(bool w) {
    int t = root;
    while (pt[t].ch[w]) t = pt[t].ch[w];
    return t;
  }
  pair<int, int> lb(int t, int k) {
    if (t == 0) return make_pair((0x3f3f3f3f), (0x3f3f3f3f));
    pair<int, int> ret =
        make_pair((k <= pt[t].x) ? pt[t].x : ((0x3f3f3f3f)), t);
    if (k > pt[t].x)
      return lb(pt[t].ch[1], k);
    else
      return min(ret, lb(pt[t].ch[0], k));
  }
} T;
int n, x[1020304], a[1020304], y[1020304], k[1020304], m[1020304];
int cur[1020304];
pair<int, int> res[1020304];
int main() {
  cin >> n;
  int s = 0;
  for (int i = 1; i <= n; ++i)
    scanf("%d%d%d%d%d", &k[i], &a[i], &x[i], &y[i], &m[i]), s += k[i],
        cur[i] = 1;
  T.Init();
  for (int i = 1; i <= n; ++i) T.Ins(a[i], i);
  int p = 0;
  int lst = -1;
  int Tot = 0, ans = 0;
  while (p < s) {
    int t = T.lb(T.root, lst).second;
    if (t == (0x3f3f3f3f)) t = T.Ask(0), ++ans;
    lst = pt[t].x;
    if (Tot < 200000) res[++Tot] = make_pair(pt[t].x, pt[t].y);
    ++p;
    if (cur[pt[t].y] < k[pt[t].y])
      T.Ins(((long long)pt[t].x * x[pt[t].y] + y[pt[t].y]) % m[pt[t].y],
            pt[t].y),
          ++cur[pt[t].y];
    T.Del(t);
  }
  cout << ans << endl;
  if (Tot <= 200000)
    for (int i = 1; i <= Tot; ++i)
      printf("%d %d\n", res[i].first, res[i].second);
  return 0;
}
