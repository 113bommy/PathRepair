#include <bits/stdc++.h>
using namespace std;
struct LazySegTree {
  int size;
  vector<long long> seg, delay;
  LazySegTree() {}
  LazySegTree(int size) {
    this->size = size;
    seg.resize(1 << (size + 1));
    delay.resize(1 << (size + 1));
  }
  long long Ident() { return 0; }
  long long ope(long long a, long long b) { return (a + b); }
  void init() {
    for (int i = 0; i < (1 << (size + 1)); i++) {
      seg[i] = Ident();
      delay[i] = 0;
    }
  }
  void eval(int l, int r, int k) {
    if (delay[k]) {
      seg[k] = 0;
      if (l < r) {
        delay[k * 2] += delay[k];
        delay[k * 2 + 1] += delay[k];
      }
      delay[k] = 0;
    }
  }
  void update(int i, long long val) {
    int l = 0, r = (1 << size) - 1, k = 1;
    eval(l, r, k);
    for (int j = size - 1; j >= 0; j--) {
      k <<= 1;
      if (i & (1 << j)) {
        k++;
        l = (l + r) / 2 + 1;
      } else
        r = (l + r) / 2;
      eval(l, r, k);
    }
    seg[i + (1 << size)] = val;
    l = i, r = i, k = i + (1 << size);
    for (int j = 0; j < size; j++) {
      k /= 2, l &= ~(1 << j), r |= 1 << j;
      eval(l, (l + r) / 2, k * 2), eval((l + r) / 2 + 1, r, k * 2 + 1);
      seg[k] = ope(seg[k * 2], seg[k * 2 + 1]);
    }
  }
  void add(int a, int b, int k, int l, int r, long long val) {
    eval(l, r, k);
    if (b < l || r < a) return;
    if (a <= l && r <= b) {
      delay[k] += val;
      eval(l, r, k);
      return;
    }
    add(a, b, k * 2, l, (l + r) / 2, val);
    add(a, b, k * 2 + 1, (l + r) / 2 + 1, r, val);
    seg[k] = ope(seg[k * 2], seg[k * 2 + 1]);
  }
  void add(int a, int b, long long val) {
    if (a > b) return;
    add(a, b, 1, 0, (1 << size) - 1, val);
  }
  long long query(int a, int b, int k, int l, int r) {
    eval(l, r, k);
    if (b < l || r < a) return Ident();
    if (a <= l && r <= b) return seg[k];
    long long lval = query(a, b, k * 2, l, (l + r) / 2);
    long long rval = query(a, b, k * 2 + 1, (l + r) / 2 + 1, r);
    return ope(lval, rval);
  }
  long long query(int a, int b) {
    if (a > b) return Ident();
    return query(a, b, 1, 0, (1 << size) - 1);
  }
};
long long n, m;
long long l[200005], r[200005], rcnt[200005];
vector<long long> vec[200005];
LazySegTree sseg[2], nseg[2];
multiset<long long> S[2];
long long dif[200005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long(i) = (1); (i) <= (n); (i)++) {
    cin >> l[i] >> r[i];
    dif[l[i]]++, dif[r[i] + 1]--;
    l[i]--;
    vec[l[i]].push_back(r[i]);
    rcnt[r[i]]++;
  }
  for (long long(i) = (0); (i) <= (1); (i)++) {
    sseg[i] = LazySegTree(18), sseg[i].init();
    nseg[i] = LazySegTree(18), nseg[i].init();
  }
  for (long long(i) = (0); (i) <= (m); (i)++)
    sseg[i % 2].update(i, i), nseg[i % 2].update(i, 1);
  long long ans = 0;
  for (long long i = m; i >= 0; i--) {
    for (auto r : vec[i]) {
      sseg[i % 2].add(i + 1, r, 1), nseg[i % 2].add(i + 1, r, 1);
      if ((r - i) % 2 == 0) {
        sseg[0].add(r + 1, m, 1), sseg[1].add(r + 1, m, 1);
        nseg[0].add(r + 1, m, 1), nseg[1].add(r + 1, m, 1);
      }
      S[r % 2].erase(S[r % 2].lower_bound(r));
    }
    long long lb = i, ub = m;
    for (long long(j) = (0); (j) <= (1); (j)++)
      if (S[j].size()) (lb) = max((lb), (*S[j].rbegin()));
    if (S[i % 2].size()) (ub) = min((ub), (*S[i % 2].begin()));
    ans += sseg[i % 2].query(lb + 1, ub);
    ans += sseg[(i + 1) % 2].query(i + 1, ub);
    ans -= i * nseg[i % 2].query(lb + 1, ub);
    ans -= i * nseg[(i + 1) % 2].query(i + 1, ub);
    for (long long(j) = (1); (j) <= (rcnt[i]); (j)++) S[i % 2].insert(i);
  }
  for (long long(i) = (1); (i) <= (m); (i)++) dif[i] += dif[i - 1];
  dif[m + 1] = 1;
  long long cnt = 0;
  for (long long(i) = (1); (i) <= (m + 1); (i)++) {
    if (dif[i])
      ans -=
          (cnt + 1) * cnt * (cnt + 1) / 2 - cnt * (cnt + 1) * (2 * cnt + 1) / 6,
          cnt = 0;
    else
      cnt++;
  }
  cout << ans << endl;
  return 0;
}
