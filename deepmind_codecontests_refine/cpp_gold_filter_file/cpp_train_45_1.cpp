#include <bits/stdc++.h>
using namespace std;
int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 100000, MOD = (int)1e9 + 7;
vector<pair<int, int> > e[N], q[N];
int dep[N], djs[N], ans[N];
struct D {
  int64_t cnt, sum, sum2;
  D operator~() { return operator+(*this); }
  D operator*(int64_t o) const {
    return {cnt, (sum + cnt * o) % MOD,
            (sum2 + sum * 2 * o + o * o % MOD * cnt) % MOD};
  }
  D operator+(const D &o) const {
    return {cnt + o.cnt, (sum + o.sum) % MOD, (sum2 + o.sum2) % MOD};
  }
  D operator-(const D &o) const {
    return {cnt - o.cnt, (sum - o.sum) % MOD, (sum2 - o.sum2) % MOD};
  }
} a[N], s[N];
int find(int v) {
  while (djs[v] != v) djs[v] = djs[djs[v]], v = djs[v];
  return v;
}
void dfs(int v, int p, int d) {
  dep[v] = d;
  s[v] = {1, 0, 0};
  for (auto ee : e[v])
    if (ee.first != p) {
      dfs(ee.first, v, (d + ee.second) % MOD);
      s[v] = s[v] + s[ee.first] * ee.second;
    }
}
void tarjan(int v, D all) {
  a[v] = all;
  djs[v] = v;
  for (auto qq : q[v])
    if (djs[qq.first] != -1) {
      int x = v, y = qq.first, id = qq.second;
      if (id < 0) id = ~id, swap(x, y);
      int w = find(qq.first), d = (int64_t(dep[x]) + dep[y] - 2 * dep[w]) % MOD;
      ans[id] =
          (w == y ? a[x] - ~((a[y] - s[y]) * d) : ~(s[y] * d) - a[x]).sum2;
    }
  for (auto ee : e[v])
    if (djs[ee.first] == -1) {
      tarjan(ee.first,
             (all - s[ee.first] * ee.second) * ee.second + s[ee.first]);
      djs[ee.first] = v;
    }
}
int main() {
  int n = ri();
  for (int i = (0); i < (n - 1); i++) {
    int v = ri() - 1, u = ri() - 1, w = ri();
    e[v].push_back({u, w});
    e[u].push_back({v, w});
  }
  int m = ri();
  for (int i = (0); i < (m); i++) {
    int v = ri() - 1, u = ri() - 1;
    q[v].push_back({u, i});
    q[u].push_back({v, ~i});
  }
  dfs(0, -1, 0);
  fill_n(djs, n, -1);
  tarjan(0, s[0]);
  for (int i = (0); i < (m); i++) printf("%d\n", (ans[i] + MOD) % MOD);
}
