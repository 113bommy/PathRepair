#include <bits/stdc++.h>
using namespace std;
int n, m, q;
short st[3030][3030][13 + 1];
vector<int> adj[3030];
char chega[3030][3030];
void dfs(int v, int s) {
  if (chega[s][v]) return;
  chega[s][v] = 1;
  for (int(i) = (0); (i) < (((int)(adj[v]).size())); (i)++) dfs(adj[v][i], s);
}
int main() {
  memset(st, -1, sizeof(st));
  scanf("%d %d %d", &n, &m, &q);
  for (int(i) = (0); (i) < (m); (i)++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
  }
  for (int(i) = (0); (i) < (n); (i)++) sort((adj[i]).begin(), (adj[i]).end());
  for (int(i) = (0); (i) < (n); (i)++) dfs(i, i);
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (n); (j)++)
      for (int(k) = (0); (k) < (((int)(adj[i]).size())); (k)++)
        if (chega[adj[i][k]][j]) {
          st[i][j][0] = adj[i][k];
          break;
        }
  for (int(i) = (0); (i) < (n); (i)++) st[i][i][0] = i;
  for (int(k) = (1); (k) < (13 + 1); (k)++)
    for (int(i) = (0); (i) < (n); (i)++)
      for (int(j) = (0); (j) < (n); (j)++)
        if (st[i][j][k - 1] != -1) st[i][j][k] = st[st[i][j][k - 1]][j][k - 1];
  for (int(i) = (0); (i) < (q); (i)++) {
    int u, v, k;
    scanf("%d%d%d", &u, &v, &k);
    u--, v--;
    if (st[u][v][0] == -1 || st[u][v][13] != v)
      puts("-1");
    else {
      int ans = u, tans = u;
      k--;
      for (int(j) = (0); (j) < (13); (j)++)
        if (k & (1 << j)) ans = st[ans][v][j];
      k--;
      for (int(j) = (0); (j) < (13); (j)++)
        if (k & (1 << j)) tans = st[tans][v][j];
      if (tans != ans || k < 0)
        printf("%d\n", ans + 1);
      else
        puts("-1");
    }
  }
}
