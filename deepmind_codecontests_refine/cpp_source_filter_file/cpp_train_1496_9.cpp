#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > to[256];
int n, m, dad[256], mark[256], ans;
int find(int x) { return dad[x] = dad[x] == x ? x : find(dad[x]); }
void unif(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) dad[fx] = fy;
}
void dfs(int x, int flag) {
  ans += (mark[x] = flag) > 0;
  for (int i = 0; i < to[x].size(); i++)
    if (!mark[to[x][i].first])
      dfs(to[x][i].first, to[x][i].second ? flag : -flag);
}
int main() {
  register int i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n * 2; i++) dad[i] = i;
  for (i = 1; i <= n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    to[a].push_back(pair<int, int>(b, c));
    to[b].push_back(pair<int, int>(a, c));
    if (c) {
      unif(a, b);
      unif(a + n, b + n);
    } else {
      unif(a + n, b);
      unif(b + n, a);
    }
  }
  for (i = 1; i <= n; i++)
    if (find(i) == find(i + n)) goto Quit;
  for (i = 1; i <= n; i++)
    if (!mark[i]) dfs(i, 1);
  printf("%d\n", ans);
  for (i = 1; i <= n; i++)
    if (mark[i] > 0) printf("%d ", i);
  return 0;
Quit:
  puts("Impossible");
  return 0;
}
