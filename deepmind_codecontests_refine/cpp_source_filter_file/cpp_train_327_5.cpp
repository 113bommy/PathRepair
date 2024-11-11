#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using std::cin;
using std::cout;
using std::string;
using LL = long long;
using db = double;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
const int MAXN = 2e5 + 10;
struct SegTree {
  const int INF = 1e9;
  struct Node {
    int l, r, max, min;
    friend Node operator+(Node x, Node y) {
      if (x.l == -1) return y;
      if (y.l == -1) return x;
      Node res;
      res.l = x.l;
      res.r = y.r;
      res.max = std::max(y.max, x.max);
      res.min = std::min(y.min, x.min);
      return res;
    }
  };
  int M;
  Node T[MAXN * 4];
  void init(int n) {
    for (M = 1; M < n + 10; M <<= 1)
      ;
    for (int i = 0; i < M; ++i) T[M + i] = {i, i, 0, INF};
    for (int i = M - 1; i; --i) T[i] = T[i + i] + T[i + i + 1];
  }
  void modify(int n, int val) {
    T[n + M] = {n, n, val, val};
    for (n += M, n >>= 1; n; n >>= 1) T[n] = T[n + n] + T[n + n + 1];
  }
  Node get(int l, int r, int v = 1) {
    if (T[v].l >= l && T[v].r <= r) return T[v];
    if (T[v].l > r || T[v].r < l) return (Node){-1, -1, 0, INF};
    return get(l, r, v + v) + get(l, r, v + v + 1);
  }
} TX, TY;
std::map<char, int> X, Y;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  TX.init(n + 10), TY.init(n + 10);
  int x = n + 1, y = n + 1;
  TX.modify(1, x), TY.modify(1, y);
  for (int i = 0; i < n; ++i) {
    x += X[s[i]], y += Y[s[i]];
    TX.modify(i + 2, x), TY.modify(i + 2, y);
  }
  SegTree::Node xr = TX.get(1, n + 1), yr = TY.get(1, n + 1);
  int dx = xr.max - xr.min + 1, dy = yr.max - yr.min + 1;
  LL ans = dx * dy;
  for (int i = 2; i < n + 2; ++i) {
    int ax = std::max(TX.get(1, i).max, TX.get(i + 1, n + 1).max - X[s[i - 2]]);
    int bx = std::min(TX.get(1, i).min, TX.get(i + 1, n + 1).min - X[s[i - 2]]);
    int ay = std::max(TY.get(1, i).max, TY.get(i + 1, n + 1).max - Y[s[i - 2]]);
    int by = std::min(TY.get(1, i).min, TY.get(i + 1, n + 1).min - Y[s[i - 2]]);
    ans = std::min(ans, (LL)(ax - bx + 1) * (ay - by + 1));
  }
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  X['W'] = 1, X['S'] = -1, X['A'] = X['D'] = 0;
  Y['D'] = 1, Y['A'] = -1, Y['W'] = Y['S'] = 0;
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
