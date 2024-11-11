#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
vector<int> adj[N];
int x[N], y[N], w[N];
long long sp[N][N];
const long long inf = 1e8;
void getSp(int root, int n) {
  for (int i = n; i; --i) {
    sp[root][i] = inf;
  }
  sp[root][root] = 0LL;
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      pq;
  pq.push({0LL, root});
  while (!pq.empty()) {
    long long dist = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (sp[root][node] != dist) {
      continue;
    }
    for (int e : adj[node]) {
      int nnode = x[e] ^ y[e] ^ node;
      long long ndist = dist + w[e];
      if (sp[root][nnode] > ndist) {
        sp[root][nnode] = ndist;
        pq.push({ndist, nnode});
      }
    }
  }
}
int a[N], b[N];
void solve() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d ", &x[i], &y[i], &w[i]);
    adj[x[i]].push_back(i);
    adj[y[i]].push_back(i);
  }
  for (int i = n; i; --i) {
    getSp(i, n);
  }
  long long ret = 0;
  for (int i = 0; i < k; ++i) {
    scanf("%d %d ", &a[i], &b[i]);
    ret += sp[a[i]][b[i]];
  }
  for (int i = 0; i < m; ++i) {
    long long tmp = 0;
    int u = x[i], v = y[i];
    for (int j = 0; j < k; ++j) {
      int q = a[j], w = b[j];
      tmp += min(sp[q][w], min(sp[q][u] + sp[v][w], sp[q][v] + sp[u][w]));
    }
    ret = min(ret, tmp);
  }
  printf("%lld\n", ret);
}
int main() {
  solve();
  return 0;
}
