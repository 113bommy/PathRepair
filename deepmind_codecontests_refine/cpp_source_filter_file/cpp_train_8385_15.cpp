#include <bits/stdc++.h>
using namespace std;
int a[100005], fa[100005], order[100005], ans[100005], n, vis[100005];
long long s[100005];
long long cur_max;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void Union(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  fa[x] = y;
  s[y] += s[x];
  cur_max = max(cur_max, s[y]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    fa[i] = i;
  }
  for (int i = 1; i <= n; ++i) cin >> order[i];
  for (int i = n; i; --i) {
    int id = order[i];
    ans[i] = cur_max;
    vis[id] = 1;
    s[id] = a[id];
    cur_max = max(cur_max, s[id]);
    if (vis[id - 1]) Union(id, id - 1);
    if (vis[id + 1]) Union(id, id + 1);
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}
