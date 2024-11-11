#include <bits/stdc++.h>
using namespace std;
int n, q;
struct query {
  int pos, l;
};
struct Fenwick {
  int n;
  vector<int> aib;
  Fenwick(int _n) {
    aib.resize(_n + 1);
    n = _n;
  }
  void upd(int pos, int val) {
    for (int i = pos; i <= n; i += (i & -i)) {
      aib[i] += val;
    }
  }
  void rupd(int l, int r) {
    if (l > r) return;
    upd(l, 1);
    if (r <= n) upd(r + 1, -1);
  }
  int qry(int x) {
    int sol = 0;
    for (; x; x -= (x & -x)) sol += aib[x];
    return sol;
  }
};
int main() {
  cin >> n >> q;
  vector<int> a(n + 1);
  Fenwick v(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = i - a[i];
  }
  vector<query> s[n + 1];
  vector<int> ans(q + 1);
  for (int i = 1; i <= q; ++i) {
    int x, y;
    cin >> x >> y;
    int l = x + 1, r = n - y;
    s[r].push_back({i, l});
  }
  for (int r = 1; r <= n; ++r) {
    if (a[r] >= 0) {
      int pas = (1 << 10), pos = 0;
      while (pas) {
        do {
          pas >>= 1;
        } while (pos + pas > r && pas);
        if (v.qry(pas + pos) >= a[r]) pos += pas;
      }
      v.rupd(1, pos);
    }
    for (auto it : s[r]) {
      ans[it.pos] = v.qry(it.l);
    }
  }
  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}
