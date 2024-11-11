#include <bits/stdc++.h>
using namespace std;
int n, m;
const int INF = 0x3f3f3f3f;
const int MAXN = 2000005;
const int maxn = 2000005;
vector<int> G[MAXN];
stack<int> Tar;
int dfn[maxn], low[maxn], idx = 0, Bcnt = 0;
;
bool instack[maxn];
int belong[MAXN];
void Tarjan(int i) {
  dfn[i] = low[i] = ++idx;
  instack[i] = true;
  Tar.push(i);
  for (int j = 0; j < G[i].size(); j++) {
    int v = G[i][j];
    if (!dfn[v]) {
      Tarjan(v);
      if (low[i] > low[v]) low[i] = low[v];
    } else if (instack[v] && low[i] > dfn[v])
      low[i] = dfn[v];
  }
  if (dfn[i] == low[i]) {
    Bcnt++;
    while (!Tar.empty()) {
      int j = Tar.top();
      Tar.pop();
      instack[j] = false;
      belong[j] = Bcnt;
      if (j == i) break;
    }
  }
}
vector<int> Array[MAXN];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i < (n + 1); i++) {
    int sz;
    scanf("%d", &sz);
    for (int j = (0); j < (sz); j++) {
      int p;
      scanf("%d", &p);
      p--;
      Array[i].push_back(p);
    }
  }
  for (int i = (1); i < (n); i++) {
    int sz = min(Array[i].size(), Array[i + 1].size());
    int flag = 0;
    for (int j = (0); j < (sz); j++) {
      int u = Array[i][j], v = Array[i + 1][j];
      if (u > v) {
        int u = Array[i][j], v = Array[i + 1][j];
        G[u * 2 + 1].push_back(u * 2);
        G[v * 2].push_back(v * 2 + 1);
        flag = true;
        break;
      } else if (u < v) {
        G[v * 2].push_back(u * 2);
        G[u * 2 + 1].push_back(v * 2 + 1);
        flag = true;
        break;
      }
    }
    if (Array[i].size() > Array[i + 1].size() && !flag) {
      return 0 * puts("No");
    }
  }
  for (int i = (0); i < ((m << 1)); i++)
    if (!dfn[i]) Tarjan(i);
  for (int i = (0); i < (m); i++)
    if (belong[i * 2] == belong[i * 2 + 1]) return 0 * printf("No\n");
  printf("Yes\n");
  vector<int> res;
  for (int i = (0); i < (m); i++) {
    if (belong[i * 2] < belong[i * 2 + 1]) res.push_back(i);
  }
  printf("%lu\n", res.size());
  for (int i = (0); i < (res.size()); i++) {
    printf("%d%c", res[i] + 1, " \n"[i == res.size() - 1]);
  }
  return 0;
}
