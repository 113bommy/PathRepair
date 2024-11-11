#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
  int u, v, vis;
} e[200005 * 2];
int le;
vector<int> G[200005];
int bin[200005];
int find(int a) {
  if (bin[a] != a) bin[a] = find(bin[a]);
  return bin[a];
}
void get(int a, int b) {
  int x = find(a);
  int y = find(b);
  if (x != y) bin[x] = y;
}
int num[200005];
int z[200005];
int k;
int res[200005];
int cnt[200005];
int mark[200005];
void dfs(int x) {
  mark[x] = 1;
  int y;
  for (int& i = cnt[x]; i < G[x].size(); i++) {
    int p = G[x][i];
    if (e[p].vis) continue;
    y = e[p].v;
    e[p].vis = 1;
    e[p ^ 1].vis = 1;
    dfs(y);
  }
  res[k++] = x;
}
int main() {
  le = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++) bin[i] = i;
  for (int i = 0; i < m; i++) {
    le += 2;
    int u, v;
    scanf("%d%d", &u, &v);
    e[i * 2].u = u;
    e[i * 2].v = v;
    e[i * 2].vis = 0;
    e[i * 2 + 1].u = v;
    e[i * 2 + 1].v = u;
    e[i * 2 + 1].vis = 0;
    G[u].push_back(i * 2);
    G[v].push_back(i * 2 + 1);
    get(u, v);
  }
  memset(num, 0, sizeof(num));
  memset(z, -1, sizeof(z));
  for (int i = 0; i <= n; i++) find(i);
  for (int i = 1; i <= n; i++) {
    if (G[i].size() % 2 == 1) {
      if (z[bin[i]] == -1)
        z[bin[i]] = i;
      else {
        int u = i, v = z[bin[i]];
        z[bin[i]] = -1;
        e[le].u = u;
        e[le].v = v;
        e[le].vis = 0;
        e[le + 1].u = v;
        e[le + 1].v = u;
        e[le + 1].vis = 0;
        G[u].push_back(le);
        G[v].push_back(le + 1);
        le += 2;
      }
    }
  }
  for (int i = 1; i <= n; i++) num[bin[i]] += G[i].size();
  for (int i = 0; i <= n; i++)
    if ((num[i] / 2) % 2 == 1) {
      e[le].u = i;
      e[le].v = i;
      e[le].vis = 0;
      e[le + 1].u = i;
      e[le + 1].v = i;
      e[le + 1].vis = 0;
      G[i].push_back(le);
      G[i].push_back(le + 1);
      le += 2;
      num[i] += 2;
    }
  printf("%d\n", le / 2);
  for (int i = 1; i <= n; i++) {
    if (mark[i]) continue;
    k = 0;
    dfs(i);
    for (int j = 0; j < k - 1; j++) {
      if (j % 2 == 0)
        printf("%d %d\n", res[j], res[j + 1]);
      else
        printf("%d %d\n", res[j + 1], res[j]);
    }
  }
}
