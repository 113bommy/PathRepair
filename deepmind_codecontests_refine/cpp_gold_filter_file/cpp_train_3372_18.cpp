#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long data = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    data = (data << 3) + (data << 1) + (ch ^ 48), ch = getchar();
  return data * w;
}
long long n, b;
inline long long fastpow(long long x, int y) {
  long long ans = 1, mod = n + 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
inline bool is_prime(long long x) {
  if (x < 2) return false;
  for (register long long i = 2; 1ll * i * i <= x; i++)
    if (!(x % i)) return false;
  return true;
}
inline bool root(long long x) {
  if (!(x % (n + 1))) return false;
  for (register long long i = 1; 1ll * i * i <= n; i++) {
    if (n % i) continue;
    if (i < n && fastpow(x, i) == 1) return false;
    if (i != 1 && fastpow(x, n / i) == 1) return false;
  }
  return true;
}
int main() {
  n = read();
  b = read();
  if (!is_prime(n + 1)) return puts("-1") & 0;
  for (register long long i = b - 1; i > 1; i--)
    if (root(i)) return printf("%d\n", i) & 0;
  puts("-1");
  return 0;
}
