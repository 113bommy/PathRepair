#include <bits/stdc++.h>
using namespace std;
int n, cnt, maxx, x, y;
int k[200005], d[200005], a[200005], dep[200005], v[200005];
int vet[400005], nxt[400005], head[200005];
vector<int> p[200005];
void add(int x, int y) {
  vet[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
void dfs(int u, int pre) {
  dep[u] = dep[pre] + 1;
  int res = 0;
  for (int i = 0; i < p[d[u]].size(); i++) {
    int t = p[d[u]][i];
    v[t]++;
    if (v[t] == dep[u] - 1) res = max(res, t);
    if (v[t] == dep[u]) k[u] = max(k[u], t);
  }
  res = max(res, max(k[u], k[pre]));
  a[u] = res;
  for (int e = head[u]; e; e = nxt[e])
    if (vet[e] != pre) dfs(vet[e], u);
  for (int i = 0; i < p[d[u]].size(); i++) v[p[d[u]][i]]--;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]), maxx = max(maxx, d[i]);
  ;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  for (int i = 1; i <= maxx; i++)
    for (int j = i; j <= maxx; j++) p[j].push_back(i);
  dfs(1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  puts("");
  return 0;
}
