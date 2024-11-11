#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
vector<int> adj[maxn];
int a[maxn], t, d[maxn], in[maxn], h[maxn];
long long ans[4 * maxn];
bool mark[maxn];
void add(int l, int r, int val, int ind, int b, int e) {
  if (l <= b && e <= r) {
    ans[ind] += (long long)val;
    return;
  }
  int mid = (b + e) / 2;
  if (l < mid) add(l, r, val, ind * 2, b, mid);
  if (r > mid) add(l, r, val, ind * 2 + 1, mid, e);
  return;
}
long long get(int p, int ind, int b, int e) {
  long long ret = ans[ind];
  if (e - b == 1) return ret;
  int mid = (b + e) / 2;
  if (p < mid)
    ret += get(p, ind * 2, b, mid);
  else
    ret += get(p, ind * 2 + 1, mid, e);
  return ret;
}
void dfs(int v) {
  in[v] = t;
  d[v]++;
  t++;
  mark[v] = 1;
  for (int i = 0; i < (int)adj[v].size(); i++) {
    if (!mark[adj[v][i]]) {
      h[adj[v][i]] = h[v] + 1;
      dfs(adj[v][i]);
      d[v] += d[adj[v][i]];
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  int x, y;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0);
  int k, val;
  long long out;
  for (int i = 0; i < m; i++) {
    cin >> k;
    if (k == 1) {
      cin >> x >> val;
      x--;
      if (h[in[x]] % 2 == 0)
        add(in[x], in[x] + d[x], val, 1, 0, n);
      else
        add(in[x], in[x] + d[x], -val, 1, 0, n);
    } else {
      cin >> x;
      x--;
      out = get(in[x], 1, 0, n);
      if (h[x] % 2 == 0)
        cout << out + a[x];
      else
        cout << -out + a[x];
      cout << endl;
    }
  }
  return 0;
}
