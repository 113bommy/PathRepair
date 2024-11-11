#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> ans;
vector<int> a;
vector<int> mp(1000000, 0);
vector<int> lb;
vector<int> p, pi;
struct query {
  int id, l, k;
};
vector<vector<query>> vq;
void dfs(int v, int pa = -1) {
  mp[a[v]]++;
  int c = pi[a[v]];
  int b = lb[mp[a[v]]] - 1;
  swap(p[c], p[b]);
  swap(pi[p[c]], pi[p[b]]);
  lb[mp[a[v]]]--;
  for (query q : vq[v]) {
    int d = lb[q.l];
    if (d + q.k - 1 >= p.size()) {
      ans[q.id] = -1;
    } else {
      ans[q.id] = p[d + q.k - 1];
    }
  }
  for (int u : g[v])
    if (u != pa) {
      dfs(u, v);
    }
  c = lb[mp[a[v]]];
  b = pi[a[v]];
  swap(p[c], p[b]);
  swap(pi[p[c]], pi[p[b]]);
  lb[mp[a[v]]]++;
  mp[a[v]]--;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    g.clear();
    g.resize(n);
    for (int i = 1; i < n; ++i) {
      int x;
      cin >> x;
      --x;
      g[x].push_back(i);
      g[i].push_back(x);
    }
    vq.clear();
    vq.resize(n);
    for (int i = 0; i < q; ++i) {
      int v, l, k;
      cin >> v >> l >> k;
      --v;
      vq[v].push_back({i, l, k});
    }
    ans.resize(q);
    p.resize(n);
    for (int i = 1; i <= n; ++i) {
      p[i - 1] = i;
    }
    pi.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      pi[i] = i - 1;
    }
    lb.resize(n + 2);
    lb[0] = 0;
    for (int i = 1; i <= n + 1; ++i) {
      lb[i] = n;
    }
    dfs(0);
    for (int i : ans) cout << i << ' ';
    cout << '\n';
  }
}
