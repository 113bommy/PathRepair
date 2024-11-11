#include <bits/stdc++.h>
using namespace std;
char sss[2000005];
int n, m, k, ans, he, ta, tim, sum;
int edgenum, vet[2000005], nex[2000005], head[2000005], q[2000005],
    flag[2000005];
vector<int> EV[1000005];
void addedge(int u, int v) {
  edgenum++;
  vet[edgenum] = v;
  nex[edgenum] = head[u];
  head[u] = edgenum;
}
void dfs(int t) {
  if (t > n) {
    for (int i = 1; i <= m; i++) printf("%c", sss[i]);
    printf("\n");
    sum++;
    if (sum == ans) exit(0);
    return;
  }
  for (int i = 0; i < EV[t].size(); i++) {
    sss[EV[t][i]] = '1';
    dfs(t + 1);
    sss[EV[t][i]] = '0';
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    addedge(x, y);
    addedge(y, x);
  }
  he = ta = 1, q[1] = 1, flag[1] = 1, tim = 1;
  while (he <= ta) {
    tim++;
    int h = he, t = ta;
    he = t + 1;
    for (int i = h; i <= t; i++)
      for (int e = head[q[i]]; e != 0; e = nex[e]) {
        int v = vet[e];
        if (flag[v] == 0) {
          ta++, q[ta] = v;
          flag[v] = tim;
          EV[v].push_back((e + 1) / 2);
        } else if (flag[v] == tim)
          EV[v].push_back((e + 1) / 2);
      }
  }
  ans = 1;
  for (int i = 2; i <= n; i++) {
    ans = ans * EV[i].size();
    if (ans > k) {
      ans = k;
      break;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++) sss[i] = '0';
  dfs(2);
  return 0;
}
