#include <bits/stdc++.h>
using namespace std;
void Freopen() {
  freopen(
      "title"
      ".in",
      "r", stdin);
  freopen(
      "title"
      ".out",
      "w", stdout);
}
int read() {
  int g = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    g = g * 10 + ch - '0';
    ch = getchar();
  }
  return g * f;
}
const int N = 2e5 + 5;
int n, m, T, a[N], b[N];
long long p[N];
vector<pair<int, int> > G[N];
struct Seg {
  long long minn[N << 2], tag[N << 2];
  void up(int v) { minn[v] = min(minn[v << 1], minn[v << 1 | 1]); }
  void updata(int v, long long w) {
    minn[v] += w;
    tag[v] += w;
  }
  void down(int v) {
    if (!tag[v]) return void();
    updata(v << 1, tag[v]), updata(v << 1 | 1, tag[v]);
    tag[v] = 0;
  }
  void insert(int v, int l, int r, int ql, int qr, long long w) {
    if (ql <= l && r <= qr) return updata(v, w), void();
    int mid = l + r >> 1;
    down(v);
    if (ql <= mid) insert(v << 1, l, mid, ql, qr, w);
    if (qr > mid) insert(v << 1 | 1, mid + 1, r, ql, qr, w);
    up(v);
  }
} seg;
signed main() {
  n = read(), m = read(), T = read();
  for (int i = (1); i <= (n - 1); i++)
    a[i] = read(), b[i + 1] = read(),
    seg.insert(1, 1, n, i + 1, i + 1, b[i + 1]);
  for (int i = (1); i <= (m); i++) {
    int x = read(), y = read(), w = read();
    G[x].push_back(pair<int, int>(y, w));
  }
  for (int i = (1); i <= (n); i++) {
    for (auto v : G[i]) seg.insert(1, 1, n, 1, v.first, v.second);
    p[i] = seg.minn[1];
  }
  memset(seg.minn, 0, sizeof(seg.minn));
  memset(seg.tag, 0, sizeof(seg.tag));
  for (int i = (1); i <= (n); i++) seg.insert(1, 1, n, i, i, a[i] + p[i]);
  cout << seg.minn[1] << '\n';
  for (int ca = (1); ca <= (T); ca++) {
    int x = read(), w = read();
    seg.insert(1, 1, n, x, x, w - a[x]);
    a[x] = w;
    cout << seg.minn[1] << '\n';
  }
  return signed();
}
