#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 4e5 + 107;
const double pi = acos(-1.0);
const double eps = 0.0000000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline void pr2(T x, int k = 64) {
  long long i;
  for (i = 0; i < k; i++) fprintf(stderr, "%d", (x >> i) & 1);
  putchar(' ');
}
template <typename T>
inline void add_(T &A, int B, long long MOD = M) {
  A += B;
  (A >= MOD) && (A -= MOD);
}
template <typename T>
inline void mul_(T &A, long long B, long long MOD = M) {
  A = (A * B) % MOD;
}
template <typename T>
inline void mod_(T &A, long long MOD = M) {
  A %= MOD;
  A += MOD;
  A %= MOD;
}
template <typename T>
inline void max_(T &A, T B) {
  (A < B) && (A = B);
}
template <typename T>
inline void min_(T &A, T B) {
  (A > B) && (A = B);
}
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline T powMM(T a, T b) {
  T ret = 1;
  for (; b; b >>= 1ll, a = (long long)a * a % M)
    if (b & 1) ret = (long long)ret * a % M;
  return ret;
}
int startTime;
void startTimer() { startTime = clock(); }
void printTimer() {
  fprintf(stderr, "/--- Time: %ld milliseconds ---/\n", clock() - startTime);
}
int n, m, q;
int A[maxn];
long long val[maxn * 4], lazyval[maxn * 4], bit[307];
long long sum[maxn * 4], lazysum[maxn * 4];
void change(int x, int len, int mul, int xo) {
  sum[x] = sum[x] * powMM(mul, len) % M;
  lazysum[x] = lazysum[x] * mul % M;
  val[x] = val[x] | xo;
  lazyval[x] |= xo;
}
void pushdown(int x, int L, int mid, int R) {
  if (lazyval[x]) {
    change(x << 1, mid - L + 1, lazysum[x], lazyval[x]);
    change(x << 1 | 1, R - mid, lazysum[x], lazyval[x]);
    lazysum[x] = 1;
    lazyval[x] = 0;
  }
}
void pushup(int x) {
  sum[x] = sum[x << 1] * sum[x << 1 | 1] % M;
  val[x] = val[x << 1] | val[x << 1 | 1];
}
void build(int x, int l, int r) {
  if (l == r) {
    val[x] = bit[A[l]];
    sum[x] = A[l];
    return;
  }
  int mid = (l + r) / 2;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pushup(x);
  lazysum[x] = 1;
}
void update(int x, int l, int r, int v, int L, int R) {
  if (l <= L && R <= r) {
    change(x, R - L + 1, v, bit[v]);
    return;
  }
  int mid = (L + R) / 2;
  pushdown(x, L, mid, R);
  if (l <= mid) update(x << 1, l, r, v, L, mid);
  if (mid < r) update(x << 1 | 1, l, r, v, mid + 1, R);
  pushup(x);
}
pair<long long, long long> merge(pair<long long, long long> A,
                                 pair<long long, long long> B) {
  return make_pair(A.first * B.first % M, A.second | B.second);
}
pair<long long, long long> query(int x, int l, int r, int L, int R) {
  if (l <= L && R <= r) return make_pair(sum[x], val[x]);
  int mid = (L + R) / 2;
  pair<long long, long long> ret = make_pair(1, 0);
  pushdown(x, L, mid, R);
  if (l <= mid) ret = merge(ret, query(x << 1, l, r, L, mid));
  if (mid < r) ret = merge(ret, query(x << 1 | 1, l, r, mid + 1, R));
  pushup(x);
  return ret;
}
int p[1007];
int chk[1007];
int main() {
  int i, j, C = 0;
  for (i = 2; i <= 300; i++)
    if (!bit[i]) {
      for (j = i; j <= 300; j += i) bit[j] |= 1ll << C;
      chk[C] = powMM((long long)i, M - 2) * (i - 1) % M;
      p[C++] = i;
    }
  scanf("%d%d", &n, &q);
  for (i = 1; i <= n; i++) scanf("%d", &A[i]);
  build(1, 1, n);
  while (q--) {
    char op[107];
    scanf("%s", op);
    if (op[0] == 'T') {
      int l, r;
      scanf("%d%d", &l, &r);
      pair<long long, long long> ans = query(1, l, r, 1, n);
      for (i = 0; i < 62; i++)
        if ((ans.second >> i) & 1) ans.first = ans.first * chk[i] % M;
      printf("%lld\n", ans.first);
    } else {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      update(1, l, r, x, 1, n);
    }
  }
}
