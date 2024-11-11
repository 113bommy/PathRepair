#include <bits/stdc++.h>
using namespace std;
template <typename OutputIterator>
void input(OutputIterator first, OutputIterator last) {
  while (first != last) cin >> *(first++);
}
template <typename InputIterator>
void output(InputIterator first, InputIterator last, string fs = " ",
            bool newline = 0) {
  while (first != last) cout << *(first++) << fs;
  if (newline) cout << endl;
}
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
int n, m;
long long dis[200009], ds[200009], h[200009];
struct Node {
  int l, r;
  long long ds, hh, ans;
} tree[200009 * 4];
void update(int u) {
  tree[u].ans = max(tree[u * 2].ans, tree[u * 2 + 1].ans);
  tree[u].ans = max(tree[u].ans, tree[u * 2 + 1].hh - tree[u * 2].ds);
  tree[u].ds = min(tree[u * 2].ds, tree[u * 2 + 1].ds);
  tree[u].hh = max(tree[u * 2].hh, tree[u * 2 + 1].hh);
}
void build(int u, int l, int r) {
  tree[u].l = l;
  tree[u].r = r;
  if (l == r) {
    tree[u].ds = ds[l];
    tree[u].hh = h[l];
    tree[u].ans = 0;
    return;
  }
  int mid = l + r >> 1;
  build(u * 2, l, mid);
  build(u * 2 + 1, mid + 1, r);
  update(u);
}
long long cnt(int u, int l, int r, long long &dds, long long &hhh) {
  if (tree[u].l == l && tree[u].r == r) {
    dds = tree[u].ds;
    hhh = tree[u].hh;
    return tree[u].ans;
  }
  int mid = tree[u].l + tree[u].r >> 1;
  if (r <= mid)
    return cnt(u * 2, l, r, dds, hhh);
  else if (l > mid)
    return cnt(u * 2 + 1, l, r, dds, hhh);
  else {
    long long ddsl, hhhl, ddsr, hhhr;
    long long t = max(cnt(u * 2, l, mid, ddsl, hhhl),
                      cnt(u * 2 + 1, mid + 1, r, ddsr, hhhr));
    t = max(t, hhhr - ddsl);
    dds = min(ddsl, ddsr);
    hhh = max(hhhl, hhhr);
    return t;
  }
}
int main() {
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) cin >> dis[i];
  for (int i = (1); i <= (n); ++i) cin >> h[i];
  memcpy(dis + n + 1, dis + 1, sizeof(long long) * n);
  memcpy(h + n + 1, h + 1, sizeof(long long) * n);
  for (int i = 2 * n; i > 1; i--) dis[i] = dis[i - 1];
  dis[1] = 0;
  for (int i = (2); i <= (2 * n); ++i) dis[i] += dis[i - 1];
  for (int i = (1); i <= (2 * n); ++i) ds[i] = dis[i] - h[i] * 2;
  for (int i = (1); i <= (2 * n); ++i) h[i] = h[i] * 2 + dis[i];
  build(1, 1, 2 * n);
  long long tl, tr;
  while (m--) {
    int l, r;
    cin >> l >> r;
    if (l <= r)
      printf("%I64d\n", cnt(1, r + 1, l + n - 1, tl, tr));
    else
      printf("%I64d\n", cnt(1, r + 1, l - 1, tl, tr));
  }
  return 0;
}
