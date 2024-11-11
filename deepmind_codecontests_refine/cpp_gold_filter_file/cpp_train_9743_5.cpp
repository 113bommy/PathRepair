#include <bits/stdc++.h>
using namespace std;
const int __ = 1e6 + 5;
int in[__], self[__];
struct uf {
  static const int __ = 1e6 + 5;
  int pre[__];
  uf() { memset(pre, -1, sizeof(pre)); }
  void un(int x, int y) {
    x = fd(x), y = fd(y);
    if (x == y) return;
    if (pre[x] < pre[y])
      pre[x] += pre[y], pre[y] = x;
    else
      pre[y] += pre[x], pre[x] = y;
  }
  int fd(int x) {
    if (pre[x] < 0) return x;
    return pre[x] = fd(pre[x]);
  }
  void clear() { memset(pre, -1, sizeof(pre)); }
} dsu;
int main() {
  int n, m, huan = 0, root;
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    dsu.un(x, y);
    if (x != y)
      in[x]++, in[y]++;
    else
      self[x]++, huan++;
    root = x;
  }
  long long ans = 0;
  for (int i = (1); i <= (n); i++) {
    if (self[i] || in[i])
      if (dsu.fd(i) != dsu.fd(root)) return !printf("0\n");
    ans += 1ll * self[i] * (m - 1);
    ans += (1ll * in[i] * (in[i] - 1)) / 2;
  }
  ans -= 1ll * huan * (huan - 1) / 2;
  printf("%lld\n", ans);
  return 0;
}
