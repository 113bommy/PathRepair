#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, N = 101010;
struct solver {
  int lim, col[N];
  bool vis[N];
  vector<pair<int, int> > g[N];
  void init(void) {
    memset(col, 0xff, sizeof col);
    memset(vis, false, sizeof vis);
  }
  void modify(int l, int r, int val) {
    if (!l) {
      if (!~col[r]) {
        col[r] = val;
      } else if (col[r] != val) {
        puts("0");
        exit(0);
      }
    } else {
      g[r].push_back({l - 1, val});
      g[l - 1].push_back({r, val});
    }
  }
  bool dfs(int x) {
    vis[x] = true;
    bool ret = true;
    for (auto v : g[x]) {
      if (~col[v.first] && col[v.first] != col[x] ^ v.second) {
        return false;
      }
      if (vis[v.first]) {
        continue;
      }
      col[v.first] = col[x] ^ v.second;
      ret &= dfs(v.first);
    }
    return ret;
  }
  int solve(void) {
    int ans = 1;
    for (int i = 0; i <= lim; i++) {
      if (!vis[i] && ~col[i]) {
        ans *= dfs(i);
      }
    }
    for (int i = lim; ~i; i--) {
      if (!vis[i]) {
        col[i] = 0;
        ans = ans * (int)dfs(i) * 2 % MOD;
      }
    }
    return ans;
  }
} a[2];
int n, m, idl[N << 1], idr[N];
char s[10];
int main(void) {
  scanf("%d%d", &n, &m);
  a[0].lim = -1;
  a[1].lim = -1;
  for (int i = 0; i < n; i++) {
    idl[n - 1 + i] = i >> 1;
    idr[n - 1 - i] = i >> 1;
    a[(n + i - 1) & 1].lim = max(a[(n + i) & 1].lim, i >> 1);
  }
  a[0].init();
  a[1].init();
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d%s", &x, &y, s);
    x--;
    y--;
    if (x + y < n - 1) {
      tie(x, y) = (pair<int, int>){n - 1 - y, n - 1 - x};
    }
    if (x < y) {
      swap(x, y);
    }
    a[(x + y) & 1].modify(idl[x + y], idr[x - y], s[0] == 'o');
  }
  cout << 1LL * a[0].solve() * a[1].solve() % MOD << endl;
  return 0;
}
