#include <bits/stdc++.h>
using namespace std;
const int inf = 0x20202020;
const long long mod = 1000000007;
const double eps = 1e-9;
const double pi = 3.1415926535897932384626;
const int DX[] = {1, 0, -1, 0}, DY[] = {0, 1, 0, -1};
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  if (n < k) return puts("-1"), 0;
  if (k == 1) {
    if (n == 1)
      return puts("1"), 0;
    else
      return puts("-1"), 0;
  } else {
    for (int i = 0; i < (int)n - k + 2; i++) putchar('a' + i % 2);
    for (int i = 0; i < (int)k - 2; i++) putchar('c' + i);
    puts("");
  }
}
