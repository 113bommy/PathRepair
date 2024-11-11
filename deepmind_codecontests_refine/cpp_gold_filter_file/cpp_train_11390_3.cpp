#include <bits/stdc++.h>
using namespace std;
vector<int> adj[500010];
pair<int, int> p[500010];
int cnt = 0, parent[500010];
int tree[8 * 500010] = {};
void update0(int node, int start, int end, int idx) {
  if (start != end && tree[node]) {
    tree[2 * node] = 1;
    tree[2 * node + 1] = 1;
  }
  if (start == end)
    tree[node] = 0;
  else {
    int mid = (start + end) >> 1;
    if (idx <= mid)
      update0(2 * node, start, mid, idx);
    else
      update0(2 * node + 1, mid + 1, end, idx);
    tree[node] = tree[2 * node] * tree[2 * node + 1];
  }
}
void update1(int node, int start, int end, int l, int r) {
  if (start != end && tree[node]) {
    tree[2 * node] = 1;
    tree[2 * node + 1] = 1;
  }
  if (start >= l && end <= r) {
    tree[node] = 1;
    return;
  }
  int mid = (start + end) >> 1;
  if (mid >= r)
    update1(2 * node, start, mid, l, r);
  else if (mid < l)
    update1(2 * node + 1, mid + 1, end, l, r);
  else {
    update1(2 * node, start, mid, l, r);
    update1(2 * node + 1, mid + 1, end, l, r);
  }
  tree[node] = tree[2 * node] * tree[2 * node + 1];
  return;
}
int query(int node, int start, int end, int l, int r) {
  if (start != end && tree[node]) {
    tree[2 * node] = 1;
    tree[2 * node + 1] = 1;
  }
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) >> 1;
  if (mid >= r) return query(2 * node, start, mid, l, r);
  if (mid < l) return query(2 * node + 1, mid + 1, end, l, r);
  int P1 = query(2 * node, start, mid, l, r);
  int P2 = query(2 * node + 1, mid + 1, end, l, r);
  return P1 * P2;
}
void dfs(int cur, int prev = -1) {
  parent[cur] = prev;
  p[cur].first = cnt++;
  for (int u : adj[cur]) {
    if (u == prev) continue;
    dfs(u, cur);
  }
  p[cur].second = cnt++;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int c, v;
    scanf("%d %d", &c, &v);
    if (c == 1) {
      if (query(1, 0, cnt - 1, p[v].first, p[v].second) == 0 && v != 1) {
        update0(1, 0, cnt - 1, p[parent[v]].first);
        update0(1, 0, cnt - 1, p[parent[v]].second);
      }
      update1(1, 0, cnt - 1, p[v].first, p[v].second);
    } else if (c == 2) {
      update0(1, 0, cnt - 1, p[v].first);
      update0(1, 0, cnt - 1, p[v].second);
    } else
      printf("%d\n", query(1, 0, cnt - 1, p[v].first, p[v].second));
  }
  return 0;
}
