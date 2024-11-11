#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int w[N], pre[N], sz[N], tot, nw;
map<int, int> mp;
int id(int x) {
  if (mp.count(x)) return mp[x];
  sz[++tot] = 1;
  pre[tot] = tot;
  return mp[x] = tot;
}
int f(int x) {
  if (pre[x] == x) return x;
  nw ^= w[x];
  return f(pre[x]);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q, x, y, z, opt, las = 0;
  cin >> q;
  while (q--) {
    cin >> opt >> x >> y;
    x ^= las;
    y ^= las;
    if (x > y) swap(x, y);
    x--;
    x = id(x);
    y = id(y);
    if (opt == 1) {
      nw = las;
      x = f(x);
      y = f(y);
      cin >> z;
      z ^= nw;
      if (x == y) continue;
      if (sz[x] > sz[y]) swap(x, y);
      pre[x] = y;
      sz[y] += sz[x];
      w[x] = z;
    } else {
      nw = 0;
      x = f(x);
      y = f(y);
      if (x != y)
        cout << -1 << '\n', las = 1;
      else
        cout << (las = nw) << '\n';
    }
  }
  return 0;
}
