#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int d[MAXN];
int fa[MAXN];
int n, m, u, v;
int od[MAXN];
int getfa(int x) {
  if (fa[x] == x) return fa[x];
  return fa[x] = getfa(fa[x]);
}
int ans = 0;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  d[0] = 2;
  while (m--) {
    scanf("%d%d", &u, &v);
    d[u]++;
    d[v]++;
    u = getfa(u);
    v = getfa(v);
    if (u == v) continue;
    fa[u] = v;
  }
  int need = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i] & 1) need++;
    od[getfa(i)] |= d[i] & 1;
  }
  for (int i = 1; i <= n; i++)
    if (getfa(i) == i && d[i] && (!od[i])) need += 2;
  if (od[getfa(1)] == 0 && need == 2) need = 0;
  cout << need / 2 << endl;
  return 0;
}
