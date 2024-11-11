#include <bits/stdc++.h>
#pragma GCC optimize "O3"
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5;
const int M = 1 << 18;
pair<long long, int> tree[M * 2 + 5];
long long lazy[M * 2 + 5];
int n, ans[N];
void push(int v) {
  tree[v * 2].first += lazy[v];
  tree[v * 2 + 1].first += lazy[v];
  lazy[v * 2] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}
void add(int l, int r, long long val, int v = 1, int le = 1, int re = M - 1) {
  if (l > r || l > re || r < le) return;
  if (le >= l && re <= r) {
    tree[v].first += val;
    lazy[v] += val;
    return;
  }
  int mid = (le + re) / 2;
  push(v);
  add(l, r, val, v * 2, le, mid);
  add(l, r, val, v * 2 + 1, mid + 1, re);
  tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
}
void solve() {
  int pom;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> tree[i + M - 1].first;
    tree[i + M - 1].second = {-i};
  }
  for (int i = M - 1; i >= 1; i--) tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
  for (int i = 1; i <= n; i++) {
    pom = -tree[1].second;
    ans[pom] = i;
    add(pom, pom, INF);
    add(pom + 1, n, -pom);
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
