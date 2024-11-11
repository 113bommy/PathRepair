#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> costo;
int n;
vector<int> path;
int grado[100000];
bool visited[100000];
long long minimo = 100000000000000;
int padreE = -1;
int abueloE = -1;
int color[100000];
void dfs(int v) {
  visited[v] = true;
  path.push_back(v);
  for (int u : adj[v]) {
    if (!visited[u]) {
      dfs(u);
    }
  }
}
void dfs(int i, int padre, int abuelo, long long acumulado) {
  if (i == n - 1) {
    if (acumulado < minimo) {
      minimo = acumulado;
      padreE = padre;
      abueloE = abuelo;
    }
    return;
  }
  if (padre != 0 && abuelo != 0)
    dfs(i + 1, 0, padre, acumulado + costo[0][path[i + 1]]);
  if (padre != 1 && abuelo != 1)
    dfs(i + 1, 1, padre, acumulado + costo[1][path[i + 1]]);
  if (padre != 2 && abuelo != 2)
    dfs(i + 1, 2, padre, acumulado + costo[2][path[i + 1]]);
}
int main() {
  scanf("%d", &n);
  vector<int> aux;
  adj.assign(n, aux);
  costo.assign(n, aux);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      costo[i].push_back(x);
    }
  }
  bool imposible = false;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
    grado[x - 1]++;
    grado[y - 1]++;
    if (grado[x - 1] > 2 || grado[y - 1] > 2) {
      imposible = true;
    }
  }
  if (imposible) {
    printf("-1\n");
    return 0;
  }
  int s;
  for (int i = 0; i < n; i++) {
    if (grado[i] == 1) {
      s = i;
    }
  }
  dfs(s);
  for (int i = 0; i < 3; i++) {
    dfs(0, i, -1, costo[i][path[0]]);
  }
  printf("%lld\n", minimo);
  color[path[n - 1]] = (padreE + 1);
  color[path[n - 2]] = (abueloE + 1);
  for (int i = n - 3; i >= 0; i--) {
    if (padreE != 0 && abueloE != 0) {
      color[path[i]] = 1;
      padreE = abueloE;
      abueloE = 0;
    } else if (padreE != 1 && abueloE != 1) {
      color[path[i]] = 2;
      padreE = abueloE;
      abueloE = 1;
    } else if (padreE != 2 && abueloE != 2) {
      color[path[i]] = 3;
      padreE = abueloE;
      abueloE = 2;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", color[i]);
  }
  printf("\n");
  return 0;
}
