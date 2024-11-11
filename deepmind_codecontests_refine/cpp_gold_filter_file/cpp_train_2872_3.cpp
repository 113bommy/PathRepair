#include <bits/stdc++.h>
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const int MAXN = 1e6 + 5;
const double eps = 1e-9;
using namespace std;
vector<pair<int, int> > adj[MAXN];
int tree[5][MAXN], vis[MAXN];
long long dp[MAXN];
int n, cur;
void build(int id, int l, int r, int k) {
  tree[id][k] = cur++;
  if (l == r) {
    if (id == 2)
      adj[tree[id][k]].push_back({l, 0});
    else if (id == 3)
      adj[l].push_back({tree[id][k], 0});
    return;
  }
  int m = (l + r) >> 1;
  build(id, l, m, k << 1);
  build(id, m + 1, r, k << 1 | 1);
  if (id == 2)
    adj[tree[id][k]].push_back({tree[id][k << 1], 0}),
        adj[tree[id][k]].push_back({tree[id][k << 1 | 1], 0});
  else if (id == 3)
    adj[tree[id][k << 1]].push_back({tree[id][k], 0}),
        adj[tree[id][k << 1 | 1]].push_back({tree[id][k], 0});
}
void upd(int v, int w, int a, int b, int id, int l, int r, int k) {
  if (r < a || b < l) return;
  if (a <= l && r <= b) {
    if (id == 2)
      adj[v].push_back({tree[id][k], w});
    else
      adj[tree[id][k]].push_back({v, w});
    return;
  }
  int m = (l + r) >> 1;
  upd(v, w, a, b, id, l, m, k << 1);
  upd(v, w, a, b, id, m + 1, r, k << 1 | 1);
}
int main() {
  fill(dp, dp + MAXN, INF);
  int q, second;
  scanf("%d", &n), scanf("%d", &q), scanf("%d", &second);
  second--;
  cur = n;
  build(2, 0, n - 1, 1);
  build(3, 0, n - 1, 1);
  for (int i = 0; i < q; i++) {
    int t, v, u, l, r, w;
    scanf("%d", &t), scanf("%d", &v);
    v--;
    if (t == 1) {
      scanf("%d", &u), scanf("%d", &w);
      u--;
      adj[v].push_back({u, w});
    } else {
      scanf("%d", &l), scanf("%d", &r), scanf("%d", &w);
      l--, r--;
      upd(v, w, l, r, t, 0, n - 1, 1);
    }
  }
  dp[second] = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      pq;
  pq.push({dp[second], second});
  while (!pq.empty()) {
    pair<int, int> u = pq.top();
    pq.pop();
    if (vis[u.second]) continue;
    vis[u.second] = true;
    for (pair<int, int> nx : adj[u.second]) {
      if (dp[nx.first] > dp[u.second] + nx.second) {
        dp[nx.first] = dp[u.second] + nx.second;
        pq.push({dp[nx.first], nx.first});
      }
    }
  }
  for (int i = 0; i < n; i++)
    if (dp[i] == INF)
      printf("-1 ");
    else
      printf("%I64d ", dp[i]);
  printf("\n");
  return 0;
}
