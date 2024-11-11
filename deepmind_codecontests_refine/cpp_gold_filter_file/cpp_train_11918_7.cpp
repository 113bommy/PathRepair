#include <bits/stdc++.h>
using namespace std;
long long d[1234567], h[1234567];
long long gn[1234567];
struct pos {
  long long lmax, rmax, ans;
  pos() { lmax = rmax = ans = -1000000000000000; }
  pos(int i) {
    ans = -1000000000000000;
    rmax = 2 * h[i] + gn[i];
    lmax = 2 * h[i] - gn[i];
  }
  pos(const pos& a, const pos& b) {
    lmax = max(a.lmax, b.lmax);
    rmax = max(a.rmax, b.rmax);
    ans = max(max(a.ans, b.ans), a.lmax + b.rmax);
  }
};
pos tree[3 * 1234567];
void build(int n, int l, int r) {
  if (l > r) return;
  if (l == r) {
    tree[n] = pos(l);
    return;
  }
  build(2 * n, l, (l + r) / 2);
  build(2 * n + 1, (l + r) / 2 + 1, r);
  tree[n] = pos(tree[2 * n], tree[2 * n + 1]);
}
pos get(int n, int l, int r, int i, int j) {
  if (i > r || j < l || i > j || l > r) return pos();
  if (l >= i && r <= j) return tree[n];
  pos v1 = get(2 * n, l, (l + r) / 2, i, j);
  pos v2 = get(2 * n + 1, (l + r) / 2 + 1, r, i, j);
  return pos(v1, v2);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  int a, b;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    d[n + i] = d[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    h[n + i] = h[i];
  }
  gn[0] = 0;
  for (int i = 1; i < 2 * n; i++) {
    gn[i] = gn[i - 1] + d[i - 1];
  }
  build(1, 0, 2 * n - 1);
  while (m--) {
    cin >> a >> b;
    a--;
    b--;
    pos ans;
    if (a <= b)
      ans = get(1, 0, 2 * n - 1, b + 1, a + n - 1);
    else
      ans = get(1, 0, 2 * n - 1, b + 1, a - 1);
    cout << ans.ans << "\n";
  }
}
