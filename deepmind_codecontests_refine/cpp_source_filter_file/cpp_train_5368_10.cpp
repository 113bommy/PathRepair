#include <bits/stdc++.h>
using namespace std;
struct node {
  int v;
  long long w;
  node(){};
  node(int v, long long w) : v(v), w(w) {}
};
vector<vector<node> > G;
int b[22550];
long long solve(int s) {
  long long ans = 1000000000000000;
  int len = G[s].size();
  for (int i = 0; i < len; i++) {
    node p = G[s][i];
    if (b[p.v]) {
      ans = min(ans, p.w);
    }
  }
  if (ans == 1000000000000000) ans = -1;
  return ans;
}
int main() {
  int n, m, k, num;
  scanf("%d %d %d", &n, &m, &k);
  G.clear();
  G.resize(n + 5);
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long w;
    scanf("%d %d %I64d", &u, &v, &w);
    G[u].push_back(node(v, w));
    G[v].push_back(node(u, w));
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &num);
    b[num] = 1;
  }
  long long ans = 1000000000000000;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 1) continue;
    long long num = solve(i);
    if (num != -1) ans = min(ans, num);
  }
  if (ans == 1000000000000000) ans = -1;
  printf("%I64d\n", ans);
  return 0;
}
