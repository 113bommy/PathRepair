#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
int _MAX(int a, int b) { return a > b ? a : b; }
int _MIN(int a, int b) { return a > b ? b : a; }
int Scan() {
  int res = 0, flag = 0;
  char ch;
  if ((ch = getchar()) == '-')
    flag = 1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
  return flag ? -res : res;
}
void Out(int a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) Out(a / 10);
  putchar(a % 10 + '0');
}
const int N = 100005;
long long muti_mod(long long a, long long b, long long c) {
  a %= c;
  b %= c;
  long long ret = 0;
  while (b) {
    if (b & 1) {
      ret += a;
      if (ret >= c) ret -= c;
    }
    a <<= 1;
    if (a >= c) a -= c;
    b >>= 1;
  }
  return ret;
}
long long pow_mod(long long x, long long n, long long mod) {
  if (n == 1) return x % mod;
  int bit[64], k = 0;
  while (n) bit[k++] = n & 1, n >>= 1;
  long long ret = 1;
  for (k = k - 1; k >= 0; --k) {
    ret = muti_mod(ret, ret, mod);
    if (bit[k] == 1) ret = muti_mod(ret, x, mod);
  }
  return ret;
}
int eul(long long p, long long k) {
  for (int i = 2; i < p; ++i)
    if ((p - 1) % i == 0 && pow_mod(k, (long long)i, p) == 1) return i;
}
int main() {
  long long p, k;
  scanf("%lld%lld", &p, &k);
  if (k == 0)
    printf("%lld\n", pow_mod(p, p, 1000000007));
  else if (k == 1)
    printf("%lld\n", pow_mod(p, p - 1, 1000000007));
  else {
    int temp = eul(p, k);
    printf("%lld\n", pow_mod(p, (p - 1) / temp, 1000000007));
  }
  return 0;
}
