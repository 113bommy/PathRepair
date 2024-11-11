#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void write(T x) {
  int i = 20;
  char buf[21];
  buf[20] = '\n';
  do {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do {
    putchar(buf[i]);
  } while (buf[i++] != '\n');
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
int main() {
  long long n = readInt<long long>(), ans = 0;
  long long last[100100];
  memset(last, -1, sizeof(last));
  for (int i = 1; i <= n; i++) {
    long long x = readInt<long long>(), y = readInt<long long>();
    ans = 0;
    for (int d = 1; d * d <= x; d++) {
      if (x % d == 0) {
        int a = d;
        int b = x / d;
        if (last[a] + y < i) ans++;
        if (a != b && last[b] + y < i) ans++;
        last[a] = last[b] = i;
      }
    }
    cout << ans << endl;
  }
}
