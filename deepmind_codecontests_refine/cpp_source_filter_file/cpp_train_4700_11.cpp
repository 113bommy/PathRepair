#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 1e5 + 5;
int n, k, a[MN];
vi g[MN];
int tin[MN], tout[MN], tt;
template <typename T>
struct SegmentTree {
  T t[MN * 4], lz[MN * 4];
  const T ID = 0;
  T merge(T x, T y) { return max(x, y); }
  void push(int i, int l, int r) {
    if (lz[i]) {
      t[i] += lz[i];
      if (l != r) {
        lz[(i << 1)] += lz[i];
        lz[(i << 1 | 1)] += lz[i];
      }
      lz[i] = 0;
    }
  }
  void upd(int ql, int qr, int v, int i = 1, int l = 1, int r = n + 1) {
    push(i, l, r);
    if (l > qr || r < ql || ql > qr) return;
    if (l >= ql && r <= qr) {
      lz[i] += v, push(i, l, r);
      return;
    }
    int m = (l + r) / 2;
    upd(ql, qr, v, (i << 1), l, m), upd(ql, qr, v, (i << 1 | 1), m + 1, r);
    t[i] = merge(t[(i << 1)], t[(i << 1 | 1)]);
  }
  T get(int ql, int qr, int i = 1, int l = 1, int r = n + 1) {
    push(i, l, r);
    if (l > qr || r < ql) return ID;
    if (l >= ql && r <= qr) return t[i];
    int m = (l + r) / 2;
    return merge(get(ql, qr, (i << 1), l, m),
                 get(ql, qr, (i << 1 | 1), m + 1, r));
  }
};
SegmentTree<int> seg;
void ett(int u) {
  tin[u] = ++tt;
  for (int v : g[u]) ett(v);
  tout[u] = tt;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  stack<int> s;
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && a[i] >= a[s.top()]) s.pop();
    int nxt = s.empty() ? n : s.top();
    g[nxt].push_back(i);
    s.push(i);
  }
  ett(n);
  for (int i = 0; i < k - 1; i++) seg.upd(tin[i], tout[i], 1);
  for (int i = k - 1; i < n; i++) {
    seg.upd(tin[i], tout[i], 1);
    cout << seg.get(1, n) << " ";
    seg.upd(tin[i - k + 1], tout[i - k + 1], -1);
  }
  return 0;
}
