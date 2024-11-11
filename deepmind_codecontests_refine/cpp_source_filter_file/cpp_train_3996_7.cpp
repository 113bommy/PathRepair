#include <bits/stdc++.h>
using namespace std;
long long tree[4 * 100100];
long long a[100100];
int n;
void build(int from, int to, int node) {
  if (from == to) {
    tree[node] = a[from];
    return;
  }
  int mid = (from + to) / 2;
  build(from, mid, 2 * node);
  build(mid + 1, to, 2 * node + 1);
  tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
long long val;
void update(int from, int to, int node) {
  if (from == to) {
    tree[node] = val;
    return;
  }
  int mid = (from + to) / 2;
  update(from, mid, 2 * node);
  tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
long long query(int from, int to, int node, int low, int high) {
  if (low > to || from > high) {
    return 0;
  }
  if (from >= low && to <= high) {
    return tree[node];
  }
  int mid = (from + to) / 2;
  return max(query(from, mid, 2 * node, low, high),
             query(mid + 1, high, 2 * node + 1, low, high));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, n - 1, 1);
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    long long w, h;
    cin >> w >> h;
    long long t = query(0, n - 1, 1, 0, w - 1);
    cout << t << endl;
    val = h + t;
    update(0, n - 1, 1);
  }
  return 0;
}
