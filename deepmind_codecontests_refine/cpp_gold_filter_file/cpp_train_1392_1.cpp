#include <bits/stdc++.h>
using namespace std;
struct pii {
  int x, y;
};
inline int lowbit(const int x) { return x & (-x); };
const int N = 100005;
struct Tree {
  vector<int> adj[N];
  int ld[N], rd[N], sz[N], id[N];
  int big[N], dep[N];
  int n, ind, rt;
  void trprint() {
    cout << "rt=" << rt << ' ' << "n=" << n << endl;
    for (int i = 1; i <= n; ++i)
      cout << "i=" << i << ' ' << ld[i] << ' ' << rd[i] << ' ' << sz[i] << ' '
           << big[i] << endl;
  }
  void trinit() {
    for (int i = 1; i <= n; ++i) adj[i].clear();
    n = ind = 0;
    rt = 1;
  }
  inline void addedge(const int x, const int y) {
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  void trdfs(int x, int pre) {
    ld[x] = ++ind;
    id[ind] = x;
    sz[x] = 1;
    big[x] = 0;
    dep[x] = dep[pre] + 1;
    for (auto &y : adj[x])
      if (y != pre) {
        trdfs(y, x);
        sz[x] += sz[y];
        if (sz[y] > sz[big[x]]) big[x] = y;
      }
    rd[x] = ld[x] + sz[x] - 1;
  }
};
pii q[N];
vector<int> query[N];
int cnt[N];
int ans[N];
string nam[N];
map<string, int> mp[N];
struct DsuOnTree : Tree {
  void dsuprint() {
    for (int i = 1; i <= n; ++i)
      cout << "i=" << i << ' ' << nam[i] << ' ' << ans[i] << endl;
  }
  inline void add(const int x, const int t) {
    int nw = (mp[dep[x]][nam[x]] += t);
    if (nw == 1 && t == 1) ++cnt[dep[x]];
    if (nw == 0 && t == -1) --cnt[dep[x]];
  }
  void calcans(const int u) {
    for (const auto &i : query[u])
      if (q[i].y <= n) ans[i] = cnt[q[i].y];
  }
  void relax(const int x) {
    for (int i = ld[x]; i <= rd[x]; ++i) add(id[i], -1);
  }
  void dfs(int x, int pre, int keep) {
    for (auto &y : adj[x])
      if (y != pre && y != big[x]) dfs(y, x, 0);
    if (big[x]) dfs(big[x], x, 1);
    add(x, 1);
    for (auto &y : adj[x])
      if (y != pre && y != big[x])
        for (int i = ld[y]; i <= rd[y]; ++i) add(id[i], 1);
    calcans(x);
    if (!keep) relax(x);
  }
} tr;
int n, m;
int main() {
  tr.trinit();
  cin >> n;
  ++n;
  tr.n = n;
  for (int i = 2, x, y; i <= n; ++i)
    cin >> nam[i], scanf("%d", &x), tr.addedge(x + 1, i);
  tr.trdfs(1, 0);
  cin >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    ++x;
    y += tr.dep[x];
    q[i] = {x, y};
    query[x].push_back(i);
  }
  tr.dfs(1, 0, 0);
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}
