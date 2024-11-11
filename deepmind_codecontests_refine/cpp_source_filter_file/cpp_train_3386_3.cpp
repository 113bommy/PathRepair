#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
void file_io(string taskname) {
  string fin = taskname + ".in";
  string fout = taskname + ".out";
  const char* FIN = fin.c_str();
  const char* FOUT = fout.c_str();
  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);
  fast_io();
}
struct max_line {
  long long m, b;
  static const long long null_v = -9223372036854775807LL;
  max_line() : m(0), b(null_v) {}
  max_line(long long _m, long long _b) : m(_m), b(_b) {}
  long long operator()(long long x) { return m * x + b; }
};
template <class T>
struct LiChaoTree {
  int C;
  vector<T> tree;
  LiChaoTree(int _C) { init(_C); }
  void init(int _C) {
    C = _C;
    tree = vector<T>(4 * C);
  }
  void insert(T line) { insert(line, 0, C, 0); }
  void insert(T line, int l, int r, int o) {
    if (l + 1 == r) {
      if (line(l) > tree[o](l)) tree[o] = line;
      return;
    }
    int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
    if (tree[o].m > line.m) swap(tree[o], line);
    if (tree[o](mid) < line(mid)) {
      swap(tree[o], line);
      insert(line, l, mid, lson);
    } else
      insert(line, mid, r, rson);
  }
  long long query(int x) { query(x, 0, C, 0); }
  long long query(int x, int l, int r, int o) {
    if (l + 1 == r) return tree[o](x);
    int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
    if (x < mid)
      return max(tree[o](x), query(x, l, mid, lson));
    else
      return max(tree[o](x), query(x, mid, r, rson));
  }
};
int main() {
  fast_io();
  int n;
  cin >> n;
  vector<long long> v(n), pref(n);
  long long tot = 0;
  for (int i = 0; i < (n); i++) {
    cin >> v[i];
    pref[i] = v[i] + (i > 0 ? pref[i - 1] : 0);
    tot += (i + 1) * v[i];
  }
  long long best = 0;
  LiChaoTree<max_line> lct(n);
  for (int r = 0; r < (n); r++) {
    if (r > 0) best = max(best, lct.query(r) - pref[r]);
    lct.insert({v[r], pref[r] - r * v[r]});
  }
  vector<long long> suff(n);
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = v[i] + (i < n - 1 ? suff[i + 1] : 0);
  }
  lct = LiChaoTree<max_line>(n);
  for (int l = n - 1; l >= 0; l--) {
    if (l < n - 1) best = max(best, lct.query(l) + suff[l]);
    lct.insert({v[l], -suff[l] - v[l] * l});
  }
  cout << tot + best << "\n";
}
