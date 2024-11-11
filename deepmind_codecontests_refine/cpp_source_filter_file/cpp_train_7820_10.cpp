#include <bits/stdc++.h>
using namespace std;
long long mod;
const int MAX_N = 100001;
int primes[10], fact[MAX_N][1], k;
int arr[MAX_N], segtree[4 * MAX_N][10], lazy[4 * MAX_N][11];
inline void mult(int &a, int b) {
  long long p = (a * 1ll) * (b * 1ll);
  if (p >= mod) p %= mod;
  a = (int)(p);
}
inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int fexp(int base, int exp) {
  int result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) mult(result, base);
    exp >>= 1;
    mult(base, base);
  }
  return result;
}
int modinv(int x) {
  long long s = 0, old_s = 1;
  long long t = 1, old_t = 0;
  long long r = mod, old_r = x;
  while (r != 0) {
    long long quotient = old_r / r;
    long long nold_r = old_r, nr = r;
    old_r = nr;
    r = nold_r - quotient * nr;
    long long nold_s = old_s, ns = s;
    old_s = ns;
    s = nold_s - quotient * ns;
    long long nold_t = old_t, nt = t;
    old_t = nt;
    t = nold_t - quotient * nt;
  }
  assert(old_r == 1);
  old_s %= mod;
  while (old_s < 0) old_s += mod;
  return old_s;
}
void pre() {
  int x = mod, itr = 0;
  for (int d = 2; ((d * d <= x) && (x > 1)); ++d) {
    if (x % d == 0) {
      primes[++itr] = d;
      while (x % d == 0) x /= d;
    }
  }
  if (x > 1) primes[++itr] = x;
  k = itr;
  fact[1][0] = 1;
  for (int i = 1; i <= k; ++i) fact[1][i] = 0;
  fact[1][k + 1] = fact[1][k + 2] = 1;
  for (int x = 2; x < MAX_N; ++x) {
    int y = x;
    fact[x][0] = x;
    for (int i = 1; i <= k; ++i) {
      while (y % primes[i] == 0) {
        y /= primes[i];
        ++fact[x][i];
      }
    }
    fact[x][k + 1] = y;
    fact[x][k + 2] = modinv(y);
  }
}
void build(int node, int start, int end) {
  int lnode = (node << 1), rnode = lnode + 1;
  if (start == end) {
    for (int i = 0; i < k + 2; ++i) segtree[node][i] = fact[arr[start]][i];
    if (segtree[node][0] >= mod) segtree[node][0] %= mod;
    return;
  }
  int mid = start + (end - start) / 2;
  build(lnode, start, mid);
  build(rnode, mid + 1, end);
  segtree[node][0] = segtree[lnode][0];
  add(segtree[node][0], segtree[rnode][0]);
}
void update1(int node, int start, int end, int l, int r, int val) {
  int lnode = (node << 1), rnode = lnode + 1;
  if (lazy[node][k + 2] != 0) {
    mult(segtree[node][0], lazy[node][0]);
    if (start != end) {
      mult(lazy[lnode][0], lazy[node][0]);
      for (int i = 1; i <= k; ++i) lazy[lnode][i] += lazy[node][i];
      mult(lazy[lnode][k + 1], lazy[node][k + 1]);
      lazy[lnode][k + 2] = 1;
      mult(lazy[rnode][0], lazy[node][0]);
      for (int i = 1; i <= k; ++i) lazy[rnode][i] += lazy[node][i];
      mult(lazy[rnode][k + 1], lazy[node][k + 1]);
      lazy[rnode][k + 2] = 1;
    } else {
      for (int i = 1; i <= k; ++i) segtree[node][i] += lazy[node][i];
      mult(segtree[node][k + 1], lazy[node][k + 1]);
    }
    lazy[node][0] = 1;
    for (int i = 1; i <= k; ++i) lazy[node][i] = 0;
    lazy[node][k + 1] = 1;
    lazy[node][k + 2] = 0;
  }
  if (r < start or end < l or start > end) return;
  if (l <= start and end <= r) {
    mult(segtree[node][0], fact[val][0]);
    if (start != end) {
      mult(lazy[lnode][0], fact[val][0]);
      for (int i = 1; i <= k; ++i) lazy[lnode][i] += fact[val][i];
      mult(lazy[lnode][k + 1], fact[val][k + 1]);
      lazy[lnode][k + 2] = 1;
      mult(lazy[rnode][0], fact[val][0]);
      for (int i = 1; i <= k; ++i) lazy[rnode][i] += fact[val][i];
      mult(lazy[rnode][k + 1], fact[val][k + 1]);
      lazy[rnode][k + 2] = 1;
    } else {
      for (int i = 1; i <= k; ++i) segtree[node][i] += fact[val][i];
      mult(segtree[node][k + 1], fact[val][k + 1]);
    }
    return;
  }
  int mid = start + (end - start) / 2;
  update1(lnode, start, mid, l, r, val);
  update1(rnode, mid + 1, end, l, r, val);
  segtree[node][0] = segtree[lnode][0];
  add(segtree[node][0], segtree[rnode][0]);
}
void update2(int node, int start, int end, int pos, int val) {
  int lnode = (node << 1), rnode = lnode + 1;
  if (lazy[node][k + 2] != 0) {
    mult(segtree[node][0], lazy[node][0]);
    if (start != end) {
      mult(lazy[lnode][0], lazy[node][0]);
      for (int i = 1; i <= k; ++i) lazy[lnode][i] += lazy[node][i];
      mult(lazy[lnode][k + 1], lazy[node][k + 1]);
      lazy[lnode][k + 2] = 1;
      mult(lazy[rnode][0], lazy[node][0]);
      for (int i = 1; i <= k; ++i) lazy[rnode][i] += lazy[node][i];
      mult(lazy[rnode][k + 1], lazy[node][k + 1]);
      lazy[rnode][k + 2] = 1;
    } else {
      for (int i = 1; i <= k; ++i) segtree[node][i] += lazy[node][i];
      mult(segtree[node][k + 1], lazy[node][k + 1]);
    }
    lazy[node][0] = 1;
    for (int i = 1; i <= k; ++i) lazy[node][i] = 0;
    lazy[node][k + 1] = 1;
    lazy[node][k + 2] = 0;
  }
  if (pos < start or end < pos or start > end) return;
  if (start == end && start == pos) {
    segtree[node][0] = 1;
    for (int i = 1; i <= k; ++i) segtree[node][i] -= fact[val][i];
    mult(segtree[node][k + 1], fact[val][k + 2]);
    for (int i = 1; i <= k; ++i)
      mult(segtree[node][0], fexp(primes[i], segtree[node][i]));
    mult(segtree[node][0], segtree[node][k + 1]);
    return;
  }
  int mid = start + (end - start) / 2;
  update2(lnode, start, mid, pos, val);
  update2(rnode, mid + 1, end, pos, val);
  segtree[node][0] = segtree[lnode][0];
  add(segtree[node][0], segtree[rnode][0]);
}
int query(int node, int start, int end, int l, int r) {
  int lnode = (node << 1), rnode = lnode + 1;
  if (r < start or end < l or start > end) return 0;
  if (lazy[node][k + 2] != 0) {
    mult(segtree[node][0], lazy[node][0]);
    if (start != end) {
      mult(lazy[lnode][0], lazy[node][0]);
      for (int i = 1; i <= k; ++i) lazy[lnode][i] += lazy[node][i];
      mult(lazy[lnode][k + 1], lazy[node][k + 1]);
      lazy[lnode][k + 2] = 1;
      mult(lazy[rnode][0], lazy[node][0]);
      for (int i = 1; i <= k; ++i) lazy[rnode][i] += lazy[node][i];
      mult(lazy[rnode][k + 1], lazy[node][k + 1]);
      lazy[rnode][k + 2] = 1;
    } else {
      for (int i = 1; i <= k; ++i) segtree[node][i] += lazy[node][i];
      mult(segtree[node][k + 1], lazy[node][k + 1]);
    }
    lazy[node][0] = 1;
    for (int i = 1; i <= k; ++i) lazy[node][i] = 0;
    lazy[node][k + 1] = 1;
    lazy[node][k + 2] = 0;
  }
  if (l <= start and end <= r) return segtree[node][0];
  int mid = start + (end - start) / 2;
  int p1 = query(lnode, start, mid, l, r);
  int p2 = query(rnode, mid + 1, end, l, r);
  add(p1, p2);
  return p1;
}
int main() {
  int n;
  scanf("%d%lld", &n, &mod);
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
  pre();
  build(1, 0, n - 1);
  int MX = 4 * MAX_N;
  for (int node = 0; node < MX; ++node) {
    lazy[node][0] = lazy[node][k + 1] = 1;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    --l;
    --r;
    if (op == 1) {
      int x;
      scanf("%d", &x);
      if (x != 1) update1(1, 0, n - 1, l, r, x);
    } else if (op == 2) {
      int x = r + 1, p = l;
      if (x != 1) update2(1, 0, n - 1, p, x);
    } else {
      int ans = query(1, 0, n - 1, l, r);
      printf("%d\n", ans);
    }
  }
  return 0;
}
