#include <bits/stdc++.h>
using namespace std;
pair<int, int> fence[100010];
inline bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first > b.first;
}
struct TreeNode {
  int left, right, left_child, right_child, max_ones, pre_ones, suf_ones;
  int len() { return right - left + 1; }
} tree[2000000];
int node;
int root[100010];
void push_up(int u) {
  int l = tree[u].left_child, r = tree[u].right_child;
  tree[u].pre_ones = tree[l].pre_ones +
                     (tree[l].pre_ones == tree[l].len() ? tree[r].pre_ones : 0);
  tree[u].suf_ones = tree[r].suf_ones +
                     (tree[r].suf_ones == tree[r].len() ? tree[l].suf_ones : 0);
  tree[u].max_ones = max(tree[l].suf_ones + tree[r].pre_ones,
                         max(tree[l].max_ones, tree[r].max_ones));
}
TreeNode merge_node(TreeNode l, TreeNode r) {
  TreeNode u;
  u.left = l.left;
  u.right = r.right;
  u.pre_ones = l.pre_ones + (l.pre_ones == l.len() ? r.pre_ones : 0);
  u.suf_ones = r.suf_ones + (r.suf_ones == r.len() ? l.suf_ones : 0);
  u.max_ones = max(l.suf_ones + r.pre_ones, max(l.max_ones, r.max_ones));
  return u;
}
void build_tree(int& u, int l, int r) {
  u = node++;
  tree[u].left = l;
  tree[u].right = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build_tree(tree[u].left_child, l, mid);
  build_tree(tree[u].right_child, mid + 1, r);
}
void insert_tree(int& u, int v, int x) {
  u = node++;
  tree[u] = tree[v];
  if (tree[u].left == x && tree[u].right == x) {
    tree[u].max_ones = tree[u].pre_ones = tree[u].suf_ones = 1;
    return;
  }
  int mid = (tree[u].left + tree[u].right) >> 1;
  if (x <= mid)
    insert_tree(tree[u].left_child, tree[u].left_child, x);
  else
    insert_tree(tree[u].right_child, tree[u].right_child, x);
  push_up(u);
}
TreeNode query_tree(int u, int l, int r) {
  if (tree[u].left <= l && tree[u].right >= r) return tree[u];
  int mid = (tree[u].left + tree[u].right) >> 1;
  if (mid >= r) return query_tree(tree[u].left_child, l, r);
  if (mid + 1 <= l) return query_tree(tree[u].right_child, l, r);
  TreeNode left = query_tree(tree[u].left_child, l, r);
  TreeNode right = query_tree(tree[u].right_child, l, r);
  return merge_node(left, right);
}
int main(int argc, char* argv[]) {
  int n, m;
  int l, r, w;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &fence[i].first), fence[i].second = i;
  sort(fence + 1, fence + n + 1, cmp);
  build_tree(root[0], 1, n);
  for (int i = 1; i <= n; i++)
    insert_tree(root[i], root[i - 1], fence[i].second);
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d%d", &l, &r, &w);
    int left = 1, right = n;
    int ans = 0;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (query_tree(root[mid], l, r).max_ones >= w)
        right = mid - 1, ans = mid;
      else
        left = mid + 1;
    }
    printf("%d\n", fence[ans].first);
  }
  return 0;
}
