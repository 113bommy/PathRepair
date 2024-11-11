#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 15, MAXL = 11;
struct FN {
  int bit[MAXN][MAXL][MAXL][4];
  int get(int p, int mod, int rem, int c) {
    int ret = 0;
    for (p++; p; p -= p & -p) ret += bit[p][mod][rem][c];
    return ret;
  }
  void update(int p, int mod, int rem, int c, int val) {
    for (p++; p < MAXN; p += p & -p) bit[p][mod][rem][c] += val;
  }
  int _(char g) {
    if (g == 'A') return 0;
    if (g == 'T') return 1;
    if (g == 'G') return 2;
    return 3;
  }
  void upd(int p, const string& s, int val) {
    int c = _(s[p]);
    for (int mod = 1; mod < MAXL; mod++) update(p, mod, p % mod, c, val);
  }
  int query(int l, int r, string e, const string& s) {
    int ret = 0;
    r--, l--;
    if (r - l + 1 <= (int)e.size()) {
      for (int i = l; i <= r; i++) ret += (s[i] == e[i - l]);
      return ret;
    }
    int j = 0;
    while (l % (int)e.size()) {
      if (e[j] == s[l]) ret++;
      l++;
      j++;
    }
    string d = e.substr(0, j);
    e = e.substr(j, (int)e.size() - j);
    e = e + d;
    for (int i = 0; i < (int)e.size(); i++) {
      if (l)
        ret += get(r, (int)e.size(), i, _(e[i])) -
               get(l - 1, (int)e.size(), i, _(e[i]));
      else
        ret += get(r, (int)e.size(), i, _(e[i]));
    }
    return ret;
  }
} tree;
string s;
int q;
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cerr << "HELLO WORLD :)\n";
  cin >> s >> q;
  for (int i = 0; i < (int)s.size(); i++) tree.upd(i, s, 1);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      tree.upd(x, s, -1);
      s[x] = c;
      tree.upd(x, s, 1);
    } else {
      int l, r;
      string e;
      cin >> l >> r >> e;
      cout << tree.query(l, r, e, s) << '\n';
    }
  }
  return false;
}
