#include <bits/stdc++.h>
using namespace std;
vector<int> E[200005];
int rd[100005], cd[100005], ls[100005];
int main(int argc, char** argv) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u < v) {
      rd[u]++;
      cd[v]++;
      E[u].push_back(v);
    } else {
      rd[v]++;
      cd[u]++;
      E[v].push_back(u);
    }
  }
  long long now = 0;
  for (int i = 1; i <= n; i++) {
    ls[i] = rd[i] * cd[i];
    now += ls[i];
  }
  printf("%lld\n", now);
  int q;
  cin >> q;
  while (q--) {
    int u;
    scanf("%d", &u);
    for (int i = 0; i < E[u].size(); i++) {
      int v = E[u][i];
      rd[u]--;
      cd[u]++;
      rd[v]++;
      cd[v]--;
      now += rd[v] * cd[v] - ls[v];
      ls[v] = rd[v] * cd[v];
      E[v].push_back(u);
    }
    E[u].clear();
    now += rd[u] * cd[u] - ls[u];
    ls[u] = rd[u] * cd[u];
    printf("%lld\n", now);
  }
  return 0;
}
