#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
  int u, v, w;
} e[1000001];
bool cmp(edge i, edge j) { return i.w < j.w; }
int fa[100005];
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
int main() {
  cin >> n >> m;
  int a, b, c;
  for (int i = 1; i <= n; i++) fa[i] = i;
  scanf("%d%d%d", &a, &b, &c);
  for (int i = 1; i < m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
  sort(e + 1, e + m, cmp);
  int sum = 0, ans = 1e9;
  for (int i = 1; i < m; i++) {
    int uf = find(e[i].u), vf = find(e[i].v);
    if (uf != vf) {
      fa[uf] = vf;
      sum++;
      if (find(a) == find(b)) {
        ans = e[i].w;
        break;
      }
      if (sum == n - 1) break;
    }
  }
  cout << ans;
  return 0;
}
