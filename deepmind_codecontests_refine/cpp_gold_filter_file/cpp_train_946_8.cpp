#include <bits/stdc++.h>
using namespace std;
const int N = 101010;
int fa[N], n, Q;
double f[N], prob[N];
vector<int> g[N];
void Dfs(int x) {
  for (int v : g[x]) {
    if (v == fa[x]) continue;
    fa[v] = x;
    f[x] += prob[v];
    Dfs(v);
  }
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &prob[i]);
    prob[i] = 1 - prob[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u++;
    v++;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  Dfs(1);
  double Ans = 0;
  for (int i = 1; i <= n; i++) {
    Ans += prob[i] * (1 - f[i]);
  }
  scanf("%d", &Q);
  while (Q--) {
    int x;
    double p;
    scanf("%d%lf", &x, &p);
    x++;
    double delta = (1 - p - prob[x]);
    prob[x] = 1 - p;
    Ans += delta * (1 - f[x]);
    if (fa[x]) {
      f[fa[x]] += delta;
      Ans -= delta * prob[fa[x]];
    }
    printf("%.10f\n", Ans);
  }
  return 0;
}
