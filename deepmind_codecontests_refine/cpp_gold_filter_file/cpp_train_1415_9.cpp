#include <bits/stdc++.h>
constexpr int P = 1e9 + 7, N = 2e5 + 10;
inline void upd(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
struct SegmentTree {
  struct Info {
    int c[6];
    Info() { std::fill(c, c + 6, 0); }
    int operator[](int i) const { return c[i]; }
    int &operator[](int i) { return c[i]; }
    friend Info operator+(const Info &a, const Info &b) {
      Info res;
      for (int i = 0; i < 6; ++i) res[i] = (a[i] + b[i]) % P;
      upd(res[3], 1ll * a[0] * b[1] % P);
      upd(res[4], 1ll * a[1] * b[2] % P);
      upd(res[5], 1ll * a[0] * b[4] % P);
      upd(res[5], 1ll * a[3] * b[2] % P);
      return res;
    }
  };
  struct Node {
    int lc, rc;
    Info c;
    Node() {
      lc = rc = 0;
      c = Info();
    }
  } t[N * 23];
  int cnt;
  int newNode() {
    int u = ++cnt;
    t[cnt] = Node();
    return u;
  }
  SegmentTree() { cnt = 0; }
  void pushup(int x) { t[x].c = t[t[x].lc].c + t[t[x].rc].c; }
  void modify(int &x, int l, int r, int p, int vi, int vj, int vk) {
    if (!x) x = newNode();
    if (l == r) {
      t[x].c[0] = vi;
      upd(t[x].c[1], vj);
      t[x].c[2] = vk;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      modify(t[x].lc, l, mid, p, vi, vj, vk);
    else
      modify(t[x].rc, mid + 1, r, p, vi, vj, vk);
    pushup(x);
  }
} st;
int fw[N];
void mdf(int x, int v = 1) {
  for (; x < N; x += x & -x) upd(fw[x], v);
}
int qry(int x) {
  int ans = 0;
  for (; x; x -= x & -x) upd(ans, fw[x]);
  return ans;
}
int rt[N], n, q, a[N], b[N], pre[N], suf[N];
int val[N], tot;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    val[i] = a[i];
  }
  std::sort(val + 1, val + n + 1);
  tot = std::unique(val + 1, val + n + 1) - val - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = std::lower_bound(val + 1, val + tot + 1, a[i]) - val;
  std::fill(fw, fw + tot + 1, 0);
  for (int i = 1; i <= n; ++i) {
    pre[i] = qry(a[i]);
    mdf(a[i]);
  }
  std::fill(fw, fw + tot + 1, 0);
  for (int i = n; i >= 1; --i) {
    suf[i] = qry(a[i]);
    mdf(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    st.modify(rt[a[i]], 1, n, i, pre[i], 1, suf[i]);
  }
  int ans = 0;
  for (int i = 1; i <= tot; ++i) upd(ans, st.t[rt[i]].c[5]);
  std::cin >> q;
  while (q--) {
    int opt, x;
    std::cin >> opt >> x;
    int vi, vj, vk;
    if (opt == 1)
      vi = 0, vj = P - 1, vk = 0;
    else
      vi = pre[x], vj = 1, vk = suf[x];
    upd(ans, P - st.t[rt[a[x]]].c[5]);
    st.modify(rt[a[x]], 1, n, x, vi, vj, vk);
    upd(ans, st.t[rt[a[x]]].c[5]);
    std::cout << ans << '\n';
  }
  return 0;
}
