#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 228;
const long long oo = 1e18 + 228;
const long long K = 300;
mt19937_64 rnd(time(0));
int n;
int a[N];
bool d1[50], d2[50];
struct ST {
  vector<int> t;
  void build(int v = 1, int l = 1, int r = n) {
    if (l == r)
      t[v] = a[l];
    else {
      int c = (l + r) / 2;
      build(v + v, l, c);
      build(v + v + 1, c + 1, r);
      t[v] = t[v + v] + t[v + v + 1];
    }
  }
  void uni() {
    t.resize(2 * N);
    build();
  }
  void upd(int x, int y, int v = 1, int l = 1, int r = n, int d = 1,
           int now = 0) {
    if (l == r) {
      t[v] = y;
      return;
    }
    int c = (l + r) / 2;
    now ^= d2[d];
    int now2 = now ^ d1[d];
    int v1 = v + v, v2 = v + v + 1;
    if (now2) swap(v1, v2);
    if (x <= c)
      upd(x, y, v1, l, c, d + 1, now);
    else
      upd(x, y, v2, c + 1, r, d + 1, now);
    t[v] = t[v + v] + t[v + v + 1];
  }
  long long get(int l, int r, int v = 1, int tl = 1, int tr = n, int d = 1,
                int now = 0) {
    if (l > r) return 0;
    if (tl == l && tr == r) return t[v];
    int c = (tl + tr) / 2;
    now ^= d2[d];
    int now2 = now ^ d1[d];
    int v1 = v + v, v2 = v + v + 1;
    if (now2) swap(v1, v2);
    return get(l, min(r, c), v1, tl, c, d + 1, now) +
           get(max(l, c + 1), r, v2, c + 1, tr, d + 1, now);
  }
} t;
void solve() {
  int q, x, y, l, r;
  cin >> n >> q;
  int w = n;
  n = (1 << n);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  t.uni();
  for (int z = 1; z <= q; ++z) {
    int T;
    cin >> T;
    if (T == 1) {
      cin >> x >> y;
      t.upd(x, y);
    }
    if (T == 3) {
      cin >> x;
      d1[w - x] = 1 - d1[w - x];
    }
    if (T == 2) {
      cin >> x;
      d2[w - x + 1] = 1 - d2[w - x + 1];
    }
    if (T == 4) {
      cin >> l >> r;
      cout << ' ' << t.get(l, r) << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  for (int z = 1; z <= T; ++z) solve();
  return 0;
}
