#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
const int inf = (int)1e9 + 1;
const long long big = (long long)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;
vector<int> g[N];
int h[N];
int in[N], out[N];
vector<int> order;
void dfs(int u, int d) {
  h[u] = d;
  in[u] = (int)order.size();
  order.push_back(u);
  for (int v : g[u]) dfs(v, d + 1);
  out[u] = (int)order.size();
}
struct ST {
  int cnt;
  vector<long long> tree;
  ST() {}
  ST(int n) {
    cnt = 1;
    while (cnt < n) cnt <<= 1;
    tree.resize(cnt * 2 - 1, 0);
  }
  void upd(int x, int lx, int rx, int l, int r, long long v) {
    if (lx >= r || l >= rx)
      return;
    else if (lx >= l && rx <= r)
      tree[x] += v;
    else {
      upd(x * 2 + 1, lx, (lx + rx) / 2, l, r, v);
      upd(x * 2 + 2, (lx + rx) / 2, rx, l, r, v);
    }
  }
  long long get(int x) {
    long long res = tree[x];
    while (x > 0) {
      x = (x - 1) / 2;
      res += tree[x];
    }
    return res;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    g[p].push_back(i);
  }
  dfs(0, 0);
  ST sum(n), add(n);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int u;
      long long x, k;
      cin >> u >> x >> k;
      u--;
      sum.upd(0, 0, sum.cnt, in[u], out[u], x + h[u] * k);
      add.upd(0, 0, add.cnt, in[u], out[u], k);
    } else {
      int u;
      cin >> u;
      u--;
      cout << (sum.get(sum.cnt - 1 + in[u]) % MOD -
               add.get(add.cnt - 1 + in[u]) % MOD * h[u] % MOD + MOD) %
                  MOD
           << "\n";
    }
  }
  return 0;
}
