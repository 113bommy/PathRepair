#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100009];
long long tree[400009];
void build(int node, int l, int r) {
  if (l == r) {
    tree[node] = arr[l] % k;
    return;
  }
  build(node * 2, l, (l + r) / 2);
  build(node * 2 + 1, (l + r) / 2 + 1, r);
  tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % k;
}
long long query(int node, int l, int r, int s, int e) {
  if (l >= s && r <= e) return tree[node];
  if ((l + r) / 2 >= s && (l + r) / 2 + 1 <= e)
    return (query(node * 2, l, (l + r) / 2, s, e) *
            query(node * 2 + 1, (l + r) / 2 + 1, r, s, e)) %
           k;
  else if ((l + r) / 2 >= s)
    return query(node * 2, l, (l + r) / 2, s, e);
  else
    return query(node * 2 + 1, (l + r) / 2 + 1, r, s, e);
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(1, 0, n - 1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int l = i - 1, r = n;
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (query(1, 0, n - 1, i, m) > 0)
        l = m;
      else
        r = m;
    }
    ans += (n - r);
  }
  cout << ans << endl;
}
