#include <bits/stdc++.h>
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
}
inline void add(long long &a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
template <typename T>
inline T const &MAX(T const &a, T const &b) {
  return a > b ? a : b;
}
template <typename T>
inline T const &MIN(T const &a, T const &b) {
  return a < b ? a : b;
}
inline long long qp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    a = a * a % 1000000007, b >>= 1;
  }
  return ans;
}
inline long long qp(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % c;
    a = a * a % c, b >>= 1;
  }
  return ans;
}
using namespace std;
const unsigned long long ba = 233;
const double eps = 1e-5;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 4000 + 10, maxn = 2000000 + 10, inf = 0x3f3f3f3f;
long long a[N], b[N], c[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  b[0] = 1;
  for (int i = 1; i < n; i++)
    b[i] = b[i - 1] * (k - 1 + i) % 1000000007 * qp(i, 1000000007 - 2) %
           1000000007;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) add(c[i + j], a[i] * b[j] % 1000000007);
  for (int i = 1; i <= n; i++) printf("%lld\n", c[i]);
  return 0;
}
