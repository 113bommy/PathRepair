#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int n, pos[100009], p[100009];
struct Seg_Tree {
  int s[100009 << 2], lazy[100009 << 2];
  void init() {
    for (int i = 0; i < (100009 << 2); i++) lazy[i] = 0, s[i] = 1000000007;
  }
  void inc(int nd, int v) {
    s[nd] += v;
    lazy[nd] += v;
  }
  void shift(int nd) {
    int& ret = lazy[nd];
    if (!ret) return;
    inc(nd << 1 | 1, ret);
    inc(nd << 1, ret);
    ret = 0;
  }
  void upd(int p, int v, int nd = 1, int x = 1, int y = n) {
    if (x == y) {
      s[nd] = v;
      return;
    }
    shift(nd);
    int mid = (x + y) >> 1;
    if (p <= mid)
      upd(p, v, nd << 1, x, mid);
    else
      upd(p, v, nd << 1 | 1, mid + 1, y);
    s[nd] = min(s[nd << 1], s[nd << 1 | 1]);
  }
} die, live;
vector<int> adj[100009];
int main() {
  die.init();
  live.init();
  int x;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x), pos[x] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d", p + i);
    if (pos[p[i]] <= i) {
      die.upd(p[i], i - pos[p[i]]);
      adj[i - pos[p[i]] + 1].push_back(p[i]);
    } else {
      adj[n - pos[p[i]] + 1 + i].push_back(p[i]);
      live.upd(p[i], pos[p[i]] - i);
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d\n", min(die.s[1], live.s[1]));
    bool flag = 0;
    die.inc(1, -1);
    for (typeof((adj[i]).begin()) it = (adj[i]).begin(); it != (adj[i]).end();
         it++) {
      if (p[i] == *it) {
        flag = true;
        die.upd(p[i], n - pos[p[i]]);
      } else {
        die.upd(*it, 1000000007);
        live.upd(*it, 0);
      }
    }
    live.inc(1, +1);
    if (!flag) {
      live.upd(p[i], 1000000007);
      die.upd(p[i], n - pos[p[i]]);
    }
  }
  return 0;
}
