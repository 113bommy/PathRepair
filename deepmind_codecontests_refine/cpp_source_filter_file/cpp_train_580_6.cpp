#include <bits/stdc++.h>
using namespace std;
int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    y = 0;
    x = 1;
    return a;
  }
  int r = exgcd(b, a % b, x, y);
  int tmp = y;
  y = x - (a / b) * y;
  x = tmp;
  return r;
}
int t, n, a[200005], s, ans[200005], k1, k2, len, nos[200005];
set<int> se[200005];
unordered_map<int, bool> vis, id, v;
int main() {
  while (~scanf("%d%d", &t, &n)) {
    vis.clear();
    id.clear();
    v.clear();
    for (int i = 0; i < 200005; ++i) se[i].clear();
    memset(ans, -1, 4 * n + 4);
    a[0] = s = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      s = (s + a[i]) % t;
    }
    a[1] = 0;
    for (int i = 2; i <= n; ++i) a[i] = (a[i - 1] + a[i]) % t;
    int g = exgcd(s, t, k1, k2), cnt = 0, len = t / g;
    for (int i = 1; i <= n; ++i) {
      if (!vis.count(a[i])) {
        vis[a[i]] = true;
        if (!id[a[i] % g]) id[a[i] % g] = ++cnt;
        nos[i] = 1LL * k1 * (a[i] % g - a[i]) / g % len;
        nos[i] = (nos[i] + len) % len;
        v[nos[i]] = i;
        se[id[a[i] % g]].insert(nos[i]);
      } else
        ans[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      if (ans[i] == -1) {
        set<int>::iterator it = se[id[a[i] % g]].find(nos[i]);
        if (it == se[id[a[i] % g]].begin())
          it = --se[id[a[i] % g]].end();
        else
          --it;
        int s1 = nos[i], s2 = *it, tmp = s1 - s2;
        ans[i] = tmp != 0 ? (tmp + len) % len : len;
      }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
