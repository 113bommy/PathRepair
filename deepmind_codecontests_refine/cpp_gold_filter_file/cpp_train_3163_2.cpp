#include <bits/stdc++.h>
using namespace std;
const int maxN = 100010;
int n, a[maxN];
vector<int> g[maxN];
pair<long long, long long> dfs(int v, int p = -1) {
  long long pl = 0, mn = 0;
  for (int i = (int)0; i <= (int)(int)g[v].size() - 1; ++i)
    if (g[v][i] != p) {
      pair<long long, long long> r = dfs(g[v][i], v);
      if (r.first > mn) mn = r.first;
      if (r.second > pl) pl = r.second;
    }
  long long res = a[v] + pl - mn;
  if (res < 0)
    pl -= res;
  else
    mn += res;
  return pair<long long, long long>(mn, pl);
}
int main() {
  scanf("%d", &n);
  for (int i = (int)0; i <= (int)n - 1 - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = (int)0; i <= (int)n - 1; ++i) scanf("%d", &a[i]);
  pair<long long, long long> res = dfs(0);
  printf("%I64d", res.first + res.second);
}
