#include <bits/stdc++.h>
using namespace std;
const long long INF(0x3f3f3f3f3f3f3f3fll);
const long long inf(0x3f3f3f3f);
template <typename T>
void read(T &res) {
  bool flag = false;
  char ch;
  while (!isdigit(ch = getchar())) (ch == '-') && (flag = true);
  for (res = ch - 48; isdigit(ch = getchar());
       res = (res << 1) + (res << 3) + ch - 48)
    ;
  flag && (res = -res);
}
template <typename T>
void Out(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) Out(x / 10);
  putchar(x % 10 + '0');
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long pow_mod(long long x, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long fact_pow(long long n, long long p) {
  long long res = 0;
  while (n) {
    n /= p;
    res += n;
  }
  return res;
}
long long mult(long long a, long long b, long long p) {
  a %= p;
  b %= p;
  long long r = 0, v = a;
  while (b) {
    if (b & 1) {
      r += v;
      if (r > p) r -= p;
    }
    v <<= 1;
    if (v > p) v -= p;
    b >>= 1;
  }
  return r;
}
long long quick_pow(long long a, long long b, long long p) {
  long long r = 1, v = a % p;
  while (b) {
    if (b & 1) r = mult(r, v, p);
    v = mult(v, v, p);
    b >>= 1;
  }
  return r;
}
bool CH(long long a, long long n, long long x, long long t) {
  long long r = quick_pow(a, x, n);
  long long z = r;
  for (long long i = 1; i <= t; i++) {
    r = mult(r, r, n);
    if (r == 1 && z != 1 && z != n - 1) return true;
    z = r;
  }
  return r != 1;
}
bool Miller_Rabin(long long n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (!(n & 1)) return false;
  long long x = n - 1, t = 0;
  while (!(x & 1)) {
    x >>= 1;
    t++;
  }
  srand(time(NULL));
  long long o = 8;
  for (long long i = 0; i < o; i++) {
    long long a = rand() % (n - 1) + 1;
    if (CH(a, n, x, t)) return false;
  }
  return true;
}
long long prime[100000], minprime[100000];
void euler(long long n) {
  long long c = 0, i, j;
  for (i = 2; i <= n; i++) {
    if (!minprime[i]) prime[++c] = i, minprime[i] = i;
    for (j = 1; j <= c && i * prime[j] <= n; j++) {
      minprime[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
struct Tree {
  long long l, r, sum, lazy, maxn, minn;
} tree[100000];
inline void push_up(long long rt) {
  tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
  tree[rt].maxn = max(tree[rt << 1].maxn, tree[rt << 1 | 1].maxn);
  tree[rt].minn = min(tree[rt << 1].minn, tree[rt << 1 | 1].minn);
}
inline void push_down(long long rt, long long length) {
  if (tree[rt].lazy) {
    tree[rt << 1].lazy += tree[rt].lazy;
    tree[rt << 1 | 1].lazy += tree[rt].lazy;
    tree[rt << 1].sum += (length - (length >> 1)) * tree[rt].lazy;
    tree[rt << 1 | 1].sum += (length >> 1) * tree[rt].lazy;
    tree[rt << 1].minn += tree[rt].lazy;
    tree[rt << 1 | 1].minn += tree[rt].lazy;
    tree[rt << 1].maxn += tree[rt].lazy;
    tree[rt << 1 | 1].maxn += tree[rt].lazy;
    tree[rt].lazy = 0;
  }
}
inline void build(long long l, long long r, long long rt, long long *aa) {
  tree[rt].lazy = 0;
  tree[rt].l = l;
  tree[rt].r = r;
  if (l == r) {
    tree[rt].sum = aa[l];
    tree[rt].minn = tree[rt].sum;
    tree[rt].maxn = tree[rt].sum;
    return;
  }
  long long mid = (l + r) >> 1;
  build(l, mid, rt << 1, aa);
  build(mid + 1, r, rt << 1 | 1, aa);
  push_up(rt);
}
inline void update_range(long long L, long long R, long long key,
                         long long rt) {
  if (tree[rt].r < L || tree[rt].l > R) return;
  if (L <= tree[rt].l && R >= tree[rt].r) {
    tree[rt].sum += (tree[rt].r - tree[rt].l + 1) * key;
    tree[rt].minn += key;
    tree[rt].maxn += key;
    tree[rt].lazy += key;
    return;
  }
  push_down(rt, tree[rt].r - tree[rt].l + 1);
  long long mid = (tree[rt].r + tree[rt].l) >> 1;
  if (L <= mid) update_range(L, R, key, rt << 1);
  if (R > mid) update_range(L, R, key, rt << 1 | 1);
  push_up(rt);
}
inline long long query_range(long long L, long long R, long long rt) {
  if (L <= tree[rt].l && R >= tree[rt].r) {
    return tree[rt].sum;
  }
  push_down(rt, tree[rt].r - tree[rt].l + 1);
  long long mid = (tree[rt].r + tree[rt].l) >> 1;
  long long ans = 0;
  if (L <= mid) ans += query_range(L, R, rt << 1);
  if (R > mid) ans += query_range(L, R, rt << 1 | 1);
  return ans;
}
inline long long query_min(long long L, long long R, long long rt) {
  if (L <= tree[rt].l && R >= tree[rt].r) {
    return tree[rt].minn;
  }
  push_down(rt, tree[rt].r - tree[rt].l + 1);
  long long mid = (tree[rt].r + tree[rt].l) >> 1;
  long long ans = (0x3f3f3f3f3f3f3f3fll);
  if (L <= mid) ans = min(ans, query_min(L, R, rt << 1));
  if (R > mid) ans = min(ans, query_min(L, R, rt << 1 | 1));
  return ans;
}
inline long long query_max(long long L, long long R, long long rt) {
  if (L <= tree[rt].l && R >= tree[rt].r) {
    return tree[rt].maxn;
  }
  push_down(rt, tree[rt].r - tree[rt].l + 1);
  long long mid = (tree[rt].r + tree[rt].l) >> 1;
  long long ans = -(0x3f3f3f3f3f3f3f3fll);
  if (L <= mid) ans = max(ans, query_max(L, R, rt << 1));
  if (R > mid) ans = max(ans, query_max(L, R, rt << 1 | 1));
  return ans;
}
const long long N = 3e5 + 10;
long long n, a[N], cnt[N];
signed main() {
  std::ios::sync_with_stdio(false);
  long long n, B;
  cin >> n >> B;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long sum = 0, now = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i] & 1)
      sum++;
    else
      sum--;
    if (sum == 0 && i + 1 <= n) cnt[++now] = a[i + 1] - a[i];
  }
  sort(cnt + 1, cnt + 1 + now);
  long long ans = 0;
  for (long long i = 1; i <= now; i++) {
    if (B >= cnt[i])
      B -= cnt[i], ans++;
    else
      break;
  }
  cout << ans << '\n';
  return 0;
}
