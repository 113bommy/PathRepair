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
const int N = 1005;
int n, p[N], a[N], ans[N][N];
int fix(int x) { return x > n + 1 ? x - n - 1 : x; }
signed main() {
  read(n);
  for (int i = 1; i <= n; i++) p[i] = i, read(a[i]);
  sort(p + 1, p + 1 + n, [&](int x, int y) { return a[x] > a[y]; });
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= a[p[i]]; j++) ans[fix(i + j - 1)][p[i]] = 1;
  write(n + 1);
  puts("");
  for (int i = 1; i <= n + 1; i++, puts(""))
    for (int j = 1; j <= n; j++) write(ans[i][j]);
}
