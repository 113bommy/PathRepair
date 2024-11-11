#include <bits/stdc++.h>
using namespace std;
const int N = 200002;
vector<int> g[N];
int n;
int color[N];
vector<int> nom;
bool mark[N];
bool flag;
void dfs(int v) {
  int i, u, j;
  for (i = 0; i < g[v].size(); i++) {
    u = g[v][i];
    if (!mark[u]) {
      mark[u] = true;
      nom.push_back(u);
      color[u] *= -1;
      dfs(u);
      if (color[u] == -1 && g[u].size() % 2 == 1 ||
          color[u] == 1 && g[u].size() % 2 == 0) {
        nom.push_back(v);
        color[v] *= -1;
        nom.push_back(u);
        color[u] *= -1;
      }
      nom.push_back(v);
    }
  }
}
int main() {
  int i, x, y;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%d", &color[i]);
    if (color[i] == -1) flag = true;
  }
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (!flag) {
    printf("1");
    return 0;
  }
  mark[1] = true;
  nom.push_back(1);
  dfs(1);
  if (color[1] == -1 && g[1].size() % 2 == 1 ||
      color[1] == 1 && g[1].size() % 2 == 0) {
    nom.push_back(g[1][0]);
    nom.push_back(1);
    nom.push_back(g[1][0]);
  }
  for (i = 0; i < nom.size(); i++) printf("%d ", nom[i]);
  return 0;
}
