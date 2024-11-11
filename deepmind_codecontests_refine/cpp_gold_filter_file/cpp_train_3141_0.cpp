#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
int dist[N], cur_deg[N];
vector<int> adj[N];
void dfs_dist(int cur, int parent) {
  for (int s : adj[cur]) {
    if (s == parent) continue;
    dist[s] = dist[cur] + 1;
    dfs_dist(s, cur);
  }
}
void check_root(int cand) {
  fill_n(dist, n, 0);
  fill_n(cur_deg, n + 1, 0);
  dfs_dist(cand, -1);
  for (int i = 0; i < n; i++) {
    int d = dist[i];
    if (cur_deg[d] && cur_deg[d] != adj[i].size()) return;
    cur_deg[d] = adj[i].size();
  }
  cout << cand + 1 << endl;
  exit(0);
}
int main() {
  int v, u;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> v >> u;
    v--, u--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  vector<int> degs(n);
  queue<int> leaf_queue;
  for (int i = 0; i < n; i++) {
    degs[i] = adj[i].size();
    if (degs[i] == 1) leaf_queue.push(i);
  }
  vector<int> order;
  while (!leaf_queue.empty()) {
    int v = leaf_queue.front();
    leaf_queue.pop();
    order.push_back(v);
    for (int s : adj[v]) {
      if ((--degs[s]) == 1) leaf_queue.push(s);
    }
  }
  int cand = order.back();
  check_root(cand);
  map<int, int> nxt_cands;
  for (int s : adj[cand]) {
    int cur = s, pnt = cand, depth = 1;
    bool ok = true;
    while (true) {
      if (adj[cur].size() == 1) break;
      if (adj[cur].size() > 2) {
        ok = false;
        break;
      }
      int nxt = adj[cur][0] + adj[cur][1] - pnt;
      ++depth;
      pnt = cur;
      cur = nxt;
    }
    if (ok) nxt_cands[depth] = cur;
  }
  int num_proc = 0;
  for (auto &info : nxt_cands) {
    if (num_proc > 2) continue;
    check_root(info.second);
    num_proc++;
  }
  cout << -1 << endl;
}
