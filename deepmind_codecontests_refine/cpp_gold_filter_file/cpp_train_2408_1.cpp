#include <bits/stdc++.h>
using namespace std;
struct _e {
  int x, y;
  long long w;
} edges[2 * 200010];
bool cmp(struct _e e1, struct _e e2) { return e1.w < e2.w; }
int n, m, mn = 1;
long long cost;
int link[200010];
long long p[200010];
int find(int x) { return x == link[x] ? x : link[x] = find(link[x]); }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    if (p[mn] > p[i]) mn = i;
    link[i] = i;
  }
  for (int i = 1; i <= m; ++i) cin >> edges[i].x >> edges[i].y >> edges[i].w;
  for (int i = 1; i <= n; ++i)
    if (mn != i)
      edges[m + i].x = mn, edges[m + i].y = i, edges[m + i].w = p[mn] + p[i];
  sort(edges + 1, edges + 1 + m + n, cmp);
  for (int i = 1; i <= m + n; ++i) {
    int px = find(edges[i].x);
    int py = find(edges[i].y);
    if (px != py) {
      link[py] = px;
      cost += edges[i].w;
    }
  }
  cout << cost << endl;
  return 0;
}
