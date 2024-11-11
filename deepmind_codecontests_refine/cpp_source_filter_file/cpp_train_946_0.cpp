#include <bits/stdc++.h>
double p[100006], q[100006], P, ans;
int a, i, x, y, Q, pa[100006];
std::vector<int> G[100006];
void dfs(int r, int par) {
  pa[r] = par;
  for (int k = 0; k < G[r].size(); k++) {
    if (G[r][k] != par) {
      q[r] += p[G[r][k]];
      dfs(G[r][k], r);
    }
  }
}
int main() {
  scanf("%d", &a);
  for (i = 0; i < a; i++) scanf("%lf", &p[i]), p[i] = 1 - p[i], ans += p[i];
  for (i = 1; i < a; i++) {
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(0, -1);
  for (i = 0; i < a; i++) ans -= p[i] * q[i];
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%lf", &x, &P);
    P = 1 - P;
    ans -= p[x];
    ans += P;
    if (pa[x] != -1) {
      ans += p[pa[x]] * q[pa[x]];
      q[pa[x]] += (P - p[x]);
      ans -= p[pa[x]] * q[pa[x]];
    }
    ans += p[x] * q[x];
    ans -= P * q[x];
    p[x] = P;
    printf("%lf", ans);
  }
}
