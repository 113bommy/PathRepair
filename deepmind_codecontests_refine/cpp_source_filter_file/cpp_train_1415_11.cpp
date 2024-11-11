#include <bits/stdc++.h>
namespace wealth {
const int N = 101000, MOD = 1000000007;
int mw[N], tot;
int getid(int x) { return std::lower_bound(mw + 1, mw + tot + 1, x) - mw; }
int ans;
struct segment_tree {
  std::vector<int> siz, v, w, tag;
  std::vector<int>::iterator A;
  int n;
  segment_tree(int len = 0) {
    n = len;
    siz.resize(n * 4);
    v.resize(n * 4);
    w.resize(n * 4);
    tag.resize(n * 4);
  }
  void put(int p, int x) {
    w[p] = (w[p] + (long long)x * v[p]) % MOD;
    tag[p] += x;
  }
  void down(int p) {
    if (tag[p]) {
      put((p << 1), tag[p]);
      put(((p << 1) | 1), tag[p]);
      tag[p] = 0;
    }
  }
  void upd(int p) {
    siz[p] = siz[(p << 1)] + siz[((p << 1) | 1)];
    v[p] = v[(p << 1)] + v[((p << 1) | 1)];
    w[p] = (w[(p << 1)] + w[((p << 1) | 1)]) % MOD;
  }
  void init(int p, int L, int R) {
    if (L == R) return void(siz[p] = v[p] = w[p] = tag[p] = 0);
    init((p << 1), L, ((L + R) >> 1)),
        init(((p << 1) | 1), ((L + R) >> 1) + 1, R), upd(p);
  }
  int query_siz(int s, int t, int p, int L, int R) {
    if (L >= s && R <= t) return siz[p];
    if (R < s || L > t) return 0;
    down(p);
    return query_siz(s, t, (p << 1), L, ((L + R) >> 1)) +
           query_siz(s, t, ((p << 1) | 1), ((L + R) >> 1) + 1, R);
  }
  int query_v(int s, int t, int p, int L, int R) {
    if (L >= s && R <= t) return v[p];
    if (R < s || L > t) return 0;
    down(p);
    return (query_v(s, t, (p << 1), L, ((L + R) >> 1)) +
            query_v(s, t, ((p << 1) | 1), ((L + R) >> 1) + 1, R)) %
           MOD;
  }
  int query_w(int s, int t, int p, int L, int R) {
    if (L >= s && R <= t) return w[p];
    if (R < s || L > t) return 0;
    down(p);
    return (query_w(s, t, (p << 1), L, ((L + R) >> 1)) +
            query_w(s, t, ((p << 1) | 1), ((L + R) >> 1) + 1, R)) %
           MOD;
  }
  void turn(int x, int y, int p, int L, int R) {
    if (L == R) {
      if (siz[p] == 1)
        siz[p] = v[p] = w[p] = 0;
      else
        siz[p] = 1, v[p] = A[L], w[p] = (long long)A[L] * y % MOD;
      return;
    }
    down(p);
    if (x <= ((L + R) >> 1))
      turn(x, y, (p << 1), L, ((L + R) >> 1));
    else
      turn(x, y, ((p << 1) | 1), ((L + R) >> 1) + 1, R);
    upd(p);
  }
  void modify(int x, int y, int p, int L, int R) {
    if (L >= x) return void(put(p, y));
    if (R < x) return;
    down(p), modify(x, y, (p << 1), L, ((L + R) >> 1)),
        modify(x, y, ((p << 1) | 1), ((L + R) >> 1) + 1, R), upd(p);
  }
};
struct bit {
  int w[N];
  int lowbit(int x) { return x & (-x); }
  void inc(int p) {
    for (; p < N; p += lowbit(p)) w[p]++;
  }
  int ask(int p) {
    int ret = 0;
    for (; p; p -= lowbit(p)) ret += w[p];
    return ret;
  }
} d;
struct fucker {
  segment_tree TL, TR;
  std::vector<int> L, R;
  inline int size() { return L.size(); }
  inline void insert_L(int x) { L.push_back(x); }
  void getR(int id_mine) {
    int tot = d.ask(id_mine);
    R.resize(size());
    for (int i = 0; i < size(); i++) R[i] = tot - L[i] - 1;
  }
  void turn_on(int x) {
    int rk = TL.query_siz(0, x - 1, 1, 0, size() - 1) + 1, tmp, u, v, delta = 0;
    TL.turn(x, rk, 1, 0, size() - 1), TR.turn(x, rk, 1, 0, size() - 1);
    TL.modify(x + 1, 1, 1, 0, size() - 1),
        TR.modify(x + 1, 1, 1, 0, size() - 1);
    tmp = TL.query_v(0, x - 1, 1, 0, size() - 1), u = tmp;
    delta = (delta + (long long)(rk - 1) * R[x] % MOD * tmp % MOD) % MOD;
    tmp = TL.query_w(0, x - 1, 1, 0, size() - 1);
    delta = (delta - (long long)R[x] * tmp % MOD);
    tmp = TR.query_v(x + 1, size() - 1, 1, 0, size() - 1), v = tmp;
    delta = (delta - (long long)(rk + 1) * L[x] % MOD * tmp % MOD) % MOD;
    tmp = TR.query_w(x + 1, size() - 1, 1, 0, size() - 1);
    delta = (delta + (long long)L[x] * tmp) % MOD;
    delta = (delta + (long long)u * v % MOD) % MOD;
    ans = (ans + delta) % MOD;
  }
  void turn_off(int x) {
    int rk = TL.query_siz(0, x - 1, 1, 0, size() - 1) + 1, tmp, u, v, delta = 0;
    tmp = TL.query_v(0, x - 1, 1, 0, size() - 1), u = tmp;
    delta = (delta + (long long)(rk - 1) * R[x] % MOD * tmp % MOD) % MOD;
    tmp = TL.query_w(0, x - 1, 1, 0, size() - 1);
    delta = (delta - (long long)R[x] * tmp % MOD);
    tmp = TR.query_v(x + 1, size() - 1, 1, 0, size() - 1), v = tmp;
    delta = (delta - (long long)(rk + 1) * L[x] % MOD * tmp % MOD) % MOD;
    tmp = TR.query_w(x + 1, size() - 1, 1, 0, size() - 1);
    delta = (delta + (long long)L[x] * tmp) % MOD;
    delta = (delta + (long long)u * v % MOD) % MOD;
    ans = (ans - delta) % MOD;
    TL.turn(x, 0, 1, 0, size() - 1), TR.turn(x, 0, 1, 0, size() - 1);
    TL.modify(x + 1, -1, 1, 0, size() - 1),
        TR.modify(x + 1, -1, 1, 0, size() - 1);
  }
  void init() {
    if (!size()) return;
    TL = segment_tree(size()), TL.A = L.begin();
    TR = segment_tree(size()), TR.A = R.begin();
    TL.init(1, 0, size() - 1);
    TR.init(1, 0, size() - 1);
    for (int i = 0; i < size(); i++) turn_on(i);
  }
  void output() {
    for (int i = 0; i < size(); i++) printf("%d , %d\n", L[i], R[i]);
    printf("---------------\n");
  }
} G[N];
int A[N], B[N];
int n, m;
void initialize() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", A + i), mw[++tot] = A[i];
  std::sort(mw + 1, mw + tot + 1);
  tot = std::unique(mw + 1, mw + tot + 1) - mw - 1;
  for (int i = 1; i <= n; i++) A[i] = getid(A[i]);
  for (int i = 1, x; i <= n; i++) {
    x = A[i];
    B[i] = G[x].size();
    G[x].insert_L(d.ask(A[i]));
    d.inc(A[i]);
  }
  for (int i = 1; i <= n; i++) G[i].getR(i);
  for (int i = 1; i <= n; i++) G[i].init();
}
void solve() {
  initialize();
  int t, x;
  for (scanf("%d", &m); m--;) {
    scanf("%d%d", &t, &x);
    if (t == 1)
      G[A[x]].turn_off(B[x]);
    else
      G[A[x]].turn_on(B[x]);
    ans = (ans + MOD) % MOD;
    printf("%d\n", ans);
  }
}
}  // namespace wealth
int main() {
  wealth::solve();
  return 0;
}
