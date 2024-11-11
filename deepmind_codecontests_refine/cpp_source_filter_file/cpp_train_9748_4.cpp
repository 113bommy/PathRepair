#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) {
  long long z = y;
  while (x % y != 0) {
    z = x % y;
    x = y;
    y = z;
  }
  return z;
}
int A[200105], B[200105];
struct mb {
  long long T[200105 << 2], lz[200105 << 2];
  void Up(int rt, int l, int r) { T[rt] = min(T[(rt << 1)], T[(rt << 1 | 1)]); }
  void Down(int rt, int l, int r) {
    if (lz[rt] != 0) {
      T[(rt << 1)] += lz[rt];
      lz[(rt << 1)] += lz[rt];
      T[(rt << 1 | 1)] += lz[rt];
      lz[(rt << 1 | 1)] += lz[rt];
      lz[rt] = 0;
    }
  }
  void build(int rt, int l, int r) {
    if (l + 1 == r) {
      T[rt] = B[r - 1];
      return;
    }
    int mid = (l + r) / 2;
    build((rt << 1), l, mid);
    build((rt << 1 | 1), mid, r);
    Up(rt, l, r);
  }
  void upt(int rt, int l, int r, int L, int R, long long val) {
    if (R <= l || r <= L) return;
    if (L <= l && r <= R) {
      T[rt] += val;
      lz[rt] += val;
      return;
    }
    Down(rt, l, r);
    int mid = (l + r) / 2;
    upt((rt << 1), l, mid, L, R, val);
    upt((rt << 1 | 1), mid, r, L, R, val);
    Up(rt, l, r);
  }
  long long qy(int rt, int l, int r, int L, int R) {
    if (R <= l || r <= L) return (1LL << 60);
    if (L <= l && r <= R) {
      return T[rt];
    }
    Down(rt, l, r);
    int mid = (l + r) / 2;
    return min(qy((rt << 1), l, mid, L, R), qy((rt << 1 | 1), mid, r, L, R));
  }
} mbt;
vector<pair<int, int> > ab[200105];
long long aa[200105];
const int MN = (1 << 20) + 5;
struct mbc {
  int M;
  long long T[MN];
  void init(int sz) {
    for (M = 1; sz + 2 > M; M <<= 1)
      ;
  }
  void init(int sz, long long val) {
    for (M = 1; sz + 2 > M; M <<= 1)
      ;
    for (int(i) = 0; (i) < (int)(MN); (i)++) T[i] = val;
  }
  void clear() { memset(T, 0, sizeof T); }
  void upt(int l, long long val) {
    l += M;
    T[l] = val;
    while (l > 1) {
      T[l >> 1] = min(T[l], T[l ^ 1]);
      l >>= 1;
    }
  }
  long long qy(int l, int r) {
    long long ans = (1LL << 60);
    for (l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1) ans = min(ans, T[l ^ 1]);
      if (r & 1) ans = min(ans, T[r ^ 1]);
    }
    return ans;
  }
} ynk;
void fmain(int ID) {
  int q;
  scanf("%d%d%d", &n, &m, &q);
  for (int(i) = 1; (i) <= (int)(n - 1); (i)++) scanf("%d%d", A + i, B + i);
  mbt.build(1, 0, n);
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    ab[u].push_back({v, w});
  }
  ynk.init(n, (1LL << 60));
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    for (auto p : ab[i]) {
      mbt.upt(1, 0, n, 0, p.first, p.second);
    }
    aa[i] = mbt.T[1];
    ynk.upt(i, mbt.T[1] + A[i]);
  }
  printf("%lld\n", ynk.qy(1, n));
  for (int(i) = 1; (i) <= (int)(q); (i)++) {
    int v, w;
    scanf("%d%d", &v, &w);
    ynk.upt(v, w + aa[i]);
    printf("%lld\n", ynk.qy(1, n));
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
