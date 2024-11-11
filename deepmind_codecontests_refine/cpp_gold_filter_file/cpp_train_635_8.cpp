#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1e6 + 107;
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
int Mod[] = {1, -1, 1, -1, 1};
struct poly {
  unsigned long long x[4];
  poly() { memset(x, 0, sizeof(x)); }
  const poly operator+(const poly &p) const {
    poly ret;
    int i;
    for (i = 0; i < 4; i++) ret.x[i] = x[i] + p.x[i];
    return ret;
  }
  const poly operator*(const poly &p) const {
    static unsigned long long tmp[7];
    int i, j;
    poly ret;
    memset(tmp, 0, sizeof(tmp));
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++) tmp[i + j] += x[i] * p.x[j];
    for (i = 7 - 1; i >= 4; i--)
      for (j = 5 - 1; j >= 0; j--) tmp[i - j] -= tmp[i] * Mod[4 - j];
    for (i = 0; i < 4; i++) ret.x[i] = tmp[i];
    return ret;
  }
} value[100007];
poly w10[20];
void fwt(poly value[], int len, int inv) {
  for (int x = 10; x <= len; x *= 10) {
    for (int y = 0; y < len; y += x) {
      int _x = x / 10;
      for (int z = y; z < (y + _x); z++) {
        vector<poly> now, nxt;
        int i, j;
        now.resize(10);
        nxt.resize(10);
        for (i = 0; i < 10; i++) now[i] = value[z + _x * i];
        for (i = 0; i < 10; i++)
          for (j = 0; j < 10; j++)
            nxt[i] = nxt[i] + now[j] * w10[(10 + i * inv) * j % 10];
        for (i = 0; i < 10; i++) value[z + _x * i] = nxt[i];
      }
    }
  }
}
inline poly poww(poly a, int b) {
  poly ret;
  ret.x[0] = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) ret = ret * a;
  return ret;
}
const unsigned long long mod = 1ull << 58;
inline unsigned long long poww(unsigned long long a, unsigned long long b) {
  unsigned long long ret = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) ret = ret * a;
  return ret;
}
int main() {
  int i;
  w10[0].x[0] = 1;
  w10[1].x[1] = 1;
  for (i = 2; i < 20; i++) w10[i] = w10[i - 1] * w10[1];
  int n;
  int x;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &x), value[x].x[0]++;
  fwt(value, 100000, 1);
  for (i = 0; i < 100000; i++) value[i] = poww(value[i], n);
  fwt(value, 100000, -1);
  unsigned long long inv5 = poww(5, mod - 1);
  for (i = 0; i < n; i++) {
    unsigned long long ans = value[i].x[0];
    ans /= 32;
    ans *= inv5 * inv5 * inv5 * inv5 * inv5;
    ans %= mod;
    printf("%llu\n", ans);
  }
}
