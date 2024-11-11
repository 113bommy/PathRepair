#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int N = 1e5 + 11;
vi a(N);
vi tree(4 * N), last(4 * N);
int n;
void build(int v, int l, int r, int pos, int val) {
  if (l == r) {
    tree[v] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    build(v << 1, l, mid, pos, val);
  else
    build(v << 1 | 1, mid + 1, r, pos, val);
  tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
}
int find_e(int v, int l, int r, int val) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (tree[v << 1] < val) return find_e(v << 1, l, mid, val);
  return find_e(v << 1 | 1, mid + 1, r, val);
}
void solve() {
  cin >> n;
  unordered_map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    if (last[x] + 1 < i) {
      mp[find_e(1, 1, N, last[x] + 1)]++;
    }
    build(1, 1, N, x, i);
    last[x] = i;
  }
  for (int i = 1; i < N; i++) {
    if (last[i] and last[i] != n) {
      mp[find_e(1, 1, N, last[i] + 1)]++;
    }
  }
  mp[find_e(1, 1, N, 1)]++;
  for (int i = 1;; i++) {
    if (!mp[i]) {
      cout << i << '\n';
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int t = 1;
  while (t--) solve();
}
