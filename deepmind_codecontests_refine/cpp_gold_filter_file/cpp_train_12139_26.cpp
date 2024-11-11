#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5 + 9;
int n, k, a[inf], q, pre[inf];
queue<int> p[inf];
vector<int> tree[inf << 2];
void merge(int node, int l, int r) {
  int i = 0, j = 0;
  while (i < tree[node + node].size() && j < tree[node + node + 1].size())
    if (tree[node + node][i] < tree[node + node + 1][j])
      tree[node].push_back(tree[node + node][i++]);
    else
      tree[node].push_back(tree[node + node + 1][j++]);
  while (i < tree[node + node].size())
    tree[node].push_back(tree[node + node][i++]);
  while (j < tree[node + node + 1].size())
    tree[node].push_back(tree[node + node + 1][j++]);
}
void build(int node, int l, int r) {
  if (l == r) return void(tree[node].push_back(pre[l]));
  build(node + node, l, (l + r) / 2);
  build(node + node + 1, (l + r) / 2 + 1, r);
  merge(node, l, r);
}
int query(int node, int l, int r, int x, int y) {
  if (l > r || r < x || l > y) return 0;
  if (l >= x && r <= y)
    return upper_bound(tree[node].begin(), tree[node].end(), x - 1) -
           tree[node].begin();
  return query(node + node, l, (l + r) / 2, x, y) +
         query(node + node + 1, (l + r) / 2 + 1, r, x, y);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (p[a[i]].size() == k) pre[i] = p[a[i]].front(), p[a[i]].pop();
    p[a[i]].push(i);
  }
  build(1, 1, n);
  int last = 0;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l = (l + last) % n + 1;
    r = (r + last) % n + 1;
    if (l > r) swap(l, r);
    last = query(1, 1, n, l, r);
    cout << last << endl;
  }
}
