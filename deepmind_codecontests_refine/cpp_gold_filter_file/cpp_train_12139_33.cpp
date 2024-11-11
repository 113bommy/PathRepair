#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
vector<int> adj[maxn], tree[maxn];
int arr[maxn], ind[maxn], k;
void build(int node, int l, int r) {
  if (l == r) {
    tree[node].push_back(ind[l]);
    tree[node].push_back(mod);
    return;
  }
  int mid = (l + r) / 2;
  build(2 * node, l, mid);
  build(2 * node + 1, mid + 1, r);
  int idx1 = 0, idx2 = 0, size1 = int(tree[2 * node].size()),
      size2 = int(tree[2 * node + 1].size());
  while (idx1 < size1 && idx2 < size2) {
    if (tree[2 * node][idx1] < tree[2 * node + 1][idx2]) {
      if (tree[2 * node][idx1] != mod)
        tree[node].push_back(tree[2 * node][idx1]);
      idx1++;
    } else {
      if (tree[2 * node + 1][idx2] != mod)
        tree[node].push_back(tree[2 * node + 1][idx2]);
      idx2++;
    }
  }
  while (idx1 < size1) {
    if (tree[2 * node][idx1] != mod) tree[node].push_back(tree[2 * node][idx1]);
    idx1++;
  }
  while (idx2 < size2) {
    if (tree[2 * node + 1][idx2] != mod)
      tree[node].push_back(tree[2 * node + 1][idx2]);
    idx2++;
  }
  tree[node].push_back(mod);
  return;
}
int query(int node, int l, int r, int s, int e) {
  if (s <= l && r <= e) {
    return int(tree[node].size()) - 1 -
           (upper_bound(tree[node].begin(), tree[node].end(), e) -
            tree[node].begin());
  }
  if (e < l || r < s) return 0;
  int mid = (l + r) / 2;
  int p1 = query(2 * node, l, mid, s, e);
  int p2 = query(2 * node + 1, mid + 1, r, s, e);
  return p1 + p2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q, i, j, ans = 0, l, r;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
    adj[arr[i]].push_back(i);
    ind[i] = n + 1;
  }
  for (i = 1; i < maxn; i++) {
    if (int(adj[i].size()) > k) {
      for (j = k; j < int(adj[i].size()); j++) {
        int x = adj[i][j];
        int mark = adj[i][j - k];
        ind[mark] = x;
      }
    }
  }
  build(1, 1, n);
  cin >> q;
  while (q--) {
    cin >> l >> r;
    l = (l + ans) % n + 1;
    r = (r + ans) % n + 1;
    if (l > r) swap(l, r);
    ans = query(1, 1, n, l, r);
    cout << ans << endl;
  }
  return 0;
}
