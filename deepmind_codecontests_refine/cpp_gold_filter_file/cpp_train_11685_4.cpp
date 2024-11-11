#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAX1 = 1e5 + 5;
const int MAX2 = 2e5 + 5;
struct Tree {
  int n, m, mxdeg;
  int to[MAX2], next[MAX2];
  int head[MAX1], deg[MAX1];
  vector<pii> v;
  void add(int u, int v) {
    to[++m] = v;
    next[m] = head[u];
    head[u] = m;
    ++deg[u];
    mxdeg = max(mxdeg, deg[u]);
  }
  void dfs(int cur, int fa, int time) {
    v.push_back({cur, time});
    int mtime = time;
    for (int i = head[cur]; i; i = next[i]) {
      if (to[i] != fa) {
        if (time == mxdeg) {
          time = mxdeg - deg[cur];
          v.push_back({cur, time});
        }
        dfs(to[i], cur, ++time);
        v.push_back({cur, time});
      }
    }
    if (mtime != 0 && time != mtime - 1) {
      v.push_back({cur, mtime - 1});
    }
  }
} tr;
int n;
int main() {
  scanf("%d", &n);
  tr.n = n;
  int u, v;
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    tr.add(u, v);
    tr.add(v, u);
  }
  tr.dfs(1, 0, 0);
  printf("%d\n", tr.v.size());
  for (pii p : tr.v) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}
