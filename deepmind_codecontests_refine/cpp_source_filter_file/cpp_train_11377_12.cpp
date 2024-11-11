#include <bits/stdc++.h>
using namespace std;
class segment_tree {
  int n;
  vector<long long> t;
  vector<int> sz;
  vector<bool> modified;
  vector<long long> mod;
  void init(int v, int L, int R) {
    if (L == R - 1) {
      sz[v] = 1;
      return;
    }
    int mid = (L + R) / 2;
    init(2 * v + 1, L, mid);
    init(2 * v + 2, mid, R);
    sz[v] = sz[2 * v + 1] + sz[2 * v + 2];
  }
  void push(int v) {
    if (!modified[v]) return;
    modified[2 * v + 1] = true;
    mod[2 * v + 1] = mod[v];
    modified[2 * v + 2] = true;
    mod[2 * v + 2] = mod[v];
    modified[v] = false;
    t[v] = get_sum(2 * v + 1) + get_sum(2 * v + 2);
  }
  long long get_sum(int v) {
    if (modified[v]) {
      return sz[v] * mod[v];
    } else {
      return t[v];
    }
  }
  long long get_sum(int v, int L, int R, int l, int r) {
    if (R <= l || r <= L) {
      return 0;
    }
    if (l <= L && R <= r) {
      return get_sum(v);
    }
    push(v);
    int mid = (L + R) / 2;
    return get_sum(2 * v + 1, L, mid, l, r) + get_sum(2 * v + 2, mid, R, l, r);
  }
  void set(int v, int L, int R, int l, int r, long long x) {
    if (R <= l || r <= L) {
      return;
    }
    if (l <= L && R <= r) {
      modified[v] = true;
      mod[v] = x;
      return;
    }
    push(v);
    int mid = (L + R) / 2;
    set(2 * v + 1, L, mid, l, r, x);
    set(2 * v + 2, mid, R, l, r, x);
    t[v] = get_sum(2 * v + 1) + get_sum(2 * v + 2);
  }

 public:
  segment_tree(int n_)
      : n(n_), t(4 * n), sz(4 * n), modified(4 * n), mod(4 * n) {
    init(0, 0, n);
  }
  void set(int l, int r, long long x) { set(0, 0, n, l, r, x); }
  void set(int i, long long x) { set(i, i + 1, x); }
  void add(int i, long long x) { set(i, get_sum(i, i + 1) + x); }
  long long get_sum(int l, int r) { return get_sum(0, 0, n, l, r); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  segment_tree count(n + 1);
  segment_tree sum(n + 1);
  int co = 0;
  for (char c : s) {
    if (c == '0') {
      for (int i = 0; i <= co; i++) {
        count.add(i, 1);
        sum.add(i, i);
      }
      co = 0;
    } else {
      co++;
      int cnt = count.get_sum(0, co);
      count.set(0, co, 0);
      sum.set(0, co, 0);
      count.add(co, cnt);
      sum.add(co, cnt * co);
      ans += 1ll * co * (co + 1) / 2;
    }
    ans += sum.get_sum(0, n + 1);
  }
  cout << ans << endl;
  return 0;
}
