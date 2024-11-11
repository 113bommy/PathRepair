#include <bits/stdc++.h>
using namespace std;
int par[2010];
int rankk[2010];
int n;
void init() {
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
    rankk[i] = 1;
  }
}
int findset(int u) {
  if (u == par[u])
    return u;
  else
    return par[u] = findset(par[u]);
}
void link(int u, int v) {
  int a = findset(u);
  int b = findset(v);
  if (a != b) {
    par[b] = a;
    rankk[a] += rankk[b];
  }
}
int main() {
  int k, m, u, v;
  scanf("%d", &n);
  ;
  init();
  scanf("%d", &k);
  ;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &u);
    ;
    scanf("%d", &v);
    ;
    link(u, v);
  }
  scanf("%d", &m);
  ;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &u);
    ;
    scanf("%d", &v);
    ;
    int a = findset(u);
    int b = findset(v);
    if (a == b) rankk[a] = 0;
  }
  int maxx = 0;
  for (int i = 1; i <= n; ++i) maxx = max(maxx, rankk[findset(i)]);
  cout << maxx << endl;
  return 0;
}
