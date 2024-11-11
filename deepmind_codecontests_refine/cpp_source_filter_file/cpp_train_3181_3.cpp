#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int tree_max[4 * maxn];
int tree_min[4 * maxn];
vector<int> qwe;
int n, k;
void build(int v, int l, int r) {
  if (l == r) {
    tree_max[v] = tree_min[v] = qwe[l];
    return;
  }
  int m = (l + r) / 2;
  build(v * 2, l, m);
  build(v * 2 + 1, m + 1, r);
  tree_max[v] = max(tree_max[v * 2], tree_max[v * 2 + 1]);
  tree_min[v] = min(tree_max[v * 2], tree_max[v * 2 + 1]);
}
int get_max(int v, int l, int r, int le, int re) {
  if (l >= le && r <= re) {
    return tree_max[v];
  }
  if (l > re || r < le) return 0;
  int m = (l + r) / 2;
  int a = get_max(v * 2, l, m, le, re);
  int b = get_max(v * 2 + 1, m + 1, r, le, re);
  return max(a, b);
}
int get_min(int v, int l, int r, int le, int re) {
  if (l >= le && r <= re) {
    return tree_min[v];
  }
  if (l > re || r < le) return INT_MAX;
  int m = (l + r) / 2;
  int a = get_min(v * 2, l, m, le, re);
  int b = get_min(v * 2 + 1, m + 1, r, le, re);
  return min(a, b);
}
bool check(int l, int r) {
  int lol1 = get_max(1, 0, n - 1, l, r);
  int lol2 = get_min(1, 0, n - 1, l, r);
  return abs(lol1 - lol2) <= k;
}
int bin_find(int l, int r, int start) {
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (check(m, start))
      r = m;
    else
      l = m;
  }
  if (l == r) return l;
  if (check(l, start))
    return l;
  else
    return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i(0); i < n; i++) {
    int x;
    cin >> x;
    qwe.push_back(x);
  }
  build(1, 0, n - 1);
  int ans = 0;
  for (int i(0); i < n; i++) {
    int mx = bin_find(0, i, i);
    ans = max(ans, i - mx + 1);
  }
  vector<pair<int, int> > in;
  for (int i(0); i < n; i++) {
    int to = i - ans + 1;
    if (to < 0) continue;
    if (check(to, i)) in.push_back({to + 1, i + 1});
  }
  cout << ans << ' ' << in.size() << endl;
  for (int i(0); i < in.size(); i++) {
    cout << in[i].first << ' ' << in[i].second << endl;
  }
  return 0;
}
