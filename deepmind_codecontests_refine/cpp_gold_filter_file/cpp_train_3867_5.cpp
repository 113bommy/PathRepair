#include <bits/stdc++.h>
static const long long int mod = 1000000007LL;
static const int prime[62] = {
    2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,
    43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101,
    103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
    173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
    241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
long long int inv[301];
static long long int val[301];
struct sectree {
  int left, right, mid;
  int ltree, rtree;
  long long int x, y;
  long long int xx, yy;
} t[1000000];
int tn;
long long int a[500003];
void build(int i, int l, int r) {
  t[i].left = l, t[i].right = r, t[i].mid = (l + r) >> 1;
  if (l != r) {
    int mid = (l + r) >> 1;
    build(t[i].ltree = tn++, l, mid);
    build(t[i].rtree = tn++, mid + 1, r);
    t[i].xx = (t[t[i].ltree].xx * t[t[i].rtree].xx) % mod;
    t[i].yy = (t[t[i].ltree].yy | t[t[i].rtree].yy);
    t[i].x = 1;
    t[i].y = 0;
  } else {
    t[i].xx = t[i].x = a[l];
    t[i].yy = t[i].y = val[a[l]];
  }
}
long long int qpow(long long int x, int y) {
  long long int ans = 1;
  long long int cur = x;
  for (int i = 0; y > 0; ++i) {
    if ((y & (1 << i)) != 0) {
      y ^= (1 << i);
      ans = ans * cur % mod;
    }
    cur = cur * cur % mod;
  }
  return ans;
}
void mul(int i, int l, int r, long long int x, long long int y) {
  if (l <= t[i].left && r >= t[i].right) {
    t[i].x = (t[i].x * x) % mod;
    t[i].y = t[i].y | y;
    t[i].xx = (t[i].xx * qpow(x, t[i].right - t[i].left + 1)) % mod;
    t[i].yy = t[i].yy | y;
  } else {
    if (l <= t[i].mid) mul(t[i].ltree, l, std::min(t[i].mid, r), x, y);
    if (r > t[i].mid) mul(t[i].rtree, std::max(t[i].mid + 1, l), r, x, y);
    t[i].xx = t[t[i].ltree].xx * t[t[i].rtree].xx % mod *
              qpow(t[i].x, t[i].right - t[i].left + 1) % mod;
    t[i].yy = t[t[i].ltree].yy | t[t[i].rtree].yy | t[i].y;
  }
}
std::pair<long long int, long long int> pro(int i, int l, int r) {
  if (l <= t[i].left && r >= t[i].right) {
    return std::make_pair(t[i].xx, t[i].yy);
  } else {
    long long int xx = qpow(t[i].x, r - l + 1), yy = t[i].y;
    if (l <= t[i].mid) {
      std::pair<long long int, long long int> p =
          pro(t[i].ltree, l, std::min(t[i].mid, r));
      xx = xx * p.first % mod;
      yy = yy | p.second;
    }
    if (r > t[i].mid) {
      std::pair<long long int, long long int> p =
          pro(t[i].rtree, std::max(t[i].mid + 1, l), r);
      xx = xx * p.first % mod;
      yy = yy | p.second;
    }
    return std::make_pair(xx, yy);
  }
}
long long int phi(long long int v) {
  long long int val = 1;
  for (int i = 0; i < 62; ++i) {
    if ((v & (1LL << i)) != 0) {
      val = val * (prime[i] - 1) % mod * inv[prime[i]] % mod;
    }
  }
  return val;
}
int main() {
  for (int i = 0; i < 62; ++i) {
    for (int j = prime[i]; j <= 300; j += prime[i]) {
      val[j] |= (1LL << i);
    }
  }
  inv[1] = 1;
  for (int i = 2; i <= 300; ++i) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &a[i]);
  }
  tn = 1;
  build(0, 0, n - 1);
  for (int i = 0; i < q; ++i) {
    char cmd[10];
    scanf("%s", cmd);
    if (cmd[0] == 'M') {
      int l, r;
      long long int x;
      scanf("%d%d%I64d", &l, &r, &x);
      --l, --r;
      mul(0, l, r, x, val[x]);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      --l, --r;
      std::pair<long long int, long long int> v = pro(0, l, r);
      long long int ans = v.first * phi(v.second) % mod;
      printf("%I64d\n", ans);
    }
  }
}
