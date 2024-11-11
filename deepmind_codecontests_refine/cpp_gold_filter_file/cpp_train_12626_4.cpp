#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long max_n = 2e5 + 5;
const long long log_n = 20;
const long long inf = 1e17 + 6;
const long long K = 1000;
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct node {
  long long tag = -1, sum = 0, mn = inf;
  node() {}
};
struct ST {
  vector<node> t;
  ST() { t.resize(4 * max_n); }
  void build(vector<long long> &a, long long v = 0, long long vl = 0,
             long long vr = max_n) {
    if (vr - vl == 1) {
      if (vl < a.size()) {
        t[v].sum = a[vl];
        t[v].mn = a[vl];
      }
      return;
    }
    long long vm = (vl + vr) / 2;
    build(a, 2 * v + 1, vl, vm);
    build(a, 2 * v + 2, vm, vr);
    t[v].sum = t[2 * v + 1].sum + t[2 * v + 2].sum;
    t[v].mn = min(t[2 * v + 1].mn, t[2 * v + 2].mn);
  }
  void push(long long v, long long vl, long long vr) {
    if (t[v].tag != -1) {
      long long tag = t[v].tag;
      t[v].tag = -1;
      t[2 * v + 1].tag = tag;
      t[2 * v + 2].tag = tag;
      t[2 * v + 1].mn = tag;
      t[2 * v + 2].mn = tag;
      long long vm = (vl + vr) / 2;
      t[2 * v + 1].sum = tag * (vm - vl);
      t[2 * v + 2].sum = tag * (vr - vm);
    }
  }
  void update(long long lq, long long rq, long long tag, long long v = 0,
              long long vl = 0, long long vr = max_n) {
    if (lq >= vr || vl >= rq) return;
    if (lq <= vl && vr <= rq) {
      t[v].tag = tag;
      t[v].mn = tag;
      t[v].sum = tag * (vr - vl);
      return;
    }
    push(v, vl, vr);
    long long vm = (vl + vr) / 2;
    update(lq, rq, tag, 2 * v + 1, vl, vm);
    update(lq, rq, tag, 2 * v + 2, vm, vr);
    t[v].sum = t[2 * v + 1].sum + t[2 * v + 2].sum;
    t[v].mn = min(t[2 * v + 1].mn, t[2 * v + 2].mn);
  }
  long long sum(long long lq, long long rq, long long v = 0, long long vl = 0,
                long long vr = max_n) {
    if (lq >= vr || vl >= rq) return 0;
    if (lq <= vl && vr <= rq) return t[v].sum;
    long long vm = (vl + vr) / 2;
    push(v, vl, vr);
    return sum(lq, rq, 2 * v + 1, vl, vm) + sum(lq, rq, 2 * v + 2, vm, vr);
  }
  long long get(long long x, long long v = 0, long long vl = 0,
                long long vr = max_n) {
    if (vr - vl == 1) return vl;
    long long vm = (vl + vr) / 2;
    push(v, vl, vr);
    if (t[2 * v + 1].mn <= x)
      return get(x, 2 * v + 1, vl, vm);
    else
      return get(x, 2 * v + 2, vm, vr);
  }
  long long down(long long x, long long v = 0, long long vl = 0,
                 long long vr = max_n) {
    if (vr - vl == 1) return vl;
    long long vm = (vl + vr) / 2;
    push(v, vl, vr);
    if (t[2 * v + 1].sum <= x)
      return down(x - t[2 * v + 1].sum, 2 * v + 2, vm, vr);
    else
      return down(x, 2 * v + 1, vl, vm);
  }
};
void run() {
  long long n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ST tree;
  tree.build(a);
  for (long long i = 0; i < q; ++i) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long pos, y;
      cin >> pos >> y;
      pos--;
      long long l = tree.get(y);
      if (l <= pos) {
        tree.update(l, pos + 1, y);
      }
    } else {
      long long pos, y;
      cin >> pos >> y;
      pos--;
      long long ans = 0;
      while (pos < n) {
        long long l = tree.get(y);
        l = max(l, pos);
        long long need = tree.sum(0, l);
        long long r = tree.down(need + y);
        r--;
        r = min(r, n - 1);
        long long sum = tree.sum(l, r + 1);
        if (sum > y || l > r) break;
        y -= sum;
        pos = r + 1;
        ans += r - l + 1;
      }
      cout << ans << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) run();
  return 0;
}
