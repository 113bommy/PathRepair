#include <bits/stdc++.h>
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
using namespace std;
int n, a[N], m, c[N], ans[N], rt[N], cnt;
struct Tree {
  int v, l, r;
} t[N << 5];
vector<pair<int, int> > vec[N];
template <typename T>
inline T read() {
  T x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * w;
}
int lowbit(int x) { return x & -x; }
void add(int x, int y) {
  for (int i = x; i; i -= lowbit(i)) c[i] = min(c[i], y);
}
int ask(int x) {
  int res = INF;
  for (int i = x; i <= n; i += lowbit(i)) res = min(res, c[i]);
  return res;
}
void modify(int &p, int o, int l, int r, int k, int x) {
  t[p = ++cnt] = t[o];
  t[p].v = max(t[p].v, x);
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (k <= mid)
    modify(t[p].l, t[o].l, l, mid, k, x);
  else
    modify(t[p].r, t[o].r, mid + 1, r, k, x);
}
int query(int p, int l, int r, int ql, int qr) {
  if (!p || ql > qr || l > r) return 0;
  if (ql <= l && r <= qr) return t[p].v;
  int mid = (l + r) >> 1;
  int ans = 0;
  if (ql <= mid) ans = query(t[p].l, l, mid, ql, qr);
  if (mid < qr) ans = max(ans, query(t[p].r, mid + 1, r, ql, qr));
  return ans;
}
void solve() {
  for (int i = 1; i <= n; i++) c[i] = INF;
  cnt = 0, memset(rt, 0, sizeof(rt));
  for (int i = 1; i <= n; i++) modify(rt[i], rt[i - 1], 0, INF, a[i], i);
  for (int pos, i = 1; i <= n; i++) {
    pos = query(rt[i - 1], 0, INF, a[i], INF);
    while (pos) {
      add(pos, a[pos] - a[i]);
      pos = query(rt[i - 1], 0, INF, a[i],
                  ((a[i] + a[pos]) >> 1) - (((a[i] + a[pos]) & 1) ^ 1));
    }
    for (int j = 0; j < vec[i].size(); j++)
      ans[vec[i][j].second] = min(ans[vec[i][j].second], ask(vec[i][j].first));
  }
}
int main() {
  n = read<int>();
  for (int i = 1; i <= n; i++) a[i] = read<int>();
  m = read<int>();
  for (int l, r, i = 1; i <= m; i++) {
    l = read<int>(), r = read<int>();
    ans[i] = INF, vec[r].push_back(make_pair(l, i));
  }
  solve();
  for (int i = 1; i <= n; i++) a[i] = INF - a[i];
  solve();
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
