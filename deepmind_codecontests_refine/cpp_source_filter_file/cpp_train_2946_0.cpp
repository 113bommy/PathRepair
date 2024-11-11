#include <bits/stdc++.h>
using namespace std;
struct state {
  int total, ss, se, ee, size;
  state() : total(0), ss(0), se(0), ee(0), size(0) {}
  inline static state build_base(const char& c, const char& startchar) {
    state s;
    s.total = 1, s.size = 1;
    if (c == startchar) {
      s.ss = 1;
    } else {
      s.ee = 1;
    }
    return s;
  }
  static state build_inc(const char& c) { return build_base(c, '4'); }
  static state build_dec(const char& c) { return build_base(c, '7'); }
};
inline state merge(const state& l, const state& r) {
  state s;
  s.size = l.size + r.size;
  s.total = max(l.total, r.total);
  s.total = max(s.total, l.ss + max(max(r.ss, r.se), r.ee));
  s.total = max(s.total, max(l.se, l.ee) + r.ee);
  s.ss = l.ss + r.ss;
  s.se = max(max(l.ss + r.se, l.ss + r.ee), l.se + r.ee);
  s.ee = l.ee + r.ee;
  return s;
}
ostream& operator<<(ostream& os, const state& s) {
  os << "(";
  os << s.total << "," << s.ss << "," << s.se << "," << s.ee << "," << s.size;
  os << ")";
  return os;
}
struct segtree {
  vector<state> t_inc, t_dec;
  vector<int> d;
  int h, n;
  segtree(const string& s) {
    int sz = s.size();
    h = sizeof(int) * 8 - __builtin_clz(sz);
    n = 1 << h;
    d = vector<int>(n << 1, 0);
    t_inc = vector<state>(n << 1);
    t_dec = vector<state>(n << 1);
    for (int i = 0; i < s.size(); ++i) {
      t_inc[i + n] = state::build_inc(s[i]);
      t_dec[i + n] = state::build_dec(s[i]);
    }
    for (int i = n - 1; i > 0; --i) {
      t_inc[i] = merge(t_inc[i << 1], t_inc[i << 1 | 1]);
      t_dec[i] = merge(t_dec[i << 1], t_dec[i << 1 | 1]);
    }
  }
  void build(int x) {
    for (x /= 2; x > 0; x /= 2) {
      t_inc[x] = merge(t_inc[x << 1], t_inc[x << 1 | 1]);
      t_dec[x] = merge(t_dec[x << 1], t_dec[x << 1 | 1]);
    }
  }
  void apply(int x) {
    d[x]++;
    swap(t_inc[x], t_dec[x]);
  }
  void push(int x) {
    for (int s = h; s > 0; --s) {
      int i = x >> s;
      if (d[i]) {
        d[i] = 0;
        apply(i << 1);
        apply(i << 1 | 1);
      }
    }
  }
  void flip(int l, int r) {
    int l0 = l + n;
    int r0 = r + n;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l % 2) apply(l++);
      if (r % 2) apply(--r);
    }
    push(l0), push(r0 - 1);
    build(l0), build(r0 - 1);
  }
  int query() { return t_inc[1].total; }
};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N, Q;
  cin >> N >> Q;
  string s;
  cin >> s;
  segtree st(s);
  for (int qq = 0; qq < Q; ++qq) {
    string op;
    cin >> op;
    if (op[0] == 'c') {
      cout << st.query() << endl;
    } else {
      int l, r;
      cin >> l >> r;
      st.flip(l - 1, r);
    }
  }
  return 0;
}
