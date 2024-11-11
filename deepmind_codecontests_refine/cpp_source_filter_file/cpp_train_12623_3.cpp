#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 12, M = 1 << 16, B = 1 << 8, K = 1 << 22;
int n, m, idx, a[N], c[K], d[K], pos[N], ans[M];
int merge(int x, int y) {
  if (!x || !y) return x + y;
  c[idx] = x;
  d[idx] = y;
  return ++idx;
}
struct Seg {
  vector<int> val;
  vector<vector<int>> id;
  void init(int x) {
    val.resize(x);
    id.resize(x);
    for (int i = 0; i < x; i++) id[i].resize(x - i);
  }
  Seg(int x = -1) {
    if (x != -1) init(1), val[0] = pos[x], id[0][0] = pos[x] + 1;
  }
  int query(int l, int r) const {
    if (r < val.front() || l > val.back()) return 0;
    l = lower_bound(val.begin(), val.end(), l) - val.begin();
    r = upper_bound(val.begin(), val.end(), r) - val.begin() - 1;
    return l > r ? 0 : id[l][r - l];
  }
  Seg modify(const Seg &x, const Seg &y) {
    init(x.val.size() + y.val.size());
    merge(x.val.begin(), x.val.end(), y.val.begin(), y.val.end(), val.begin());
    for (int i = 0; i < int(val.size()); i++)
      for (int j = i; j < int(val.size()); j++)
        id[i][j - i] = merge(x.query(val[i], val[j]), y.query(val[i], val[j]));
    return *this;
  }
} t[N / B];
Seg solve(int l, int r) {
  if (l == r) return Seg(l);
  int mid = (l + r) >> 1;
  return Seg().modify(solve(l, mid), solve(mid + 1, r));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  idx = n--;
  for (int i = 0; i <= n; i++) cin >> a[i], ++a[i];
  for (int i = 0; i <= n; i++) pos[a[i]] = i;
  for (int i = 0; i <= n / B; i++) t[i] = solve(i * B, min(i * B + B - 1, n));
  int l, r;
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    l--;
    r--;
    for (int j = 0; j <= n / B; j++) ans[i] = merge(ans[i], t[j].query(l, r));
  }
  cout << idx << endl;
  for (int i = n + 1; i < idx; i++) cout << c[i] << ' ' << d[i] << '\n';
  for (int i = 0; i < m; i++) cout << ans[i] << ' ';
  return 0;
}
