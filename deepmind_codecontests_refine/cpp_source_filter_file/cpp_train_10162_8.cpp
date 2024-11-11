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
const int N = 1e5 + 5;
bool v[N];
int dis[N], n, m;
vector<pair<int, int>> g[N];
namespace basis {
int b[40];
void insert(int x) {
  for (int i = 30; ~i; i--)
    if (x >> i & 1) {
      if (b[i])
        x ^= b[i];
      else {
        b[i] = x;
        break;
      }
    }
}
int que(int x) {
  for (int i = 30; ~i; i--)
    if (x ^ b[i] < x) x ^= b[i];
  return x;
}
}  // namespace basis
void dfs(int x, int now) {
  v[x] = 1;
  dis[x] = now;
  for (auto [y, w] : g[x]) {
    if (v[y])
      basis::insert(now ^ w ^ dis[y]);
    else
      dfs(y, now ^ w);
  }
}
signed main() {
  read(n);
  read(m);
  for (int i = 1, x, y, z; i <= m; i++) {
    read(x);
    read(y);
    read(z);
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
  }
  dfs(1, 0);
  write(basis::que(dis[n]));
}
