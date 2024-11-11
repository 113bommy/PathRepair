#include <bits/stdc++.h>
using namespace std;
int n, m, cc, in[100005], t[100005];
vector<int> g[100005];
priority_queue<int> pq;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[y].push_back(x);
    in[x]++;
  }
  for (int i = 1; i <= n; i++)
    if (in[i] == 0) pq.push(i);
  cc = n;
  while (!pq.empty()) {
    int x = pq.top();
    pq.pop();
    t[x] = cc--;
    for (int i = 0; i < g[x].size(); i++) {
      --in[g[x][i]];
      if (in[g[x][i]] == 0) pq.push(g[x][i]);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", t[i]);
  printf("\n");
  return 0;
}
