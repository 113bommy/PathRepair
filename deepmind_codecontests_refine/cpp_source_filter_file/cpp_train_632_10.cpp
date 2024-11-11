#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n, k, q;
bool check(long long x, long long n, long long k) {
  if (n & 1) {
    if (x == n && k) return 1;
    n--;
    k--;
  }
  if (k - n / 2 > 0) {
    k -= n / 2;
    if (x % 2 == 0) return 1;
    x = x / 2 + 1;
    k = n / 2 - k;
    if (x > k) return 1;
    return 0;
  } else {
    if (x & 1) return 0;
    x = x / 2;
    k = n / 2 - k;
    if (x > k) return 1;
    return 0;
  }
}
signed main() {
  n = read(), k = read(), q = read();
  while (q--) {
    long long x = read();
    if (check(x, n, k))
      printf("X\n");
    else
      printf(".\n");
  }
  return 0;
}
