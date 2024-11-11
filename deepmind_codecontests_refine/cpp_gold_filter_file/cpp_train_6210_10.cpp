#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
inline void read(Tp &x) {
  static char c;
  static bool neg;
  x = 0, c = getchar(), neg = false;
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') {
      neg = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (neg) {
    x = -x;
  }
}
const int N = 100000 + 5;
int n, m;
int line[N];
int f[N], g[N];
namespace BIT {
int t[N];
inline void clear() { memset(t, 0, sizeof(t)); }
inline void add(int x, int val) {
  for (; x < N; x += ((x) & -(x))) {
    t[x] = std::max(t[x], val);
  }
}
inline int query(int x) {
  int res = 0;
  for (; x > 0; x -= ((x) & -(x))) {
    res = std::max(res, t[x]);
  }
  return res;
}
}  // namespace BIT
int main() {
  read(n), read(m);
  for (int i = 1, l, r; i <= n; ++i) {
    read(l), read(r);
    ++line[l], --line[r + 1];
  }
  ++line[1];
  for (int i = 1; i <= m; ++i) {
    line[i] += line[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    f[i] = BIT::query(line[i]) + 1;
    BIT::add(line[i], f[i]);
  }
  BIT::clear();
  for (int i = m; i >= 1; --i) {
    g[i] = BIT::query(line[i]) + 1;
    BIT::add(line[i], g[i]);
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans = std::max(ans, f[i] + g[i] - 1);
  }
  printf("%d\n", ans);
  return 0;
}
