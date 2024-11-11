#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 100;
const long long MOD = 1e9 + 7;
long long n, m;
long long seed, MAXV, in[N];
inline long long rnd() {
  long long res = seed;
  seed = (seed * 7 + 13) % MOD;
  return res;
}
struct Node {
  long long l, r;
  mutable long long val;
  Node(long long L, long long R = -1, long long V = 0) : l(L), r(R), val(V) {}
  bool operator<(const Node &x) const { return l < x.l; }
};
set<Node> S;
inline long long pow(long long x, long long p, long long mod) {
  long long res = 1;
  while (p) {
    if (p & 1) res = (res * x) % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return res;
}
set<Node>::iterator split(long long pos) {
  set<Node>::iterator x = S.lower_bound(Node(pos));
  if (x != S.end() && x->l == pos) return x;
  --x;
  long long L = x->l, R = x->r;
  long long V = x->val;
  S.erase(x);
  S.insert(Node(L, pos - 1, V));
  return S.insert(Node(pos, R, V)).first;
}
inline void assign_val(long long l, long long r, long long val) {
  set<Node>::iterator R = split(r + 1), L = split(l);
  S.erase(L, R);
  S.insert((Node){l, r, val});
}
inline void add(long long l, long long r, long long val) {
  set<Node>::iterator R = split(r + 1), L = split(l);
  for (set<Node>::iterator i = L; i != R; ++i) i->val += val;
}
vector<pair<long long, long long> > Q;
inline long long ranks(long long l, long long r, long long k) {
  set<Node>::iterator R = split(r + 1), L = split(l);
  Q.clear();
  for (set<Node>::iterator i = L; i != R; ++i)
    Q.push_back(pair<long long, long long>(i->val, i->r - i->l + 1));
  sort(Q.begin(), Q.end());
  for (vector<pair<long long, long long> >::iterator i = Q.begin();
       i != Q.end(); ++i) {
    k -= i->second;
    if (k <= 0) return i->first;
  }
  return -1;
}
inline long long sum(long long l, long long r, long long x, long long y) {
  set<Node>::iterator R = split(r + 1), L = split(l);
  long long res = 0;
  for (set<Node>::iterator i = L; i != R; ++i)
    res = (res + (long long)(i->r - i->l + 1) * pow(i->val % y, x, y) % y) % y;
  return res;
}
signed main() {
  scanf("%lld%lld%lld%lld", &n, &m, &seed, &MAXV);
  for (long long i = 1; i <= n; ++i) {
    in[i] = rnd() % MAXV + 1;
    S.insert((Node){i, i, in[i]});
  }
  S.insert((Node){n + 1, n + 1, 0});
  for (long long i = 1; i <= m; ++i) {
    long long opt = rnd() % 4 + 1;
    long long l = rnd() % n + 1;
    long long r = rnd() % n + 1;
    if (l > r) swap(l, r);
    long long x, y;
    if (opt == 3)
      x = rnd() % (r - l + 1) + 1;
    else
      x = rnd() % MAXV + 1;
    if (opt == 4) y = rnd() % MAXV + 1;
    if (opt == 1)
      add(l, r, x);
    else if (opt == 2)
      assign_val(l, r, x);
    else if (opt == 3)
      printf("%lld\n", ranks(l, r, x));
    else
      printf("%lld\n", sum(l, r, x, y));
  }
}
