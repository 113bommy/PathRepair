#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long INFL = 9223372036854775807LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;
vector<int> adj[200000 + 5];
bool deleted[200000 + 5];
int tree_size[200000 + 5];
vector<int> cd_children[200000 + 5];
int node_mask[200000 + 5], cum_mask[200000 + 5];
unordered_set<int> all_descendents[200000 + 5];
bool visited[200000 + 5];
int descendent_masks[(1 << ('t' - 'a' + 1)) + 10],
    descendent_masks_by_child[(1 << ('t' - 'a' + 1)) + 10];
long long ans[200000 + 5];
long long pending_cnt[200000 + 5];
int dfs(int cur, int parent) {
  int size = 1;
  for (auto it = adj[cur].begin(); it != adj[cur].end(); it++) {
    if (*it != parent && !deleted[*it]) {
      size += dfs(*it, cur);
    }
  }
  tree_size[cur] = size;
  return size;
}
int find_centroid(int cur, int parent, int n) {
  for (auto it = adj[cur].begin(); it != adj[cur].end(); it++) {
    if (*it != parent && !deleted[*it] && tree_size[*it] >= (n + 1) / 2) {
      return find_centroid(*it, cur, n);
    }
  }
  return cur;
}
int centroid_decomposition(int root, int depth, int n) {
  if (n == 1) {
    return root;
  }
  dfs(root, -1);
  int centroid = find_centroid(root, -1, n);
  deleted[centroid] = true;
  for (auto it = adj[centroid].begin(); it != adj[centroid].end(); it++) {
    if (!deleted[*it]) {
      int c;
      if (tree_size[*it] < tree_size[centroid])
        c = centroid_decomposition(*it, depth + 1, tree_size[*it]);
      else
        c = centroid_decomposition(*it, depth + 1,
                                   tree_size[root] - tree_size[centroid]);
      cd_children[centroid].push_back(c);
    }
  }
  return centroid;
}
void get_all_descendents(int root) {
  all_descendents[root].insert(root);
  for (int c : cd_children[root]) {
    get_all_descendents(c);
    for (int x : all_descendents[c]) all_descendents[root].insert(x);
  }
}
void get_masks(int root, vector<int>& bfs_order, vector<int>& mask_list) {
  queue<int> q;
  q.push(root);
  cum_mask[root] = 0;
  visited[root] = true;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    descendent_masks[cum_mask[top]]++;
    mask_list.push_back(cum_mask[top]);
    bfs_order.push_back(top);
    for (int u : adj[top]) {
      if (not visited[u] and
          all_descendents[root].find(u) != all_descendents[root].end()) {
        visited[u] = true;
        cum_mask[u] = cum_mask[top] ^ node_mask[u];
        q.push(u);
      }
    }
  }
}
void search_path(int root, int u, int target) {
  int u_target = target ^ cum_mask[u] ^ node_mask[root];
  int cnt = descendent_masks[u_target] - descendent_masks_by_child[u_target];
  if (cnt > 0) {
  }
  pending_cnt[u] += cnt;
  if (u_target == cum_mask[root]) {
    pending_cnt[root]++;
  }
}
void solve_cd_tree(int root) {
  vector<int> mask_list, mask_list_by_child;
  vector<int> bfs_order;
  get_masks(root, bfs_order, mask_list);
  pending_cnt[root] += 1;
  for (int c : cd_children[root]) {
    mask_list_by_child.clear();
    for (int u : all_descendents[c]) {
      mask_list_by_child.push_back(cum_mask[u]);
      descendent_masks_by_child[cum_mask[u]]++;
    }
    for (int u : all_descendents[c]) {
      for (int target = 1; target <= (1 << ('t' - 'a')); target <<= 1) {
        search_path(root, u, target);
      }
      search_path(root, u, 0);
    }
    for (int x : mask_list_by_child) descendent_masks_by_child[x] = 0;
  }
  for (int i = (int)(bfs_order).size() - 1; i > 0; i--) {
    int nd = bfs_order[i];
    ans[nd] += pending_cnt[nd];
    for (int u : adj[nd]) {
      pending_cnt[u] += pending_cnt[nd];
    }
  }
  ans[root] += pending_cnt[root] / 2 + 1;
  for (int u : all_descendents[root]) {
    visited[u] = false;
  }
  visited[root] = false;
  for (int i = (int)(bfs_order).size() - 1; i >= 0; i--) {
    pending_cnt[i] = 0;
    for (int u : adj[bfs_order[i]]) {
      pending_cnt[u] = 0;
    }
  }
  for (int x : mask_list) descendent_masks[x] = 0;
  for (int c : cd_children[root]) {
    solve_cd_tree(c);
  }
}
int32_t main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d", &u);
    ;
    scanf("%d", &v);
    ;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  string chars;
  cin >> chars;
  memset(deleted, false, sizeof(deleted));
  ;
  memset(visited, false, sizeof(visited));
  ;
  memset(ans, 0, sizeof(ans));
  ;
  memset(pending_cnt, 0, sizeof(pending_cnt));
  ;
  memset(descendent_masks, 0, sizeof(descendent_masks));
  ;
  memset(descendent_masks_by_child, 0, sizeof(descendent_masks_by_child));
  ;
  int root = centroid_decomposition(0, 0, n);
  for (int i = 0; i < n; i++) {
    node_mask[i] = 1 << (chars[i] - 'a');
  }
  get_all_descendents(root);
  solve_cd_tree(root);
  for (int i = 0; i < n; i++) {
    printf("%I64d ", ans[i]);
  }
  printf("\n");
  return 0;
}
