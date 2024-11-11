#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 16) + 10;
int n, u, v, d[maxn], s[maxn];
queue<int> q;
vector<pair<int, int> > G;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &d[i], &s[i]);
  for (int i = 0; i < n; i++)
    if (d[i] == 1) q.push(i);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    if (!d[u]) continue;
    v = s[u];
    G.push_back(pair<int, int>(u, v));
    s[v] ^= s[u];
    if (--d[v] == 1) q.push(v);
  }
  printf("%d\n", G.size());
  for (int i = 0; i < G.size(); i++) printf("%d %d\n", G[i].first, G[i].second);
  return 0;
}
