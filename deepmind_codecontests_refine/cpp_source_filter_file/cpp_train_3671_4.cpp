#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int T, n, k;
int inq[N], lf[N], sz[N];
vector<int> nex[N];
queue<int> q;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) {
      inq[i] = lf[i] = sz[i] = 0;
      nex[i].clear();
    }
    for (int i = 1; i <= n - 1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      nex[u].push_back(v);
      nex[v].push_back(u);
    }
    if (1 == k) {
      printf("%d\n", n - 1);
      continue;
    }
    for (int i = 1; i <= n; i++) {
      sz[i] = nex[i].size();
      if (1 == sz[i]) lf[nex[i][0]] += 1;
    }
    for (int i = 1; i <= n; i++) {
      if (sz[i] < k) continue;
      q.push(i);
      inq[i] = 1;
    }
    int res = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      inq[u] = 0;
      res += 1;
      lf[u] -= k;
      sz[u] -= k;
      if (lf[u] >= k) {
        q.push(u);
        inq[u] = 1;
      }
      if (1 == sz[u]) {
        sz[u] = 0;
        for (int i = 0; i < nex[u].size(); i++) {
          int v = nex[u][i];
          if (0 == sz[v]) continue;
          lf[v] += 1;
          if (lf[v] >= k && !inq[v]) {
            q.push(v);
            inq[v] = 1;
          }
        }
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
