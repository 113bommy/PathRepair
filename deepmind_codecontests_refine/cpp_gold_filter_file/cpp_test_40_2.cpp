#include <bits/stdc++.h>
namespace FastRead {
char __buff[5000];
int __lg = 0, __p = 0;
char nc() {
  if (__lg == __p) {
    __lg = fread(__buff, 1, 5000, stdin);
    __p = 0;
    if (!__lg) return EOF;
  }
  return __buff[__p++];
}
template <class T>
void read(T& __x) {
  T __sgn = 1;
  char __c;
  while (!isdigit(__c = nc()))
    if (__c == '-') __sgn = -1;
  __x = __c - '0';
  while (isdigit(__c = nc())) __x = __x * 10 + __c - '0';
  __x *= __sgn;
}
}  // namespace FastRead
using namespace FastRead;
using namespace std;
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const long double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, q, m, x, y;
int root[N], h[N], fr[N];
vector<int> G[N], path[N];
int find(int r) { return (root[r] == r ? r : root[r] = find(root[r])); }
void unite(int x, int y) {
  x = root[x];
  y = root[y];
  if (h[x] < h[y])
    root[x] = y;
  else if (h[x] > h[y])
    root[y] = x;
  else
    root[x] = y, ++h[y];
}
bool dfs(int curr, int parent, int asked, int cnt) {
  if (curr == asked) {
    path[cnt].push_back(curr);
    return 1;
  }
  for (auto i : G[curr])
    if (i != parent) {
      bool ok = dfs(i, curr, asked, cnt);
      if (ok == 1) {
        path[cnt].push_back(curr);
        return 1;
      }
    }
  return 0;
}
void Test() {
  int i;
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    path[i].clear(), fr[i] = 0, G[i].clear(), root[i] = i, h[i] = 1;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    if (find(x) == find(y)) continue;
    unite(x, y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  cin >> q;
  int cnt = 0;
  while (q--) {
    cin >> x >> y;
    ++fr[x], ++fr[y];
    dfs(x, 0, y, ++cnt);
  }
  int add = 0;
  for (i = 1; i <= n; i++) add += fr[i] & 1;
  if (add) return cout << "NO\n" << add / 2 << '\n', void();
  cout << "YES\n";
  for (i = 1; i <= cnt; i++) {
    cout << path[i].size() << '\n';
    reverse(path[i].begin(), path[i].end());
    for (auto j : path[i]) cout << j << ' ';
    cout << '\n';
  }
}
signed main() {
  int q = 1;
  while (q--) Test();
  return 0;
}
