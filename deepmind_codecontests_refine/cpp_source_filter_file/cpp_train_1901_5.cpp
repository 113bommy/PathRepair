#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int maxm = 55;
const int inf = 2147483647;
const long long p = 1000000007;
const double eps = 1e-9;
const long long INF = 9223372036854775807ll;
int dep[maxn], maxdep;
vector<int> g[maxn];
vector<int> gdep[maxn];
pair<int, int> query(vector<int> &a) {
  if (a.empty()) return make_pair(-1, -1);
  printf("? %d", (int)a.size());
  for (register int i = (0); i < (a.size()); ++i) printf(" %d", a[i]);
  printf("\n");
  fflush(stdout);
  int ans1, ans2;
  scanf("%d%d", &ans1, &ans2);
  return make_pair(ans1, ans2);
}
void answer(int a, int b) {
  printf("! %d %d\n", a, b);
  fflush(stdout);
  char c[15];
  scanf("%s", c);
  if (strcmp(c, "Incorrect") == 0) exit(0);
}
void dfs(int u, int f) {
  dep[u] = dep[f] + 1;
  maxdep = max(maxdep, dep[u]);
  gdep[dep[u]].push_back(u);
  for (register int i = (0); i < (g[u].size()); ++i) {
    if (g[u][i] != f) dfs(g[u][i], u);
  }
}
void dfs2(int u, int f, int deep, int len, vector<int> &a) {
  if (deep == len) a.push_back(u);
  for (register int i = (0); i < (g[u].size()); ++i) {
    if (g[u][i] != f) dfs2(g[u][i], u, deep + 1, len, a);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (register int i = (0); i < (n - 1); ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> node;
    for (register int i = (1); i < (n + 1); ++i) node.push_back(i);
    maxdep = 0;
    int rt, len;
    pair<int, int> xx;
    xx = query(node);
    rt = xx.first, len = xx.second;
    dep[0] = -1;
    dfs(rt, 0);
    int l = (len + 1) / 2, r = max(maxdep, len) + 1, s = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      int le, ts;
      xx = query(gdep[mid]);
      ts = xx.first, le = xx.second;
      if (le != len) {
        r = mid - 1;
      } else
        l = mid + 1, s = ts;
    }
    node.clear();
    dfs2(s, 0, 0, len, node);
    int tt;
    if (node.size() == 1)
      tt = node[0];
    else
      tt = query(node).first;
    answer(tt, s);
    for (register int i = (0); i < (n + 1); ++i) {
      g[i].clear();
      gdep[i].clear();
    }
  }
}
