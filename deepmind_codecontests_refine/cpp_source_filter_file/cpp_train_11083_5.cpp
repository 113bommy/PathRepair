#include <bits/stdc++.h>
using namespace std;
int a[112345], l[112345], r[112345], q[112345], sum[112345], tree[4 * 112345];
int maxx = (1ll << 30) - 1;
void build_tree(int node, int s, int e) {
  if (s == e) {
    tree[node] = a[s];
    return;
  }
  int mid = (s + e) / 2;
  int c1 = 2 * node + 1;
  int c2 = c1 + 1;
  build_tree(c1, s, mid);
  build_tree(c2, mid + 1, e);
  tree[node] = (tree[c1] & tree[c2]);
}
int query_tree(int node, int s, int e, int p, int q) {
  if (q < e || p > e) return maxx;
  if (s >= p && e <= q) return tree[node];
  int mid = (s + e) / 2;
  int c1 = 2 * node + 1;
  int c2 = c1 + 1;
  return query_tree(c1, s, mid, p, q) & query_tree(c2, mid + 1, e, p, q);
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> q[i];
    l[i]--;
  }
  for (int bit = 0; bit <= 30; bit++) {
    for (int i = 0; i < n; i++) {
      sum[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      if ((q[i] >> bit) & 1) {
        sum[l[i]]++;
        sum[r[i]]--;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) sum[i] += sum[i - 1];
      if (sum[i] > 0) {
        a[i] |= (1 << bit);
      }
    }
  }
  build_tree(0, 0, n - 1);
  for (int i = 0; i < m; i++) {
    if (query_tree(0, 0, n - 1, l[i], r[i] - 1) != q[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
