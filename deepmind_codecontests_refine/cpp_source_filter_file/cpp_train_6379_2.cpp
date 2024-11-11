#include <bits/stdc++.h>
using namespace std;
int n, m, u[2100000], v[2100000], c[2100000];
int d[21000], val[21000];
bool vis[4100000];
vector<pair<int, int> > vec[21000];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u[i], &v[i]);
    c[i] = 1;
    val[u[i]]++;
    val[v[i]]++;
    vec[max(u[i], v[i])].push_back(pair<int, int>(min(u[i], v[i]), i));
  }
  for (int u = 1; u <= n; u++) {
    for (pair<int, int> v : vec[u]) {
      if (!d[v.first]) {
        d[v.first]++;
        c[v.second]--;
        val[u]--;
      }
      vis[val[v.first]] = u;
    }
    for (pair<int, int> v : vec[u]) {
      if (vis[val[u]] != u) break;
      val[u]++;
      d[v.first]--;
      c[v.second]++;
    }
  }
  int tot = 0;
  for (int i = 1; i <= n; i++)
    if (d[i]) tot++;
  printf("%d\n", tot);
  for (int i = 1; i <= n; i++)
    if (d[i]) printf("%d ", i);
  putchar('\n');
  for (int i = 1; i <= m; i++) printf("%d %d %d\n", u[i], v[i], c[i]);
  return 0;
}
