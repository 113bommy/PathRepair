#include <bits/stdc++.h>
using namespace std;
const int N = 20005, M = N << 5;
using ll = long long;
int u[N], v[N], *f = u, *g = v, a[N], rt[N], idx, kk[N], b[N], lc[M], rc[M],
                s[M], st[N];
int Y(int x, int k) { return b[k] + a[k] * x; }
inline int cp(int pos) {
  lc[++idx] = lc[pos];
  rc[idx] = rc[pos];
  s[idx] = s[pos];
  return idx;
}
void modify(int pos, int l, int r, int vv) {
  if (l == r) {
    if (Y(l, vv) < Y(l, s[pos])) s[pos] = vv;
    return;
  }
  int mid = (l + r) >> 1;
  if (Y(mid, vv) < Y(mid, s[pos])) swap(vv, s[pos]);
  if (Y(l, vv) < Y(l, s[pos]))
    modify(lc[pos] = cp(lc[pos]), l, mid, vv);
  else
    modify(rc[pos] = cp(rc[pos]), mid + 1, r, vv);
}
int query(int pos, int l, int r, int p) {
  if (l == r || !p) return Y(p, s[pos]);
  int mid = (l + r) >> 1;
  return min(Y(p, s[pos]), p <= mid ? query(lc[pos], l, mid, p)
                                    : query(rc[pos], mid + 1, r, p));
}
struct ConvexHull {
  deque<int> d;
  void merge(ConvexHull &h) {
    int t = h.d.size() - 1;
    if (h.d.size() > d.size()) {
      for (auto &i : d) {
        while (t && ll(g[i] - g[h.d[t]]) * (h.d[t] - h.d[t - 1]) <=
                        ll(g[h.d[t]] - g[h.d[t - 1]]) * (i - h.d[t]))
          --t, h.d.pop_back();
        ++t;
        h.d.push_back(i);
      }
      swap(h.d, d);
    } else {
      for (int i; t >= 0; --t) {
        i = h.d[t];
        while (d.size() > 1 && ll(g[d[0]] - g[i]) * (d[1] - d[0]) >=
                                   ll(g[d[1]] - g[d[0]]) * (d[0] - i))
          d.pop_front();
        d.push_front(i);
      }
    }
  }
  int query(int kk) {
    int l = 1, r = d.size() - 1, mid;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (g[d[mid]] - g[d[mid - 1]] < ll(kk) * (d[mid] - d[mid - 1]))
        l = mid + 1;
      else
        r = mid - 1;
    }
    return g[d[l - 1]] - (d[l - 1] - 1) * kk;
  }
} h[N];
int main() {
  ios::sync_with_stdio(false);
  int n, m, t;
  cin >> n >> m;
  b[0] = INT_MAX;
  for (int i = 1, j = 0; i <= n; i++)
    cin >> a[i], j = max(j, a[i]), f[i + 1] = i * j;
  for (int i = 2; i <= m; i++) {
    swap(f, g);
    idx = t = 0;
    for (int j = i; j <= n; j++) {
      h[j].d.resize(1);
      h[j].d[0] = j;
      while (t && a[st[t]] < a[j]) h[j].merge(h[st[t--]]);
      rt[j] = cp(rt[st[t]]);
      st[++t] = j;
      b[j] = h[j].query(a[j]);
      modify(idx, 1, n, j);
      f[j + 1] = query(rt[j], 1, n, j);
    }
  }
  cout << f[n + 1] << endl;
  return 0;
}
