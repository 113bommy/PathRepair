#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXM = 5010;
int n, m;
vector<int> e[MAXM];
int u[MAXM], v[MAXM];
int findway[MAXN];
int d[MAXN];
int getway(int u) {
  if (!findway[u]) {
    findway[u] = u == n ? 1 : -1;
    for (int i = 0; i < e[u].size(); i++) {
      int v = e[u][i];
      if (getway(v) == 1) findway[u] = 1;
    }
  }
  return findway[u];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u[i], &v[i]);
    e[u[i]].push_back(v[i]);
  }
  memset(findway, 0, sizeof(findway));
  getway(1);
  for (int i = 1; i <= n; i++) findway[i] = findway[i] == 0 ? -1 : findway[i];
  bool adjust = 1;
  for (int i = 1; i <= n && adjust; i++) {
    adjust = 0;
    for (int j = 1; j <= m; j++) {
      if (findway[u[j]] == 1 && findway[v[j]] == 1) {
        if (d[u[j]] < d[v[j]] + 1) {
          d[u[j]] = d[v[j]] + 1;
          adjust = 1;
        }
        if (d[u[j]] > d[v[j]] + 2) {
          d[u[j]] = d[v[j]] + 2;
          adjust = 1;
        }
      }
    }
  }
  if (adjust)
    printf("No\n");
  else {
    printf("Yes\n");
    for (int j = 1; j <= m; j++) {
      if (findway[u[j]] == 1 && findway[v[j]] == 1)
        printf("%d\n", d[u[j]] - d[v[j]]);
      else
        printf("1\n");
    }
  }
  return 0;
}
