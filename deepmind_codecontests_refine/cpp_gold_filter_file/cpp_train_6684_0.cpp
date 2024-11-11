#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
const int INF = 1e9 + 7;
const int mod = 998244353;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
long long int modInv(long long int n) { return powmod(n, mod - 2); }
vector<long long int> num;
const int nax = 2e5 + 5;
struct SegTree {
  struct Node {
    long long int val, delay;
    Node(long long int val_ = 0) {
      val = val_;
      delay = 1;
    }
    void mul(int sum) {
      val = val * sum % mod;
      delay = delay * sum % mod;
    }
    Node operator+(Node other) { return Node((val + other.val) % mod); }
  };
  int n;
  Node nodes[nax << 2];
  int left(int p) { return p * 2 + 1; }
  int right(int p) { return p * 2 + 2; }
  void build(int p, int l, int r) {
    if (l == r) {
      nodes[p] = Node(num[l]);
      return;
    }
    int mid = (l + r) / 2;
    build(left(p), l, mid);
    build(right(p), mid + 1, r);
    nodes[p] = nodes[left(p)] + nodes[right(p)];
  }
  void propagate(int p) {
    if (nodes[p].delay != 1) {
      nodes[left(p)].mul(nodes[p].delay);
      nodes[right(p)].mul(nodes[p].delay);
      nodes[p].delay = 1;
    }
  }
  void update(int p, int l, int r, int a, int b, long long int sum) {
    if (l > b || r < a) return;
    if (a <= l && r <= b) return nodes[p].mul(sum);
    propagate(p);
    int mid = (l + r) / 2;
    update(left(p), l, mid, a, b, sum);
    update(right(p), mid + 1, r, a, b, sum);
    nodes[p] = nodes[left(p)] + nodes[right(p)];
  }
  void build(int _n) {
    n = _n;
    build(0, 0, n - 1);
  }
  void update(int l, int r, int sum) { update(0, 0, n - 1, l, r, sum); }
  long long int query() { return nodes[0].val; }
} tree;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int n, q;
  cin >> n >> q;
  vector<long long int> a(n), pre(n), suf(n), hun(n), ihun(n);
  num.assign(n, 0LL);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    cin >> a[i];
  num[0] = powmod(100, n);
  pre[0] = 1;
  hun[0] = 1;
  long long int dec = modInv(100);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (i) {
      num[i] = (num[i - 1] * dec % mod) * a[i - 1] % mod;
      pre[i] = pre[i - 1];
      hun[i] = hun[i - 1];
      hun[i] = (hun[i] * 100) % mod;
    }
    pre[i] *= a[i];
    pre[i] %= mod;
  }
  suf[n - 1] = modInv(pre[n - 1]);
  ihun[n - 1] = modInv(hun[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = (suf[i + 1] * a[i + 1]) % mod;
    ihun[i] = (ihun[i + 1] * 100) % mod;
  }
  set<int> on;
  on.insert(0);
  on.insert(n);
  tree.build(n);
  long long int dem = modInv(pre[n - 1]);
  while (q--) {
    int b;
    cin >> b;
    b--;
    int l = *(--on.upper_bound(b - 1)), r = *on.upper_bound(b);
    long long int change = 1;
    if (on.count(b) == 0) {
      change = (change * ihun[r - b] % mod) * pre[r - 1] % mod;
      if (b) change = (change * suf[b - 1]) % mod;
      on.insert(b);
    } else {
      change = (change * suf[r - 1] % mod) * hun[r - b] % mod;
      if (b) change = (change * pre[b - 1]) % mod;
      on.erase(b);
    }
    tree.update(l, b - 1, change);
    printf("%lld\n", tree.query() * dem % mod);
  }
  return 0;
}
