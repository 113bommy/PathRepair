#include <bits/stdc++.h>
using namespace std;
const int N = 100007;
struct Node {
  int i = -1, u = 0;
};
int ar[N], br[N];
Node tree[4 * N];
int x;
void update(int v, int l, int r, int tl, int tr, int q) {
  if (l >= tl && tr >= r) {
    tree[v].i = x;
    tree[v].u = q;
    x = x + (r - l + 1);
  } else if (l > r || l > tr || r < tl)
    return;
  else {
    int m = (r + l) / 2;
    update(2 * v + 1, l, m, tl, tr, q);
    update(2 * v + 2, m + 1, r, tl, tr, q);
  }
}
int query(int v, int l, int r, int tar, Node top) {
  if (l == r) {
    if (top.i == -1 && tree[v].i == -1)
      return br[l];
    else {
      return (top.u > tree[v].u) ? (ar[top.i]) : (ar[tree[v].i]);
    }
  } else {
    int m = (r + l) / 2;
    Node ret;
    ret.u = max(tree[v].u, top.u);
    ret.i = (top.u > tree[v].u) ? (top.i) : (tree[v].i);
    if (tar <= m)
      return query(2 * v + 1, l, m, tar, ret);
    else {
      if (ret.i != -1) {
        ret.i += ((m - l + 1));
      }
      return query(2 * v + 2, m + 1, r, tar, ret);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> ar[i];
  for (int i = 0; i < n; i++) cin >> br[i];
  Node temp;
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q >> x;
    if (q == 1) {
      int y, k;
      cin >> y >> k;
      x--;
      update(0, 0, n - 1, y - 1, y + k - 2, i);
    } else {
      cout << query(0, 0, n - 1, x - 1, temp) << '\n';
    }
  }
}
