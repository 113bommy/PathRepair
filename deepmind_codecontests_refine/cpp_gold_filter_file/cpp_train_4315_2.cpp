#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, nxt, w;
} e[400001];
int edge_num = -1;
int head[200001];
void add(int u, int v) {
  e[++edge_num].nxt = head[u];
  e[edge_num].to = v;
  head[u] = edge_num;
}
void add_edge(int u, int v) {
  add(u, v);
  add(v, u);
}
struct node {
  int l, r;
} q[200001];
int in[200001];
void dfs(int u) {
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    head[u] = i;
    if (e[i].w == 0) {
      e[i].w = 1, e[i ^ 1].w = 2;
      dfs(e[i].to);
    }
  }
}
int main() {
  memset(head, -1, sizeof(head));
  int n;
  scanf("%d", &n);
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].r++;
    v.push_back(q[i].l);
    v.push_back(q[i].r);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= n; i++) {
    q[i].l = lower_bound(v.begin(), v.end(), q[i].l) - v.begin() + 1;
    q[i].r = lower_bound(v.begin(), v.end(), q[i].r) - v.begin() + 1;
    add_edge(q[i].l, q[i].r);
    in[q[i].l]++;
    in[q[i].r]++;
  }
  vector<int> v1;
  for (int i = 1; i <= v.size(); i++)
    if (in[i] % 2 == 1) v1.push_back(i);
  for (int i = 0; i < v1.size(); i += 2) add_edge(v1[i], v1[i + 1]);
  for (int i = 1; i <= v.size(); i++) dfs(i);
  for (int i = 0; i < 2 * n; i++) {
    if (e[i].w == 1) printf("%d ", i % 2);
  }
  return 0;
}
