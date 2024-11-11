#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int inf = 1e18;
int a[N], arr[N];
int sums[4 * N], sums2[4 * N];
int n, v;
vector<int> tree[4000005];
void build(int x, int lx, int rx) {
  if (lx == rx) {
    tree[x].push_back(a[lx]);
    return;
  }
  int m = (lx + rx) / 2;
  build((2 * x), lx, m);
  build((2 * x) + 1, m + 1, rx);
  int o1 = 0, o2 = 0;
  while (o1 < tree[x * 2].size() && o2 < tree[x * 2 + 1].size()) {
    if (tree[x * 2][o1] < tree[x * 2 + 1][o2])
      tree[x].push_back(tree[x * 2][o1]), o1++;
    else
      tree[x].push_back(tree[x * 2 + 1][o2]), o2++;
  }
  while (o1 < tree[x * 2].size()) tree[x].push_back(tree[x * 2][o1]), o1++;
  while (o2 < tree[x * 2 + 1].size())
    tree[x].push_back(tree[x * 2 + 1][o2]), o2++;
}
int bin(int x, int q) {
  int l = -1, r = tree[x].size();
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (tree[x][mid] < q)
      l = mid;
    else
      r = mid;
  }
  return l + 1;
}
int go(int q, int l, int r, int x, int lx, int rx) {
  if (rx < l || lx > r) {
    return 0;
  }
  if (rx <= r && lx >= l) {
    return bin(x, q);
  }
  int mid = (lx + rx) / 2;
  if (l <= mid && mid < r) {
    int o1 = go(q, l, r, x * 2, lx, mid);
    int o2 = go(q, l, r, x * 2 + 1, mid + 1, rx);
    return o1 + o2;
  }
  if (l <= mid) return go(q, l, r, x * 2, lx, mid);
  return go(q, l, r, x * 2 + 1, mid + 1, rx);
}
map<int, int> mp;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = n; i >= 1; i--) {
    a[i] = ++mp[arr[i]];
  }
  mp.clear();
  build(1, 1, n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += go(++mp[arr[i]], i + 1, n, 1, 1, n);
  }
  cout << ans << endl;
  return 0;
}
