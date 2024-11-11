#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int INF = 0x3f3f3f3f;
int c[N];
vector<int> g[N];
int in[N];
int deg[N];
int topsort(int n, int l) {
  queue<int> q[3];
  int ans = 0;
  int u;
  for (int i = 1; i <= n; i++)
    if (in[i] == 0) q[c[i]].push(i);
  while (!q[0].empty() || !q[1].empty() || !q[2].empty()) {
    while (!q[l].empty()) {
      u = q[l].front();
      q[l].pop();
      ans++;
      for (int v, i = 0; i < g[u].size(); i++) {
        v = g[u][i];
        in[v]--;
        if (in[v] == 0) q[c[v]].push(v);
      }
    }
    l = (l + 1) % 3;
    ans++;
  }
  return ans - 1;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    c[i]--;
  }
  for (int u, k, i = 1; i <= n; i++) {
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &u);
      g[u].push_back(i);
      deg[i]++;
    }
  }
  int ans = INF;
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) in[j] = deg[j];
    ans = min(ans, topsort(n, i));
  }
  printf("%d\n", ans);
  return 0;
}
