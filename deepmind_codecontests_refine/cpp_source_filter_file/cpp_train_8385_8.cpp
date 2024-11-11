#include <bits/stdc++.h>
using namespace std;
int a[100001], tree[4 * 100001], treel[4 * 100001], treer[4 * 100001],
    check[4 * 100001];
void build(int l, int r, int node) {
  if (l == r) {
    tree[node] = a[l];
    treel[node] = a[l];
    treer[node] = a[l];
    check[node] = 1;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, 2 * node);
  build(mid + 1, r, 2 * node + 1);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
  treel[node] = treel[2 * node] + treel[2 * node + 1];
  treer[node] = treer[2 * node] + treer[2 * node + 1];
  check[node] = 1;
}
void update(int l, int r, int pos, int node) {
  if (l == r && l == pos) {
    tree[node] = 0;
    treel[node] = 0;
    treer[node] = 0;
    check[node] = 0;
    return;
  }
  int mid = (l + r) / 2;
  if (mid >= pos) {
    update(l, mid, pos, 2 * node);
  } else
    update(mid + 1, r, pos, 2 * node + 1);
  check[node] = 0;
  if (check[2 * node] == 0) {
    treel[node] = treel[2 * node];
  } else
    treel[node] = treel[2 * node] + treel[2 * node + 1];
  if (check[2 * node + 1] == 0) {
    treer[node] = treer[2 * node + 1];
  } else
    treer[node] = treer[2 * node] + treer[2 * node + 1];
  tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  tree[node] = max(tree[node], treer[2 * node] + treel[2 * node + 1]);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    update(1, n, x, 1);
    cout << tree[1] << endl;
  }
  return 0;
}
