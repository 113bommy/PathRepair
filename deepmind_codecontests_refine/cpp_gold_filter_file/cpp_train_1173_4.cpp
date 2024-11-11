#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  bool f = 0;
  char c = getchar();
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int N = 2e5 + 5;
int n, m, a[N], b[N];
signed main() {
  read(n);
  read(m);
  for (int i = 0; i < m; i++) read(a[i]), read(b[i]);
  long long sum = accumulate(b, b + m, 0ll);
  if (sum < n) return write(1), 0;
  if (sum > n) return write(-1), 0;
  sum = 0;
  for (int i = 0; i < m; i++) sum += 1ll * a[i] * b[i] % n;
  write(sum % n == 1ll * n * (n + 1) / 2 % n ? 1 : -1);
}
