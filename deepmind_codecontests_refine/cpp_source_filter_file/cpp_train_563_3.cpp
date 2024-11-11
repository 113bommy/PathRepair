#include <bits/stdc++.h>
using namespace std;
struct node {
  int u, v;
  bool cmp(node a) { return (this->u == a.u && this->v == a.v); }
};
bool cmp(node a, node b) {
  if (a.u != b.u) return a.u < b.u;
  return a.v < b.v;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, p;
  cin >> n >> p;
  int *chosen = new int[n + 1];
  node *adj = new node[n + 1];
  int *cnt = new int[(n << 1) + 1];
  for (int i = 1; i <= n << 1; i++) cnt[i] = 0;
  for (int i = 1; i <= n; i++) chosen[i] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> adj[i].u >> adj[i].v;
    if (adj[i].u > adj[i].v) swap(adj[i].u, adj[i].v);
    chosen[adj[i].u]++;
    chosen[adj[i].v]++;
  }
  for (int i = 1; i <= n; i++) cnt[chosen[i]]++;
  for (int i = (n << 1) - 1; i >= 1; i--) cnt[i] += cnt[i + 1];
  int res = 0;
  for (int i = 1; i <= n; i++)
    if (chosen[i] >= p) {
      res += n - 1;
    } else {
      res += cnt[p - chosen[i]];
      if (chosen[i] << 1 >= p) res--;
    }
  res >>= 1;
  sort(adj + 1, adj + 1 + n, cmp);
  int tmp = 1;
  for (int i = 2; i <= n; i++)
    if (adj[i].cmp(adj[i - 1]))
      tmp++;
    else {
      int val = chosen[adj[i - 1].u] + chosen[adj[i - 1].v];
      if (val >= p && val - tmp < p) res--;
      tmp = 0;
    }
  int val = chosen[adj[n].u] + chosen[adj[n].v];
  if (val >= p && val - tmp < p) res--;
  tmp = 0;
  cout << res;
  delete[] adj;
  delete[] chosen;
  delete[] cnt;
}
