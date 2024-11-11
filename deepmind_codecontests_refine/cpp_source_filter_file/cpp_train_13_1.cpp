#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200000 + 5];
vector<int> E[200000 + 5];
int ind[200000 + 5];
int rk[200000 + 5];
int sg[200000 + 5];
void topo() {
  static bool vis[200000 + 5];
  queue<int> q;
  vector<int> seq;
  for (int i = 1; i <= n; i++)
    if (ind[i] == 0) q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    seq.push_back(x);
    for (int y : E[x]) {
      ind[y]--;
      if (ind[y] == 0) q.push(y);
    }
  }
  for (int i = seq.size() - 1; i >= 0; i--) {
    int x = seq[i];
    for (int y : E[x]) vis[rk[y]] = 1;
    while (vis[rk[x]]) rk[x]++;
    for (int y : E[x]) vis[rk[y]] = 0;
  }
}
int main() {
  int u, v;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    E[u].push_back(v);
    ind[v]++;
  }
  topo();
  for (int i = 1; i <= n; i++) sg[rk[i]] ^= a[i];
  int pos = -1;
  for (int i = 0; i <= n; i++) {
    if (sg[i] != 0) {
      pos = i;
      break;
    }
  }
  if (pos == -1)
    puts("LOSE");
  else {
    puts("WIN");
    for (int i = 1; i <= n; i++) {
      if (rk[i] == pos) {
        if ((sg[rk[i]] ^ a[i]) <= a[i]) {
          a[i] ^= sg[rk[i]];
          sg[rk[i]] = 0;
          for (int y : E[i]) {
            a[y] ^= sg[rk[y]];
            sg[rk[y]] = 0;
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  }
}
