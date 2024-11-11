#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
struct Query {
  int u;
  int k;
  int w;
  Query(int _u, int _k, int _w) {
    u = _u;
    k = _k;
    w = _w;
  }
};
long long deg[N];
vector<Query> qs[N];
vector<int> es[N];
long long wes[N];
int n;
bool on[N];
void dfs(int rt, int pos, long long tmp) {
  on[rt] = true;
  for (int i = 0; i < qs[rt].size(); ++i) {
    deg[pos] += qs[rt][i].w;
    if (pos + 1 + qs[rt][i].k <= n) {
      deg[pos + 1 + qs[rt][i].k] -= qs[rt][i].w;
    }
  }
  wes[rt] = tmp + deg[pos];
  for (int i = 0; i < es[rt].size(); ++i) {
    if (on[es[rt][i]]) continue;
    dfs(es[rt][i], pos + 1, wes[rt]);
  }
  for (int i = 0; i < qs[rt].size(); ++i) {
    deg[pos] -= qs[rt][i].w;
    if (pos + 1 + qs[rt][i].k <= n) {
      deg[pos + 1 + qs[rt][i].k] += qs[rt][i].w;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    es[u].push_back(v);
    es[v].push_back(u);
  }
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int u, k, w;
    scanf("%d %d %d", &u, &k, &w);
    qs[u].push_back(Query(u, k, w));
  }
  memset(wes, 0, sizeof(wes));
  memset(deg, 0, sizeof(deg));
  memset(on, false, sizeof(on));
  dfs(1, 1, 0);
  bool tag = true;
  for (int i = 1; i <= n; ++i) {
    if (tag)
      tag = false;
    else
      printf(" ");
    printf("%I64d", wes[i]);
  }
  printf("\n");
  return 0;
}
