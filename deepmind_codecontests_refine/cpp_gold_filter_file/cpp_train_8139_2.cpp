#include <bits/stdc++.h>
using namespace std;
int parent[200005];
int SZ[200005];
int boro[200005];
char ch[200005];
int n, m, ii, k;
vector<int> g[200005];
int vis[200005];
int Findparent(int x) {
  return (x == parent[x]) ? x : (parent[x] = Findparent(parent[x]));
}
void Union(int x, int y) { parent[Findparent(x)] = parent[Findparent(y)]; }
void Initialize() {
  for (int i = 1; i <= 200005 - 5; i++) {
    parent[i] = i;
    boro[i] = i;
    SZ[i] = 1;
  }
}
int func(int u) {
  int shuru = Findparent(u);
  int jabe = boro[shuru];
  set<int> s;
  for (int i = u; i <= jabe; i++) {
    int p = Findparent(i);
    s.insert(p);
    jabe = max(jabe, boro[p]);
    vis[i] = 1;
  }
  return (int)s.size();
}
void solve() {
  Initialize();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int par1 = Findparent(x);
    int par2 = Findparent(y);
    if (par1 == par2) continue;
    if (SZ[par1] > SZ[par2]) {
      SZ[par1] += SZ[par2];
      boro[par1] = max(boro[par1], boro[par2]);
      SZ[par2] = 0;
      parent[par2] = par1;
    } else {
      SZ[par2] += SZ[par1];
      boro[par2] = max(boro[par1], boro[par2]);
      SZ[par1] = 0;
      parent[par1] = par2;
    }
  }
  long long re = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    re += func(i) - 1;
  }
  printf("%lld\n", re);
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
