#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
vector<int> edge[maxn];
void marry(int a, int b) { edge[a].push_back(b); }
int in[maxn], out[maxn];
void dfs(int node, int pre, int& now) {
  in[node] = ++now;
  int len2 = edge[node].size();
  for (int i = 0; i < len2; ++i) {
    if (edge[node][i] == pre) continue;
    dfs(edge[node][i], node, now);
  }
  out[node] = now;
}
vector<int> ask[maxn];
void marry_ask(int a, int b) { ask[a].push_back(b); }
struct mytree {
  int v;
  int sum;
} tree[maxn << 2];
void build(int node, int l, int r) {
  tree[node].v = tree[node].sum = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(node << 1, l, mid);
  build(node << 1 | 1, mid + 1, r);
}
void push_up(int node, int l, int r) {
  if (tree[node].v)
    tree[node].sum = r - l + 1;
  else
    tree[node].sum = tree[node << 1].sum + tree[node << 1 | 1].sum;
}
void update(int node, int l, int r, int left, int right, int how) {
  if (left <= l && r <= right) {
    tree[node].v += how;
    push_up(node, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  if (left <= mid) update(node << 1, l, mid, left, right, how);
  if (right > mid) update(node << 1 | 1, mid + 1, r, left, right, how);
  push_up(node, l, r);
}
int now;
int ans[maxn];
void solve(int node, int pre) {
  int len1 = ask[node].size();
  for (int i = 0; i < len1; ++i) {
    int who = ask[node][i];
    update(1, 1, now, in[who], out[who], 1);
  }
  ans[node] = tree[1].sum;
  if (ans[node]) ans[node]--;
  int len2 = edge[node].size();
  for (int i = 0; i < len2; ++i) {
    if (edge[node][i] == pre) continue;
    solve(edge[node][i], node);
  }
  for (int i = 0; i < len1; ++i) {
    int who = ask[node][i];
    update(1, 1, now, in[who], out[who], -1);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a, b;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &a, &b);
    marry(a, b);
    marry(b, a);
  }
  now = 0;
  dfs(1, 1, now);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a, &b);
    marry_ask(a, b);
    marry_ask(b, a);
    marry_ask(a, a);
    marry_ask(b, b);
  }
  build(1, 1, n);
  solve(1, 1);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}
