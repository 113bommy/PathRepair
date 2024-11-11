#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& x) {
  x = 0;
  int fl = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fl = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  x *= fl;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const int N = 100005;
int n, mxdeg, deg[N];
vector<int> edge[N];
vector<pair<int, int> > ans;
void dfs(int x, int f, int t) {
  ans.emplace_back(make_pair(x, t));
  if (t == mxdeg) {
    t = mxdeg - deg[x];
    ans.emplace_back(make_pair(x, t));
  }
  for (auto to : edge[x]) {
    if (to == f) continue;
    dfs(to, x, t + 1);
    t++;
    if (ans.back().second != t - 1) ans.emplace_back(make_pair(to, t - 1));
    ans.emplace_back(make_pair(x, t));
    if (f && t == mxdeg) {
      t = mxdeg - deg[x];
      ans.emplace_back(make_pair(x, t));
    }
  }
}
int main() {
  read(n);
  if (n == 1) {
    puts("1");
    puts("1 0");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    read(u, v);
    edge[u].emplace_back(v), edge[v].emplace_back(u);
    deg[u]++, deg[v]++;
    mxdeg = max(mxdeg, deg[u]);
    mxdeg = max(mxdeg, deg[v]);
  }
  dfs(1, 0, 0);
  printf("%d\n", (int)ans.size());
  for (auto k : ans) printf("%d %d\n", k.first, k.second);
  return 0;
}
