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
const int N = 7005;
int n, m, mu[N];
bitset<N> f[N], g[N], a[100005];
void init(int n) {
  mu[1] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = i * 2; j <= n; j += i) mu[j] -= mu[i];
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i) f[j][i] = 1, g[i][j] = mu[j / i] != 0;
}
void doit() {
  int o, x, y, z;
  read(o);
  read(x);
  if (o == 1) a[x] = f[read(y)];
  if (o == 2) a[x] = a[read(y)] ^ a[read(z)];
  if (o == 3) a[x] = a[read(y)] & a[read(z)];
  if (o == 4) write((g[read(y)] & a[x]).count() & 1);
}
signed main() {
  read(n);
  read(m);
  init(7000);
  while (m--) doit();
}
