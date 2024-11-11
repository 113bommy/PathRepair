#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1e5 + 7;
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
int n, m, q;
char str[maxn];
int startTime;
void startTimer() { startTime = clock(); }
void printTimer() {
  fprintf(stderr, "/--- Time: %ld milliseconds ---/\n", clock() - startTime);
}
namespace pcf {
unsigned int H[maxn], L[maxn];
unsigned int getsum(unsigned int n, unsigned int k) {
  if (k == 0) return n;
  if (k == 1) {
    unsigned int a = n, b = n + 1;
    if (a % 2 == 0)
      a /= 2;
    else
      b /= 2;
    return a * b;
  }
  if (k == 2) {
    unsigned int a = n, b = n + 1, c = n + 2;
    if (a % 2 == 0)
      a /= 2;
    else
      b /= 2;
    if (a % 3 == 0)
      a /= 3;
    else if (b % 3 == 0)
      b /= 3;
    else
      c /= 3;
    return a * b * c;
  }
  if (k == 3) {
    unsigned int a = n, b = n + 1;
    if (a % 2 == 0)
      a /= 2;
    else
      b /= 2;
    return a * b * a * b;
  }
  return 0 * fprintf(stderr, "getsum:wrong!");
}
unsigned int power(unsigned int n, unsigned int k) {
  unsigned int ret = 1;
  while (k--) ret *= n;
  return ret;
}
unsigned int cal(unsigned int n, unsigned int K) {
  unsigned int p, k, m;
  for (m = 1; m * m <= n; ++m) H[m] = getsum(n / m, K) - 1;
  for (p = 1; p <= m; p++) L[p] = getsum(p, K) - 1;
  for (p = 2; p <= m; p++) {
    if (L[p] == L[p - 1]) continue;
    for (k = 1; k <= min(m - 1, n / p / p); k++) {
      if (p * k < m)
        H[k] -= power(p, K) * (H[p * k] - L[p - 1]);
      else
        H[k] -= power(p, K) * (L[n / p / k] - L[p - 1]);
    }
    for (k = m; k >= p * p; k--) L[k] -= power(p, K) * (L[k / p] - L[p - 1]);
  }
  unsigned int ret = 0;
  unsigned int l;
  for (l = 1; l <= n; l++) {
    unsigned int r = n / (n / l);
    if (r <= m)
      ret += n / l * (L[r] - L[l - 1]);
    else
      ret += n / l * (H[n / l] - H[n / l + 1]);
    l = r;
  }
  return ret;
}
}  // namespace pcf
unsigned int A, B, C, D;
inline unsigned int get(unsigned int x) {
  return A * x * x * x + B * x * x + C * x + D;
}
bool mark[maxn];
int main() {
  int i, j;
  scanf("%d%u%u%u%u", &n, &A, &B, &C, &D);
  int m;
  for (m = 1; m * m <= n; ++m)
    ;
  unsigned int ans = 0;
  for (i = 2; i <= m; i++)
    if (!mark[i]) {
      for (j = i * i; j <= n; j += i) mark[j] = 1;
      for (j = n / i / i; j; j /= i) ans += get(i) * j;
    }
  ans += pcf::cal(n, 3) * A;
  ans += pcf::cal(n, 2) * B;
  ans += pcf::cal(n, 1) * C;
  ans += pcf::cal(n, 0) * D;
  printf("%u", ans);
}
