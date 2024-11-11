#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
using namespace std;
struct UF {
  vector<long long int> e;
  UF(int n) : e(n, -1) {}
  bool same_set(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
  }
};
long long int p = 998244353;
long long int power_(long long int a, long long int b) {
  if (!b) return 1;
  long long int ans = power_(a, b / 2);
  ans = (ans * ans) % p;
  if (b % 2) ans = (ans * a) % p;
  return ans;
}
long long int inf = -1e15;
struct Node {
  Node *l = 0, *r = 0;
  long long int lo, hi, mset = inf, madd = 0, val = -inf;
  Node(long long int lo, long long int hi) : lo(lo), hi(hi) {}
  Node(vector<long long int>& v, long long int lo, long long int hi)
      : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      long long int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = min(l->val, r->val);
    } else
      val = v[lo];
  }
  long long int query(long long int L, long long int R) {
    if (R <= lo || hi <= L) return -inf;
    if (L <= lo && hi <= R) return val;
    push();
    return min(l->query(L, R), r->query(L, R));
  }
  void set(long long int L, long long int R, long long int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R)
      mset = val = x, madd = 0;
    else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = min(l->val, r->val);
    }
  }
  void add(long long int L, long long int R, long long int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (mset != inf)
        mset += x;
      else
        madd += x;
      val += x;
    } else {
      push(), l->add(L, R, x), r->add(L, R, x);
      val = min(l->val, r->val);
    }
  }
  void push() {
    if (!l) {
      long long int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset != inf)
      l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
    else if (madd)
      l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
  }
};
struct Tree {
  const long long int LOW = 1e8;
  long long int f(long long int a, long long int b) { return min(a, b); }
  long long int n;
  vector<long long int> s;
  Tree() {}
  Tree(long long int m, long long int def = 1e8) { init(m, def); }
  void init(long long int m, long long int def) {
    n = 1;
    while (n < m) n *= 2;
    s.assign(n + m, def);
    s.resize(2 * n, LOW);
    for (long long int i = n; i-- > 1;) s[i] = f(s[i * 2], s[i * 2 + 1]);
  }
  void update(long long int pos, long long int val) {
    pos += n;
    s[pos] = val;
    for (pos /= 2; pos >= 1; pos /= 2) s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  long long int query(long long int l, long long int r) {
    return que(1, l, r, 0, n);
  }
  long long int que(long long int pos, long long int l, long long int r,
                    long long int lo, long long int hi) {
    if (r <= lo || hi <= l) return LOW;
    if (l <= lo && hi <= r) return s[pos];
    long long int m = (lo + hi) / 2;
    return f(que(2 * pos, l, r, lo, m), que(2 * pos + 1, l, r, m, hi));
  }
};
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  long long int n, m;
  long long int a, b, c, de;
  cin >> n >> m;
  p = 998244353;
  long long int dp[m + 1];
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    dp[i] = (dp[i - 1] * i) % p;
  }
  long long int ans = 1;
  a = dp[m];
  b = (dp[n - 1] * dp[m - n + 1]) % p;
  b = power_(b, p - 2);
  ans = (ans * a * b) % p;
  ans = (ans * (n - 2)) % p;
  ans = (ans * (power_(2, n - 2) - 1 + p) % p) % p;
  cout << ans << endl;
}
