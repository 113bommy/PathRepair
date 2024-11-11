#include <bits/stdc++.h>
using namespace std;
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() {
  rnd_data = rnd_data * 0x5DEECE66DULL + 0xB;
  return (rnd_data >> 17) & 0x7FFFFFFF;
}
template <typename T>
void my_random_shuffle(T b, T e) {
  for (ssize_t i = 1; i < (e - b); i++) {
    swap(b[i], b[my_rand() % (i + 1)]);
  }
}
template <class _T>
inline _T sqr(const _T &x) {
  return x * x;
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-9;
const int MOD = 1000000007;
int n, m;
int a[2000008 * 2];
int b[((2000008 + 1) >> 5) + 10];
int c[2000008 + 8];
int f[2000008 + 8];
int pk[2000008 + 8];
void gen_primes() {
  memset(b, 0, sizeof(b));
  int sq = (int)(sqrt(2000008) + 2);
  for (int j = 4; j <= 2000008; j += 2) {
    b[j >> 5] |= 1 << j;
    c[j] = 2;
  }
  for (int i = 3; i <= sq; i += 2) {
    if (b[i >> 5] & (1 << i)) continue;
    int j = i * i;
    while (j <= 2000008) {
      b[j >> 5] |= 1 << j;
      c[j] = i;
      j += i * 2;
    }
  }
  b[1 >> 5] |= 1 << 1;
  for (int i = 2; i <= 2000008; i++) {
    if (!(b[i >> 5] & (1 << i))) c[i] = i;
  }
}
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += MOD;
}
int modpow(int a, int k) {
  if (!k) return 1;
  int ans = modpow(a, k / 2);
  ans = ans * (unsigned long long)ans % MOD;
  if (k & 1) ans = ans * (unsigned long long)a % MOD;
  return ans;
}
int main() {
  cout << setiosflags(ios::fixed) << setprecision(10);
  gen_primes();
  memset((a), 0, sizeof(a));
  scanf("%d%d", &m, &n);
  pk[0] = 1;
  for (int i = (1); i <= (int)(n); i++) {
    pk[i] = modpow(i, m);
  }
  int ans = 0;
  f[1] = 1;
  for (int i = (2); i <= (int)(n); i++) {
    int x = c[i];
    int t = i / x;
    if (t % x == 0)
      f[i] = 0;
    else
      f[i] = -f[t];
  }
  for (int i = (1); i <= (int)(n); i++) {
    if (!f[i]) continue;
    int t = 0;
    for (int j = (1); j <= (int)(n); j++) {
      t += i;
      if (t > n) break;
      int cur = f[i] * pk[j];
      if (cur < 0) cur += MOD;
      add(a[t], cur);
      sub(a[t + i], cur);
    }
  }
  for (int i = (1); i <= (int)(n); i++) {
    add(a[i], a[i - 1]);
    add(ans, (a[i] ^ i));
  }
  printf("%d\n", ans);
  return 0;
}
