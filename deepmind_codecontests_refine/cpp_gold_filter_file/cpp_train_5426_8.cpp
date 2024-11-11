#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
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
const int N = 3e5 + 5;
int first[N][20], second[N][20], n, a[N];
pair<int, int> tr[20][N << 2];
pair<int, int> operator+(pair<int, int> x, pair<int, int> y) {
  return {min(x.first, y.first), max(x.second, y.second)};
}
void build(int o, int x, int first, int second) {
  if (first == second) {
    tr[o][x] = {::first[first][o], ::second[second][o]};
    return;
  }
  int mid = first + second >> 1;
  build(o, x << 1, first, mid);
  build(o, x << 1 | 1, mid + 1, second);
  tr[o][x] = tr[o][x << 1] + tr[o][x << 1 | 1];
}
pair<int, int> que(int o, int x, int first, int second, int p, int q) {
  if (p <= first && second <= q) return tr[o][x];
  int mid = first + second >> 1;
  if (q <= mid) return que(o, x << 1, first, mid, p, q);
  if (p > mid) return que(o, x << 1 | 1, mid + 1, second, p, q);
  return que(o, x << 1, first, mid, p, q) +
         que(o, x << 1 | 1, mid + 1, second, p, q);
}
signed main() {
  read(n);
  if (n == 1) return write(0), 0;
  for (int i = 1; i <= n; i++) a[n + i] = a[n + n + i] = read(a[i]);
  for (int i = 1; i <= n * 3; i++)
    first[i][0] = max(1, i - a[i]), second[i][0] = min(n * 3, i + a[i]);
  build(0, 1, 1, n * 3);
  for (int j = 1; j <= 16; j++) {
    for (int i = 1; i <= n * 3; i++) {
      pair<int, int> x =
          que(j - 1, 1, 1, n * 3, first[i][j - 1], second[i][j - 1]);
      first[i][j] = x.first;
      second[i][j] = x.second;
    }
    build(j, 1, 1, n * 3);
  }
  for (int i = n + 1; i <= n << 1; i++) {
    int ans = 0, first = i, second = i;
    for (int j = 16; ~j; j--) {
      pair<int, int> x = que(j, 1, 1, n * 3, first, second);
      if (x.second - x.first + 1 < n)
        first = x.first, second = x.second, ans |= 1 << j;
    }
    write(ans + 1);
    putchar(' ');
  }
}
