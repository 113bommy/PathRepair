#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 4e5 + 10;
const int LOG = 19;
const long long NOT_CALC = -1e17;
vector<pair<int, int> > adj[N];
int par[N][LOG];
int h[N];
void dfs(int v, int p = -1) {
  par[v][0] = p;
  if (p + 1) h[v] = h[p] + 1;
  for (int i = 1; i < LOG; i++)
    if (par[v][i - 1] + 1) par[v][i] = par[par[v][i - 1]][i - 1];
  for (auto u : adj[v])
    if (p - u.first) dfs(u.first, v);
}
int LCA(int v, int u) {
  if (h[v] < h[u]) swap(v, u);
  for (int i = LOG - 1; i >= 0; i--)
    if (par[v][i] + 1 and h[par[v][i]] >= h[u]) v = par[v][i];
  if (v == u) return v;
  for (int i = LOG - 1; i >= 0; i--)
    if (par[v][i] - par[u][i]) v = par[v][i], u = par[u][i];
  return par[v][0];
}
int a[N];
void init() {
  memset(par, -1, sizeof par);
  dfs(0);
}
long long ans_without_parent[N];
long long ans_with_parent[N];
void calc_ans_for_nodes_no_parent(int v, int p) {
  ans_without_parent[v] = a[v];
  for (auto u : adj[v])
    if (u.first != p) {
      calc_ans_for_nodes_no_parent(u.first, v);
      ans_without_parent[v] +=
          max(0LL, -2 * u.second + ans_without_parent[u.first]);
    }
}
void calc_ans_for_nodes_with_parent(int v, int p, long long par_edge,
                                    long long par_ans_without_me = 0) {
  ans_with_parent[v] =
      ans_without_parent[v] + max(0LL, -2 * par_edge + par_ans_without_me);
  for (auto u : adj[v])
    if (u.first != p) {
      calc_ans_for_nodes_with_parent(
          u.first, v, u.second,
          ans_with_parent[v] -
              max(0LL, -2 * u.second + ans_without_parent[u.first]));
    }
}
struct QUERY {
  int other, lca, idx;
};
vector<QUERY> query[N];
int cur_child[N];
long long cum_sum[N];
long long cum_ans[N];
long long ans_quyer[M];
void calc_queries(int v, int p, long long prv_sum, long long prv_ans,
                  long long prv_edge) {
  for (QUERY q : query[v]) {
    if (ans_quyer[q.idx] == NOT_CALC) {
      ans_quyer[q.idx] = ans_with_parent[q.lca];
    }
    if (q.lca == v) {
      continue;
    }
    long long sum = prv_sum + a[v] - prv_edge - cum_sum[q.lca];
    ans_quyer[q.idx] += sum;
    ans_quyer[q.idx] -=
        max(0LL, -2 * adj[q.lca][cur_child[q.lca]].second +
                     ans_without_parent[adj[q.lca][cur_child[q.lca]].first]);
    ans_quyer[q.idx] += prv_ans + ans_without_parent[v] - cum_ans[q.lca] - a[v];
  }
  cum_sum[v] = prv_sum - prv_edge + a[v];
  cum_ans[v] = prv_ans + ans_without_parent[v];
  for (auto u : adj[v]) {
    if (u.first != p) {
      cum_ans[v] = prv_ans + ans_without_parent[v] -
                   max(0LL, -2 * u.second + ans_without_parent[u.first]) - a[v];
      calc_queries(u.first, v, cum_sum[v], cum_ans[v], u.second);
    }
    cur_child[v]++;
  }
}
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  init();
  for (int i = 0; i < n - 1; i++) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    x--, y--;
    adj[x].push_back({y, c});
    adj[y].push_back({x, c});
  }
  init();
  for (int i = 0; i < q; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    int lca = LCA(x, y);
    query[x].push_back({y, lca, i});
    query[y].push_back({x, lca, i});
  }
  dfs(0);
  calc_ans_for_nodes_no_parent(0, -1);
  calc_ans_for_nodes_with_parent(0, -1, 0);
  fill(ans_quyer, ans_quyer + q, NOT_CALC);
  calc_queries(0, -1, 0, 0, 0);
  for (int i = 0; i < q; i++) {
    printf("%I64d\n", ans_quyer[i]);
  }
}
