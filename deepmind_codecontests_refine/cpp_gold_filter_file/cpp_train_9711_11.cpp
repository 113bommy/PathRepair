#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x *= f, void();
}
template <typename T>
void ckmax(T &a, T b) {
  a = b > a ? b : a;
}
template <typename T>
void ckmin(T &a, T b) {
  a = b < a ? b : a;
}
const long long N = 1e6 + 5;
long long k, a[N], f[N], q, n;
inline void bag(long long v, long long w, long long cnt) {
  for (long long i = 1; i < cnt; i <<= 1) {
    cnt -= i;
    for (long long j = 1000000; j >= v * i; j--) {
      ckmax(f[j], f[j - v * i] + w * i);
    }
  }
  for (long long j = 1000000; j >= v * cnt; j--) {
    ckmax(f[j], f[j - v * cnt] + w * cnt);
  }
}
signed main() {
  read(k);
  for (long long i = 0; i < 6; i++) {
    read(a[i]);
  }
  for (long long i = 0; i <= 1000000; i++) {
    long long x = i, ws = 0;
    while (x) {
      if ((x % 10) % 3 == 0) f[i] += a[ws] * ((x % 10) / 3);
      x /= 10, ++ws;
    }
  }
  for (long long i = 0, pw = 1; i < 6; i++) {
    bag(3 * pw, a[i], min(3 * (k - 1), 1000000 / (3 * pw)));
    pw = 10 * pw;
  }
  for (read(q); q; q--) {
    read(n), printf("%lld\n", f[n]);
  }
  return 0;
}
