#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n;
int a[MAXN];
vector<int> edge[MAXN];
bool mark[MAXN];
int st[MAXN];
int ft[MAXN];
int sign[MAXN];
int tim;
void dfs(int v) {
  mark[v] = true;
  st[v] = tim;
  tim++;
  for (int u : edge[v]) {
    if (!mark[u]) {
      sign[u] = (-1) * sign[v];
      dfs(u);
    }
  }
  ft[v] = tim;
}
int seg[MAXN * 4];
void add(int val, int l, int r, int b = 0, int e = n, int k = 0) {
  if (l <= b && e <= r) {
    seg[k] += val;
    return;
  }
  if (r <= b || e <= l) return;
  int mid = (b + e) / 2;
  add(val, l, r, b, mid, k * 2 + 1);
  add(val, l, r, mid, e, k * 2 + 2);
  return;
}
int get(int i, int b = 0, int e = n, int k = 0) {
  if (i < b || i >= e) return 0;
  if (b + 1 == e) return seg[k];
  int mid = (b + e) / 2;
  return seg[k] + get(i, b, mid, k * 2 + 1) + get(i, mid, e, k * 2 + 2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[v].push_back(u);
    edge[u].push_back(v);
  }
  sign[0] = 1;
  dfs(0);
  while (q--) {
    int i, val;
    cin >> i;
    if (i == 1) {
      cin >> i >> val;
      i--;
      add(val * sign[i], st[i], ft[i]);
    } else if (i == 2) {
      cin >> i;
      i--;
      int ans = get(st[i]);
      cout << a[i] + sign[i] * ans << '\n';
    }
  }
}
