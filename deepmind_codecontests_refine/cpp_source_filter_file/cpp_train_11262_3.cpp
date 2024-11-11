#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace _buff {
const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
  if (ib == ie) {
    ib = ibuf;
    ie = ibuf + fread(ibuf, 1, BUFF, stdin);
  }
  return ib == ie ? -1 : *ib++;
}
}  // namespace _buff
LL read() {
  using namespace _buff;
  LL ret = 0;
  bool pos = true;
  char c = getc();
  for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
    assert(~c);
  }
  if (c == '-') {
    pos = false;
    c = getc();
  }
  for (; c >= '0' && c <= '9'; c = getc()) {
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
  }
  return pos ? ret : -ret;
}
const size_t N = 1e5 + 5;
vector<int> g[N];
LL deg[N];
int main() {
  int n = read(), m = read();
  for (int i = 0; i < m; ++i) {
    int x = read(), y = read();
    if (x < y) swap(x, y);
    ++deg[x];
    ++deg[y];
    g[x].emplace_back(y);
  }
  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (LL)g[i].size() * (deg[i] - (LL)g[i].size());
  }
  printf("%lld\n", ans);
  int q = read();
  while (q--) {
    int x = read();
    ans -= (LL)g[x].size() * (deg[x] - (LL)g[x].size());
    for (int y : g[x]) {
      ans += deg[y] - 2 * (LL)g[y].size() - 1;
      g[y].emplace_back(x);
    }
    g[x].clear();
    printf("%lld\n", ans);
  }
  return 0;
}
