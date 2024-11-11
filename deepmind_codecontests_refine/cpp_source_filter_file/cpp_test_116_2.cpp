#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Read(T &x) {
  x = 0;
  char ch = getchar();
  int64_t f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
int64_t __lcm(T a, T b) {
  return a / __gcd(a, b) * b;
}
template <typename T>
int64_t __ceil(T a, T b) {
  return (a + b - 1) / b;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t __rand(int64_t a, int64_t b) { return a + rng() % (b - a + 1); }
inline int64_t QuickPow(int64_t base, int64_t n, int64_t Mod = 0) {
  int64_t ret(1);
  while (n) {
    if (n & 1) {
      ret *= base;
      if (Mod) ret %= Mod;
    }
    base *= base;
    if (Mod) base %= Mod;
    n >>= 1;
  }
  return Mod ? ret % Mod : ret;
}
inline int64_t __inv(int64_t x, int64_t p) { return QuickPow(x, p - 2, p); }
class DSU {
 public:
  std::vector<int> p, size;
  int n, setCount;
  DSU(int _n) : n(_n), setCount(_n), p(_n), size(_n, 1) {
    std::iota(p.begin(), p.end(), 0);
  }
  int find(int x) { return p[x] = x == p[x] ? x : find(p[x]); }
  bool unite(int x, int y) {
    if (size[x] < size[y]) return unite(y, x);
    return p[y] = x, size[x] += size[y], --setCount, true;
  }
  bool helper(int x, int y) {
    int pX = find(x), pY = find(y);
    return pX != pY ? unite(pX, pY) : false;
  }
};
class BIT {
 public:
  BIT(int size) : n(size), tree(size + 10, 0LL) {}
  virtual ~BIT() { tree.clear(); }
  vector<int64_t> tree;
  int n;
  int lowbit(int x) { return ((x) & -(x)); }
  void update(int64_t x, int64_t d) {
    while (x <= n) {
      tree[x] += d;
      x += lowbit(x);
    }
  }
  int64_t query(int x) {
    int64_t res = 0;
    while (x > 0) {
      res += tree[x];
      x -= lowbit(x);
    }
    return res;
  }
};
class SegmentTree {
 public:
  struct node {
    int64_t l, r;
    int64_t sum;
    int64_t dat;
    int64_t lazy;
  };
  std::vector<node> tree;
  std::vector<int64_t> arr;
  int n;
  SegmentTree(int _n, vector<int64_t> a) : n(_n), tree(_n << 1 | 1), arr(a) {}
  void pushup(int64_t p) {
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].dat = max(tree[p << 1].dat, tree[p << 1 | 1].dat);
  }
  void pushdown(int64_t p) {
    if (tree[p].lazy) {
      tree[p << 1].sum += tree[p].lazy * (tree[p << 1].r - tree[p << 1].l + 1);
      tree[p << 1 | 1].sum +=
          tree[p].lazy * (tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1);
      tree[p << 1].dat += tree[p].lazy;
      tree[p << 1 | 1].sum += tree[p].lazy;
      tree[p << 1].lazy += tree[p].lazy;
      tree[p << 1 | 1].lazy += tree[p].lazy;
      tree[p].lazy = 0;
    }
  }
  void build(int64_t p, int64_t l, int64_t r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
      tree[p].sum = tree[p].dat = arr[l];
      return;
    }
    int64_t mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
  }
  void ChangeSegment(int64_t p, int64_t l, int64_t r, int64_t d) {
    if (l <= tree[p].l && r >= tree[p].r) {
      tree[p].sum += (int64_t)d * (tree[p].r - tree[p].l + 1);
      tree[p].lazy += d;
      tree[p].dat += d;
      return;
    }
    pushdown(p);
    int64_t mid = (tree[p].l + tree[p].r) / 2;
    if (l <= mid) ChangeSegment(p << 1, l, r, d);
    if (r > mid) ChangeSegment(p << 1 | 1, l, r, d);
    pushup(p);
  }
  int64_t QuerySum(int64_t p, int64_t l, int64_t r) {
    if (l <= tree[p].l && r >= tree[p].r) return tree[p].sum;
    pushdown(p);
    int64_t mid = (tree[p].l + tree[p].r) / 2;
    int64_t sum = 0;
    if (l <= mid) sum += QuerySum(p << 1, l, r);
    if (r > mid) sum += QuerySum(p << 1 | 1, l, r);
    return sum;
  }
  int64_t AskDat(int64_t p, int64_t l, int64_t r) {
    if (l <= tree[p].l && r >= tree[p].r) return tree[p].dat;
    pushdown(p);
    int64_t mid = (tree[p].l + tree[p].r) / 2;
    int64_t res = -(1 << 30);
    if (l <= mid) res = max(res, AskDat(p << 1, l, r));
    if (r > mid) res = max(res, AskDat(p << 1 | 1, l, r));
    return res;
  }
  void show(int n) {
    for (int i = 1; i <= n; i++) cout << QuerySum(1, i, i) << " ";
    cout << '\n';
  }
};
const double pi = acos(-1.0);
const int64_t kInf(1e18 + 10);
const int64_t kMod(998244353);
const int64_t kMax(2e5 + 10);
int64_t group(1);
inline void Solve() {
  int n;
  Read(n);
  vector<vector<int64_t>> dp(2, vector<int64_t>(n + 2));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int64_t num;
    Read(num);
    dp[0][num + 1] = (dp[0][num + 1] + dp[0][num + 1]) % kMod;
    dp[0][num + 1] = (dp[0][num + 1] + dp[0][num]) % kMod;
    if (num > 0) dp[1][num - 1] = (dp[1][num - 1] + dp[1][num - 1]) % kMod;
    if (num > 0) dp[1][num - 1] = (dp[1][num - 1] + dp[0][num - 1]) % kMod;
    dp[1][num + 1] = (dp[1][num + 1] + dp[1][num + 1]) % kMod;
  }
  int64_t res = 0;
  for (int i = 0; i <= n; i++)
    res = ((res + dp[0][i]) % kMod + dp[1][i]) % kMod;
  cout << (res - 1) % kMod << '\n';
}
int main() {
  Read(group);
  while (group--) {
    Solve();
  }
  return 0;
}
