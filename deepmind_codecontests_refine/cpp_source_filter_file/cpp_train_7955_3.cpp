#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
double eps = 1e-7;
long long int exp(long long int x, long long int y) {
  if (y < 0) return 0;
  long long int ret = 1;
  for (; y; y >>= 1, x = (x * x) % mod) {
    if (y & 1) ret = (ret * x) % mod;
  }
  return ret;
}
unsigned long long int pexp(unsigned long long int x,
                            unsigned long long int y) {
  if (y < 0) return 0;
  unsigned long long int ret = 1;
  for (; y; y >>= 1, x = (x * x)) {
    if (y & 1) ret = (ret * x);
  }
  return ret;
}
long long int gcd(long long int x, long long int y) {
  if (!x || !y) return x + y;
  return x % y == 0 ? y : gcd(y, x % y);
}
long long int lcm(long long int x, long long int y) {
  return x * (y / gcd(x, y));
}
long long int bsum(long long int u, long long int b) {
  long long int ret = 0;
  if (u < b) return u;
  while (u) {
    ret += u % b;
    u /= b;
  }
  return ret;
}
long long int prival(long long int u, long long int p) {
  long long int cn = 0;
  while (u % p == 0) {
    cn++;
    u = u / p;
  }
  return cn;
}
long long int minv(long long int a, long long int b) {
  return 1 < a ? b - minv(b % a, a) * b / a : 1;
}
long long int extm(long long int a, long long int b) {
  long long int ret = 0;
  while (a != 0) {
    if (a % 2 == 1) {
      ret += b;
      ret %= mod;
    }
    a >>= 1;
    b = (2 * b) % mod;
  }
  return ret;
}
long long int eaphi(long long int x) {
  long long int t = x, ret = x, i;
  for (i = 2; i * i <= x; i++) {
    if (t % i == 0) {
      ret -= ret / i;
      while (t % i == 0) t /= i;
    }
  }
  if (t != 1) ret -= ret / t;
  return ret;
}
long long int eadivc(long long int x) {
  long long int ret = 0;
  long long int i;
  for (i = 1; i * i <= x; i++) {
    if (x % i == 0 && i * i != x) ret += 2;
    if (x % i == 0 && i * i == x) ret += 1;
  }
  return ret;
}
long long int eadivs(long long int x) {
  long long int ret = 0;
  long long int i;
  for (i = 1; i * i <= x; i++) {
    if (x % i == 0 && i * i != x) ret += i + x / i;
    if (x % i == 0 && i * i == x) ret += i;
  }
  return ret;
}
long long int ndig(long long int x, long long int b) {
  long long int ret = 0;
  while (x) {
    x /= b;
    ret++;
  }
  return ret;
}
long long int rev(long long int n, long long int b) {
  long long int ret = 0;
  while (n) {
    ret = b * ret + n % b;
    n /= b;
  }
  return ret;
}
long long int sq(long long int x) {
  long long int t = (long long int)sqrt(x);
  for (long long int i = t - 2; i <= t + 2; i++)
    if (i * i == x) return abs(i);
  return -1;
}
long long int extexp(long long int x, long long int y) {
  if (y < 0) return 0;
  long long int ret = 1;
  for (; y; y >>= 1, x = extm(x, x)) {
    if (y & 1) ret = extm(ret, x);
  }
  return ret;
}
bool isprime(long long int x) {
  if (x <= 1) return false;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
int n;
void go_5(void) {
  printf("1 2 2\n");
  printf("1 3 1\n");
  printf("2 4 1\n");
  printf("4 5 1\n");
  printf("3 4\n");
  printf("4 5\n");
  exit(0);
}
int main(void) {
  cin >> n;
  int i;
  if (n == 5) go_5();
  for (i = 1; i <= n / 2; i++) printf("%d %d %d\n", i, i + n / 2, 1);
  for (i = n / 2 + 1; i <= n - 1; i++)
    printf("%d %d %d\n", i, i + 1, 2 * (i - n / 2) - 1);
  for (i = 1; i <= n / 2 - 1; i++) printf("%d %d\n", i, i + 1);
  printf("1 3");
  return 0;
}
