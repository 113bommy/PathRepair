#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
set<pair<int, int> > s;
int w[4005][4005];
int p[100005], r[100005], deg[100005];
void init(int n) {
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    r[i] = 0;
  }
}
int find(int x) {
  if (p[x] == x)
    return x;
  else
    return p[x] = find(p[x]);
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  ans--;
  if (r[x] < r[y])
    p[x] = y;
  else {
    p[y] = x;
    if (r[x] == r[y]) r[x]++;
  }
}
bool same(int x, int y) { return find(x) == find(y); }
vector<int> v;
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1) {
    puts("0");
    return 0;
  }
  init(n);
  ans = n - 1;
  if (n <= 4000) {
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      w[u][v] = w[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (!w[i][j]) unite(i, j);
    printf("%d\n", ans);
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++;
    deg[v]++;
    s.insert(pair<int, int>(u, v));
    s.insert(pair<int, int>(v, u));
  }
  for (int i = 1; i <= n; i++)
    if (deg[i] > n / 2) v.push_back(i);
  ans = (int)v.size();
  for (int i = 0; i < (int)v.size(); i++)
    for (int j = 1; j <= n; j++)
      if (!s.count(pair<int, int>(v[i], j))) {
        if (deg[j] > n / 2)
          unite(v[i], j);
        else
          unite(v[i], 0);
      }
  printf("%d\n", ans);
  return 0;
}
