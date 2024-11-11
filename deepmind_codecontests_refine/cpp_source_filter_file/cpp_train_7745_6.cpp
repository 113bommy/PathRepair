#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long double PI = 3.1415926535;
const long double eps = 1e-07;
const long long INF = 1e18;
const int inf = 1e9;
const long long M = 305;
const string IO[2]{"NO\n", "YES\n"};
const string io[2]{"No\n", "Yes\n"};
struct STree {
  int start;
  vector<int> t;
  STree(int n) {
    start = 1;
    while (start < n) start *= 2;
    t = vector<int>(2 * start, inf);
  }
  int min(int v, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return INF;
    if (l >= ql && r <= qr) return t[v];
    int c = (l + r) / 2;
    return std::min(min(2 * v, l, c, ql, qr), min(2 * v + 1, c + 1, r, ql, qr));
  }
  void upd(int v, int l, int r, int p, int x) {
    if (l > p || r < p) return;
    if (l == r) {
      t[v] = x;
      return;
    }
    int c = (l + r) / 2;
    upd(2 * v, l, c, p, x);
    upd(2 * v + 1, c + 1, r, p, x);
    t[v] = std::min(t[2 * v], t[2 * v + 1]);
  }
};
void solve() {
  int m;
  cin >> m;
  vector<int> x(m);
  for (int i = 0; i < m; ++i) cin >> x[i];
  sort(x.begin(), x.end());
  auto last = unique(x.begin(), x.end());
  x.erase(last, x.end());
  m = x.size();
  int a, b;
  cin >> b >> a;
  int n = b - a + 1;
  STree st = STree(n);
  int start = st.start;
  vector<int> maxx(n, 1);
  for (auto& nx : x) {
    int fa = ((a - 1) / nx) * nx + nx;
    for (int i = fa; i <= b; i += nx) maxx[i - a] = max(maxx[i - a], nx - 1);
  }
  st.upd(1, 0, start - 1, n - 1, 0);
  for (int i = b - 1; i >= a; --i) {
    int x = i - a;
    int cw = maxx[x];
    int ans = 1 + st.min(1, 0, start - 1, x + 1, x + cw);
    st.upd(1, 0, start - 1, x, ans);
  }
  cout << st.min(1, 0, start - 1, 0, 0) << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) solve();
}
