#include <bits/stdc++.h>
using namespace std;
vector<int> segtr[800000];
int A[200005];
void build(int node, int l, int r) {
  if (l == r) {
    segtr[node].push_back(A[l]);
    return;
  }
  build(2 * node, l, (l + r) / 2);
  build(2 * node + 1, (l + r) / 2 + 1, r);
  int i, j;
  i = j = 0;
  while (i < (int)segtr[2 * node].size() && j < (int)segtr[2 * node + 1].size())
    if (segtr[2 * node][i] < segtr[2 * node + 1][j])
      segtr[node].push_back(segtr[2 * node][i++]);
    else
      segtr[node].push_back(segtr[2 * node + 1][j++]);
  while (i < (int)segtr[2 * node].size())
    segtr[node].push_back(segtr[2 * node][i++]);
  while (j < (int)segtr[2 * node + 1].size())
    segtr[node].push_back(segtr[2 * node + 1][j++]);
}
int query(int node, int l, int r, int ql, int qr, int y1, int y2) {
  if (r < ql || l > qr || qr < ql) return 0;
  if (l >= ql && r <= qr)
    return upper_bound((segtr[node]).begin(), (segtr[node]).end(), y2) -
           lower_bound((segtr[node]).begin(), (segtr[node]).end(), y1);
  int lchild = query(2 * node, l, (l + r) / 2, ql, qr, y1, y2);
  int rchild = query(2 * node + 1, (l + r) / 2 + 1, r, ql, qr, y1, y2);
  return lchild + rchild;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q, i, l, d, r, u;
  long long res, tmp;
  cin >> n >> q;
  for (i = 1; i <= n; i++) cin >> A[i];
  build(1, 1, n);
  while (q--) {
    cin >> l >> d >> r >> u;
    res = 1LL * (d - 1) * (d - 2) / 2 + 1LL * (n - u) * (n - u - 1) / 2 +
          1LL * (l - 1) * (l - 2) / 2 + 1LL * (n - r) * (n - r - 1) / 2;
    tmp = query(1, 1, n, 1, l - 1, 1, d - 1);
    res -= tmp * (tmp - 1) / 2;
    tmp = query(1, 1, n, r + 1, n, 1, d - 1);
    res -= tmp * (tmp - 1) / 2;
    tmp = query(1, 1, n, 1, l - 1, u + 1, n);
    res -= tmp * (tmp - 1) / 2;
    tmp = query(1, 1, n, r + 1, n, u + 1, n);
    res -= tmp * (tmp - 1) / 2;
    res = 1LL * n * (n - 1) / 2 - res;
    cout << res << '\n';
  }
  return 0;
}
