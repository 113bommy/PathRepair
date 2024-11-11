#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N], pos[N];
vector<int> adj[N];
struct node {
  int sum = 0;
  node *left, *right;
  node(int sum, node *left, node *right) : sum(sum), left(left), right(right) {}
  node(int sum = 0) : sum(sum), left(this), right(this) {}
};
node *update(node *cur, int v, int d, int l = 0, int r = n - 1) {
  if (v < l || v > r) return cur;
  if (l == r) return new node(d);
  int mid = l + ((r - l) >> 1);
  node *left = update(cur->left, v, d, l, mid);
  node *right = update(cur->right, v, d, mid + 1, r);
  return new node(left->sum + right->sum, left, right);
}
node *roots[N];
int kth(node *cur, int k, int l = 0, int r = n - 1) {
  if (k >= cur->sum) return n;
  if (l == r) return l;
  int mid = l + ((r - l) >> 1);
  if (k < cur->left->sum) return kth(cur->left, k, l, mid);
  return kth(cur->right, k - cur->left->sum, mid + 1, r);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    pos[i] = adj[arr[i]].size();
    adj[arr[i]].push_back(i);
  }
  roots[n] = new node;
  for (int i = n - 1; i >= 0; i--) {
    int nxt = pos[i] == adj[arr[i]].size() - 1 ? -1 : adj[arr[i]][pos[i] + 1];
    if (~nxt)
      roots[i] = update(update(roots[i + 1], nxt, 0), i, 1);
    else
      roots[i] = update(roots[i + 1], i, 1);
  }
  for (int i = 1; i <= n; i++) {
    int l = 0, cnt = 0;
    while (l < n) l = kth(roots[l], i), cnt++;
    printf("%d ", cnt);
  }
}
