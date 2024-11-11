#include <bits/stdc++.h>
using namespace std;
ifstream in("test.in");
ofstream out("test.out");
const int LOG = 2e1 + 0;
const int DIM = 1e6 + 5;
vector<int> edg[DIM], snk, src;
int rnk[DIM], wsn[DIM], msk[1 << LOG];
bool oki[DIM];
void dfs(int x, int s) {
  oki[x] = true;
  if (!edg[x].size()) {
    msk[1 << s] |= (1 << wsn[x]);
  }
  for (int y : edg[x]) {
    if (!oki[y]) {
      dfs(y, s);
    }
  }
}
int main(void) {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    edg[x].push_back(y);
    ++rnk[y];
  }
  for (int i = 1; i <= n; ++i) {
    if (!edg[i].size()) {
      wsn[i] = (int)snk.size();
      snk.push_back(i);
    }
    if (!rnk[i]) {
      src.push_back(i);
    }
  }
  int nr = 0;
  for (int x : src) {
    memset(oki, 0, sizeof oki);
    dfs(x, nr);
    ++nr;
  }
  int sz = (int)snk.size();
  bool ok = true;
  for (int m = 1; m < (1 << sz) - 1 and ok; ++m) {
    msk[m] = msk[m ^ (m & -m)] ^ msk[m & -m];
    if (__builtin_popcount(m) >= __builtin_popcount(msk[m])) {
      ok = false;
    }
  }
  cout << (ok ? "YES" : "NO");
  return 0;
}
