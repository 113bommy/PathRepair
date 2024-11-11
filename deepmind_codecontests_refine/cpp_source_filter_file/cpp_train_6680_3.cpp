#include <bits/stdc++.h>
using namespace std;
int n;
const int shift = 2e6 + 5, N = 4e6 + 10;
vector<vector<int>> v(N);
int tree[4 * N], lz[4 * N];
void upd(int x, int l, int r, int ll, int rr, int val) {
  if (ll <= l and r <= rr) {
    tree[x] += val;
    lz[x] += val;
    return;
  }
  int m = (l + r) / 2;
  if (lz[x]) {
    tree[2 * x] += lz[x];
    tree[2 * x + 1] += lz[x];
    lz[2 * x] += lz[x];
    lz[2 * x + 1] += lz[x];
    lz[x] = 0;
  }
  if (ll <= m) upd(2 * x, l, m, ll, rr, val);
  if (m < rr) upd(2 * x + 1, m + 1, r, ll, rr, val);
  tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}
int r;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> r;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    int t = x;
    x = x - y;
    y = t + y;
    v[x + shift].push_back(y + shift);
  }
  for (int i = 0; i <= r; ++i) {
    for (int e : v[i]) upd(1, 0, N - 1, max(0, e - r), min((int)2e6, e + r), 1);
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, tree[1]);
    if (i - r >= 0) {
      for (int e : v[i - r])
        upd(1, 0, N - 1, max(0, e - r), min(N - 1, e + r), -1);
    }
    if (i + r + 1 < N) {
      for (int e : v[i + r + 1])
        upd(1, 0, N - 1, max(0, e - r), min(N - 1, e + r), 1);
    }
  }
  cout << ans << '\n';
}
