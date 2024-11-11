#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
int t, tree[4 * N], tmin[N], tmout[N], timer, lazy[4 * N], r[N], n, k, a[N];
vector<int> V[N];
void update(int u, int start, int end, int l, int r, int val) {
  if (lazy[u]) {
    tree[u] += lazy[u];
    if (l != r) {
      lazy[2 * u] += lazy[u];
      lazy[2 * u + 1] += lazy[u];
    }
    lazy[u] = 0;
  }
  if (l > end || r < start) return;
  if (start <= l && r <= end) {
    lazy[u] = val;
    tree[u] += lazy[u];
    if (l != r) {
      lazy[2 * u] += lazy[u];
      lazy[2 * u + 1] += lazy[u];
    }
    lazy[u] = 0;
    return;
  }
  int mid = (l + r) / 2;
  update(2 * u, start, end, l, mid, val);
  update(2 * u + 1, start, end, mid + 1, r, val);
  tree[u] = max(tree[2 * u], tree[2 * u + 1]);
}
void dfs(int u) {
  timer++;
  tmin[u] = timer;
  for (int i = 0; i < V[u].size(); i++) dfs(V[u][i]);
  tmout[u] = timer;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    int x = i + 1;
    while (x <= n && a[x] <= a[i]) {
      x = r[x];
    }
    r[i] = x;
    V[r[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (r[i] == n + 1) dfs(i);
  }
  for (int i = 1; i <= k; i++) {
    update(1, tmin[i], tmout[i], 1, n, 1);
  }
  cout << tree[1] << " ";
  for (int i = 2; i <= n - k + 1; i++) {
    update(1, tmin[i + k - 1], tmout[i + k - 1], 1, n, 1);
    update(1, tmin[i - 1], tmin[i - 1], 1, n, 0);
    cout << tree[1] << " ";
  }
}
