#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int colr[N];
vector<int> h[N][2];
bool dfs(int u, int cl) {
  colr[u] = cl;
  for (int i = 0; i < h[u][1].size(); i++) {
    int j = h[u][1][i];
    if (colr[j] != -1) {
      if (colr[j] != cl) return false;
      continue;
    }
    if (!dfs(j, cl)) return false;
  }
  for (int i = 0; i < h[u][0].size(); i++) {
    int j = h[u][0][i];
    if (colr[j] != -1) {
      if (colr[j] == cl) return false;
      continue;
    }
    if (!dfs(j, !cl)) return false;
  }
  return true;
}
void ini(int u) {
  colr[u] = -1;
  for (int i = 0; i < h[u][0].size(); i++) {
    int j = h[u][0][i];
    if (colr[j] == -1) continue;
    ini(j);
  }
  for (int i = 0; i < h[u][1].size(); i++) {
    int j = h[u][1][i];
    if (colr[j] == -1) continue;
    ini(j);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    h[a][c].push_back(b);
    h[b][c].push_back(a);
  }
  memset(colr, -1, sizeof colr);
  for (int i = 1; i <= 1; i++) {
    if (colr[i] != -1) continue;
    if (!dfs(i, 1)) {
      ini(i);
      if (!dfs(i, 0)) {
        puts("Impossible");
        return 0;
      }
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; i++)
    if (colr[i] == 1) res.push_back(i);
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);
}
