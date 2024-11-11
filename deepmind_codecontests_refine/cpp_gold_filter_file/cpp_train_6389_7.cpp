#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
inline int read() {
  char c = getchar();
  int t = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    t = (t << 3) + (t << 1) + (c ^ 48);
    c = getchar();
  }
  return t * f;
}
int n, m, N;
struct tree {
  int sum[maxn << 2];
  inline void pushup(int rt) { sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]); }
  void update(int rt, int l, int r, int pos, int v) {
    if (l == r) {
      sum[rt] = v;
      return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
      update(rt << 1, l, mid, pos, v);
    else
      update(rt << 1 | 1, mid + 1, r, pos, v);
    pushup(rt);
  }
  int query(int rt, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
      return sum[rt];
    }
    int mid = l + r >> 1;
    int res = 0;
    if (x <= mid) {
      res = max(res, query(rt << 1, l, mid, x, y));
    }
    if (y > mid) {
      res = max(res, query(rt << 1 | 1, mid + 1, r, x, y));
    }
    return res;
  }
} xt, yt;
int pl[maxn], h[maxn], ans;
priority_queue<pair<int, int> > x, y;
stack<pair<int, int> > xa, ya;
bool vis[maxn];
int main() {
  n = read();
  m = read();
  N = m + 20;
  int k, X;
  for (int i = 1; i <= m; i++) {
    k = read();
    if (k == 1) {
      pl[i] = read(), h[i] = read();
      x.push(pair<int, int>(-pl[i], i));
      h[i] += m - i;
      while (!y.empty()) {
        if (-y.top().first <= h[i]) {
          if (!vis[pl[y.top().second]]) ya.push(y.top());
          yt.update(1, 1, n, pl[y.top().second], 0);
          y.pop();
        } else
          break;
      }
      ya.push(pair<int, int>(-h[i], i));
      while (!ya.empty()) {
        y.push(ya.top());
        ya.pop();
        int Y = yt.query(1, 1, n, pl[y.top().second] + 1, n) + 1;
        xt.update(1, 1, N, -y.top().first, Y);
        yt.update(1, 1, n, pl[y.top().second], Y);
      }
      ans = yt.sum[1];
    } else {
      X = read();
      while (X) {
        X--;
        if (X) {
          xa.push(x.top());
          x.pop();
          xt.update(1, 1, N, h[xa.top().second], 0);
        } else
          break;
      }
      yt.update(1, 1, n, -x.top().first, 0);
      xt.update(1, 1, N, h[x.top().second], 0);
      vis[-x.top().first] = 1;
      x.pop();
      while (!xa.empty()) {
        x.push(xa.top());
        xa.pop();
        int Y = xt.query(1, 1, N, h[x.top().second] + 1, N) + 1;
        yt.update(1, 1, n, -x.top().first, Y);
        xt.update(1, 1, N, h[x.top().second], Y);
      }
      ans = xt.sum[1];
    }
    printf("%d\n", ans);
  }
  return 0;
}
