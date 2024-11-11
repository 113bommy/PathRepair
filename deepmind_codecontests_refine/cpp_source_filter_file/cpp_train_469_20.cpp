#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, a[N], sub[N], tree[N * 2];
vector<int> g[N];
long long ans;
void make() {
  for (int i = n - 1; i >= 0; i--) {
    if (a[tree[i * 2]] > a[tree[i * 2 + 1]])
      tree[i] = tree[i * 2];
    else
      tree[i] = tree[i * 2 + 1];
  }
}
int query(int l, int r) {
  int res = 0;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      if (a[tree[l]] > a[res]) res = tree[l];
      l++;
    }
    if (r & 1)
      if (a[tree[--r]] > a[res]) res = tree[r];
  }
  return res;
}
void dfs(int u) {
  sub[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    dfs(g[u][i]);
    sub[u] += sub[g[u][i]];
  }
  ans += 1ll * sub[u] * (n - (a[u]));
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    tree[i + n - 1] = i;
  }
  tree[n * 2 - 1] = n, a[n] = n;
  make();
  for (int i = 1; i < n; i++) {
    int u = query(i, a[i] - 1);
    g[u].push_back(i);
  }
  ans = n * (n - 1) / 2;
  dfs(n);
  cout << ans;
}
