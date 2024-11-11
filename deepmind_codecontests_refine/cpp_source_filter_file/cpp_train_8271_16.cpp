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
const int N = 4e3 + 5;
const int M = 2e4 + 5;
const int maxn = 4e3;
const int maxd = 2e4;
int n, p, st[N][N], top, f[N], ans[N], q;
vector<pair<int, int> > G[M];
struct Seg {
  vector<pair<int, int> > S[M << 2];
  void insert(int v, int l, int r, int ql, int qr, pair<int, int> a) {
    if (ql <= l && r <= qr) return S[v].push_back(a), void();
    int mid = l + r >> 1;
    if (ql <= mid) insert(v << 1, l, mid, ql, qr, a);
    if (qr > mid) insert(v << 1 | 1, mid + 1, r, ql, qr, a);
  }
  void solve(int v, int l, int r) {
    int bot = top;
    for (int i = (0); i <= (maxn); i++) st[top][i] = f[i];
    top++;
    for (auto t : S[v])
      for (int i = (maxn); i >= (t.first); i--)
        f[i] = max(f[i], f[i - t.first] + t.second);
    if (l == r) {
      for (auto t : G[l]) ans[t.second] = f[t.first];
      top = bot;
      for (int i = (0); i <= (maxn); i++) f[i] = st[top][i];
      return void();
    }
    int mid = l + r >> 1;
    solve(v << 1, l, mid), solve(v << 1 | 1, mid + 1, r);
    top = bot;
    for (int i = (0); i <= (maxn); i++) f[i] = st[top][i];
  }
} seg;
signed main() {
  n = read(), p = read();
  for (int i = (1); i <= (n); i++) {
    int c = read(), h = read(), t = read();
    seg.insert(1, 1, maxd, t, t + p - 1, pair<int, int>(c, h));
  }
  q = read();
  for (int i = (1); i <= (q); i++) {
    int x = read(), y = read();
    G[x].push_back(pair<int, int>(y, i));
  }
  seg.solve(1, 1, maxd);
  for (int i = (1); i <= (q); i++) cout << ans[i] << '\n';
  return signed();
}
