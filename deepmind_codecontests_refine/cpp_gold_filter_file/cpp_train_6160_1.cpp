#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long inff = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
mt19937 rnd(time(0));
const int maxn = 1e6 + 5, maxm = 1e5 + 5;
namespace linear_table {
bool isp[maxn + 10];
int prime[maxn + 10];
int p;
void init() {
  int N = maxn;
  for (int i = 2; i <= N; i++) {
    if (!isp[i]) prime[++p] = i;
    for (int j = 1; j <= p && i * prime[j] <= N; j++) {
      isp[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
}  // namespace linear_table
using linear_table::isp;
char s1[maxm], s2[maxm];
int c[maxm], a[maxm];
long long qp(long long base, long long n, long long mod) {
  base %= mod;
  long long res = 1;
  while (n) {
    if (n & 1) (res *= base) %= mod;
    (base *= base) %= mod;
    n >>= 1;
  }
  return res;
}
void work(int d, int n, int m) {
  for (int i = (0); i <= (int)(d - 1); ++i) a[i] = 0;
  for (int i = (0); i <= (int)(n - 1); ++i) a[i % d] += c[i];
  for (int p = m / d * d + d; p < maxn; p += d) {
    if (isp[p + 1]) continue;
    int mod = p + 1;
    int r, r0;
    while (1) {
      r = rnd() % (mod - 2) + 1;
      if (qp(r, p / d, mod) != 1) {
        r0 = qp(r, p / d, mod), r = r0;
        for (int i = 1; i <= d; i++) {
          int res = 0, x = 1;
          for (int j = 0; j < d; j++)
            (res += 1LL * a[j] * x % mod) %= mod, x = 1LL * x * r % mod;
          if (!res) {
            printf("%d %d\n", mod, r);
            exit(0);
          }
          r = 1LL * r * r0 % mod;
        }
        break;
      }
    }
  }
}
int main() {
  linear_table::init();
  int n, m;
  scanf("%d%d", &(n), &(m));
  scanf("%s%s", s1, s2);
  for (int i = 0; i < n; i++) c[i] = s1[i] - s2[i];
  for (int i = 3; i <= 1000000; i++)
    if (!isp[i]) work(i, n, m);
  return 0;
}
