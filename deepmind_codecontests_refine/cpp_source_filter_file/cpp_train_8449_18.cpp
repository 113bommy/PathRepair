#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 998244353;
using namespace std;
template <class T>
struct Dinic {
  static const int N = 10101, M = N * 200;
  int s, t, n, h[N], cur[N], lv[N], q[N], e, ne[M], to[M];
  T cap[M], flow;
  void liu(int u, int v, T w) {
    to[e] = v, ne[e] = h[u], cap[e] = w;
    h[u] = e++;
  }
  void link(int u, int v, T w) {
    liu(u, v, w);
    liu(v, u, 0);
  }
  void init(int _n = N) {
    fill(h, h + (n = _n), -1);
    e = 0;
  }
  bool bfs() {
    int L = 0, R = 0;
    fill(lv, lv + n, -1);
    lv[q[R++] = s] = 0;
    while (L < R && !~lv[t]) {
      int c = q[L++];
      for (int k = h[c]; ~k; k = ne[k]) {
        if (cap[k] > 0 && !~lv[to[k]]) lv[q[R++] = to[k]] = lv[c] + 1;
      }
    }
    return ~lv[t];
  }
  T dfs(int c, T mx) {
    if (c == t) return mx;
    T ret = 0;
    for (int &k = cur[c]; ~k; k = ne[k]) {
      if (lv[to[k]] == lv[c] + 1 && cap[k] > 0) {
        T flow = dfs(to[k], min(mx, cap[k]));
        ret += flow;
        cap[k] -= flow;
        cap[k ^ 1] += flow;
        mx -= flow;
        if (!mx) return ret;
      }
    }
    lv[c] = -1;
    return ret;
  }
  T run(int _s, int _t) {
    s = _s, t = _t;
    flow = 0;
    while (bfs()) {
      copy(h, h + n, cur);
      flow += dfs(s, ~0U >> 1);
    }
    return flow;
  }
};
Dinic<int> G;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> xa(m), ya(m), xb(m), yb(m), xs = {0, n}, ys = {0, n};
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d%d", &xa[i], &ya[i], &xb[i], &yb[i]);
    --xa[i], --ya[i];
    xs.push_back(xa[i]), xs.push_back(xb[i]);
    ys.push_back(ya[i]), ys.push_back(yb[i]);
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
  ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
  int nx = xs.size() - 1, ny = ys.size() - 1, s = nx + ny, t = s + 1;
  G.init();
  for (int i = 0; i < nx; ++i) G.link(s, i, xs[i + 1] - xs[i]);
  for (int i = 0; i < ny; ++i) G.link(nx + i, t, ys[i + 1] - ys[i]);
  for (int i = 0; i < nx; ++i)
    for (int j = 0; j < ny; ++j) {
      bool f = 0;
      for (int k = 0; k < m; ++k) {
        if (xa[k] <= xs[i] && xs[i + 1] <= xb[k] && ya[k] <= ys[j] &&
            ys[j + 1] <= yb[k])
          f = 1, k = m;
      }
      if (f) G.link(i, j + nx, min(xs[i + 1] - xs[i], ys[i + 1] - ys[i]));
    }
  printf("%d\n", G.run(s, t));
  return 0;
}
