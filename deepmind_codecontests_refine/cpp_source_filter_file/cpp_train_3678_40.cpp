#include <bits/stdc++.h>
using namespace std;
int com[100009], vis[100009], sz;
vector<vector<int> > adj_lis;
void dfs(int u) {
  sz++;
  vis[u] = 1;
  for (vector<int>::iterator it = (adj_lis[u]).begin();
       it != (adj_lis[u]).end(); it++) {
    if (vis[*it] == -1) dfs(*it);
  }
}
int main() {
  int n, m, k;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  adj_lis.resize(n + 1);
  for (int i = int(0); i <= int(m - 1); i++) {
    int p, q;
    scanf("%d", &p);
    scanf("%d", &q);
    adj_lis[p].push_back(q);
    adj_lis[q].push_back(p);
  }
  int co = 0;
  memset(vis, -1, sizeof(vis));
  for (int i = int(1); i <= int(n); i++) {
    if (vis[i] == -1) {
      sz = 0;
      dfs(i);
      com[co] = sz;
      co++;
    }
  }
  if (co == 1) {
    printf("1\n");
    return 0;
  }
  long long int ans = 1;
  for (int i = int(0); i <= int(co - 1); i++) ans = (ans * com[i]) % k;
  for (int i = int(0); i <= int(co - 3); i++) ans = (ans * n) % k;
  printf("%lld\n", ans);
  return 0;
}
