#include <bits/stdc++.h>
using namespace std;
long long readint() {
  long long x = 0, s = 1;
  char c;
  while ((c = getchar()), c < '0' || c > '9') {
    if (c == '-') s = -1;
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
void putint(int x) {
  char c[20];
  if (!x) {
    putchar('0');
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  int i = 0;
  while (x > 0) c[++i] = x % 10, x /= 10;
  while (i) putchar(c[i--] + 48);
}
template <typename T>
void print(T x) {
  putint(x);
}
template <typename T, typename... A>
inline void print(T x, A... a) {
  print(x);
  putchar(' ');
  print(a...);
}
template <typename T>
void scan(T &x) {
  x = readint();
}
template <typename T, typename... A>
inline void scan(T &x, A &...a) {
  scan(x);
  scan(a...);
}
int32_t main() {
  long long n = readint();
  long long m = max(n + 1, 100LL);
  vector<long long> d(m + 1), cnt(10);
  auto fun = [&](long long x) -> long long {
    if (x <= 9) return x;
    long long s = 0;
    while (x) s += x % 10, x /= 10;
    return d[s];
  };
  for (long long i = 1; i <= m; i++) d[i] = fun(i);
  for (long long i = 1; i <= n; i++) cnt[d[i]]++;
  long long ans = 0;
  for (long long i = 1; i <= 9; i++)
    for (long long j = 1; j <= 9; j++)
      for (long long k = 1; k <= 9; k++)
        if (d[i * j] == k) ans += cnt[i] * cnt[j] * cnt[k];
  for (long long i = 1; i <= n; i++) ans -= n / i;
  printf("%lld\n", ans);
}
