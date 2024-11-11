#include <bits/stdc++.h>
using namespace std;
constexpr int seed = 131;
constexpr long long LLMAX = 2e18;
constexpr int MOD = 1e9 + 7;
constexpr double eps = 1e-8;
constexpr int MAXN = 5e5 + 10;
constexpr int hmod1 = 0x48E2DCE7;
constexpr int hmod2 = 0x60000005;
inline long long sqr(long long x) { return x * x; }
inline int sqr(int x) { return x * x; }
inline double sqr(double x) { return x * x; }
inline int mul(int x, int y) { return 1ll * x * y % MOD; }
inline int sub(int x, int y) { return x >= y ? x - y : MOD + x - y; }
inline int add(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
inline int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return (x > 0 ? 1 : -1);
}
inline long long qpow(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum = sum * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return sum;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d;
  (b == 0 ? (x = 1, y = 0, d = a)
          : (d = exgcd(b, a % b, y, x), y -= a / b * x));
  return d;
}
int n, q;
char s[MAXN];
int tree[MAXN << 2][2], L[MAXN << 2][4], R[MAXN << 2][4], lz[MAXN << 2];
int tp[MAXN << 2][2], Lp[MAXN << 2][4], Rp[MAXN << 2][4], len[MAXN << 2];
inline void swap(int rt) {
  swap(L[rt][0], L[rt][1]);
  swap(L[rt][2], L[rt][3]);
  swap(R[rt][0], R[rt][1]);
  swap(R[rt][2], R[rt][3]);
  swap(tree[rt][0], tree[rt][1]);
}
void pushup(int l, int r, int rt, int tree[][2], int L[][4], int R[][4]) {
  int mid = (l + r) >> 1;
  int ls = mid - l + 1, rs = r - mid;
  if (l == -1 && r == -1) ls = len[rt << 1], rs = len[rt << 1 | 1];
  for (int i = 0; i < 2; i++) {
    if (L[rt << 1][i] == ls)
      L[rt][i] = L[rt << 1][i] + L[rt << 1 | 1][i];
    else
      L[rt][i] = L[rt << 1][i];
    if (R[rt << 1 | 1][i] == rs)
      R[rt][i] = R[rt << 1 | 1][i] + R[rt << 1][i];
    else
      R[rt][i] = R[rt << 1 | 1][i];
    if (L[rt << 1][i + 2] == ls) {
      if (L[rt << 1][i] == ls)
        L[rt][i + 2] = L[rt << 1][i + 2] +
                       max(L[rt << 1 | 1][i],
                           max(L[rt << 1 | 1][1 - i], L[rt << 1 | 1][i + 2]));
      else
        L[rt][i + 2] = L[rt << 1][i + 2] + L[rt << 1 | 1][1 - i];
    } else
      L[rt][i + 2] = L[rt << 1][i + 2];
    if (R[rt << 1 | 1][i + 2] == rs) {
      if (R[rt << 1 | 1][1 - i] == rs)
        R[rt][i + 2] =
            R[rt << 1 | 1][i + 2] +
            max(R[rt << 1][1 - i], max(R[rt << 1][i], R[rt << 1][i + 2]));
      else
        R[rt][i + 2] = R[rt << 1 | 1][i + 2] + R[rt << 1][i];
    } else
      R[rt][i + 2] = R[rt << 1 | 1][i + 2];
  }
  tree[rt][0] = max(tree[rt << 1][0], tree[rt << 1 | 1][0]);
  tree[rt][0] = max(tree[rt][0],
                    max(max(L[rt][0], max(L[rt][1], L[rt][3])),
                        max(max(R[rt][0], max(R[rt][1], R[rt][3])),
                            max(max(R[rt << 1][0] + L[rt << 1 | 1][0],
                                    R[rt << 1][1] + L[rt << 1 | 1][1]),
                                max(R[rt << 1][1] + L[rt << 1 | 1][0],
                                    max(R[rt << 1][1] + L[rt << 1 | 1][3],
                                        R[rt << 1][3] + L[rt << 1 | 1][0]))))));
  tree[rt][1] = max(tree[rt << 1][1], tree[rt << 1 | 1][1]);
  tree[rt][1] = max(tree[rt][0],
                    max(max(L[rt][0], max(L[rt][1], L[rt][2])),
                        max(max(R[rt][0], max(R[rt][1], R[rt][2])),
                            max(max(R[rt << 1][0] + L[rt << 1 | 1][0],
                                    R[rt << 1][1] + L[rt << 1 | 1][1]),
                                max(R[rt << 1][0] + L[rt << 1 | 1][1],
                                    max(R[rt << 1][0] + L[rt << 1 | 1][2],
                                        R[rt << 1][2] + L[rt << 1 | 1][1]))))));
}
void pushdown(int rt) {
  if (lz[rt]) {
    swap(rt << 1);
    swap(rt << 1 | 1);
    lz[rt << 1] ^= 1;
    lz[rt << 1 | 1] ^= 1;
    lz[rt] = 0;
  }
}
void clear(int rt) {
  len[rt] = 0;
  for (int i = 0; i < 2; i++) tp[rt][i] = 0;
  for (int i = 0; i < 4; i++) Lp[rt][i] = 0, Rp[rt][i] = 0;
}
void build(int l, int r, int rt) {
  if (l == r) {
    int i = (s[l] == '<' ? 0 : 1);
    L[rt][i] = R[rt][i] = 1;
    L[rt][2 + i] = R[rt][3 - i] = 1;
    tree[rt][0] = tree[rt][1] = 1;
  } else {
    build(l, (l + r) / 2, rt << 1);
    build((l + r) / 2 + 1, r, rt << 1 | 1);
    pushup(l, r, rt, tree, L, R);
  }
}
void update(int l, int r, int rt, int a, int b) {
  if (a <= l && r <= b) {
    swap(rt);
    lz[rt] ^= 1;
    len[rt] = r - l + 1;
    for (int i = 0; i < 2; i++) tp[rt][i] = tree[rt][i];
    for (int i = 0; i < 4; i++) Lp[rt][i] = L[rt][i], Rp[rt][i] = R[rt][i];
  } else {
    int mid = (l + r) >> 1;
    pushdown(rt);
    clear(rt << 1), clear(rt << 1 | 1);
    if (a <= mid) update(l, (l + r) / 2, rt << 1, a, b);
    if (mid < b) update((l + r) / 2 + 1, r, rt << 1 | 1, a, b);
    len[rt] = len[rt << 1] + len[rt << 1 | 1];
    pushup(-1, -1, rt, tp, Lp, Rp);
    pushup(l, r, rt, tree, L, R);
  }
}
int main(void) {
  int n, q;
  scanf("%d%d%s", &n, &q, s + 1);
  build(1, n, 1);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    update(1, n, 1, l, r);
    printf("%d\n", tp[1][0]);
  }
  return 0;
}
