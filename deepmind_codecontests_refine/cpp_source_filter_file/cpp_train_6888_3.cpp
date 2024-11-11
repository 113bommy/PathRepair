#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 10;
int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b % 2) {
      res = 1LL * res * a % mod;
    }
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return res;
}
vector<pair<int, int> > adj[N];
pair<int, int> dfs(int node = 1, int par = 0) {
  pair<int, int> leaf;
  leaf.first = leaf.second = 0;
  for (auto child : adj[node]) {
    if (child.first == par) continue;
    if (leaf.first == 0) {
      leaf.first = dfs(child.first, node).first;
    } else if (leaf.second == 0) {
      leaf.second = dfs(child.first, node).first;
    }
  }
  if (leaf.first == 0) {
    leaf.first = node;
  }
  return leaf;
}
int main() {
  int n, u[N], v[N], val[N];
  vector<pair<int, pair<int, int> > > ans;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d", &u[i], &v[i], &val[i]);
    adj[u[i]].push_back({v[i], val[i]});
    adj[v[i]].push_back({u[i], val[i]});
  }
  if (n == 2) {
    printf("%d %d %d\n", u[1], v[1], val[1]);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 2) {
      printf("NO\n");
      return 0;
    }
  }
  for (int i = 1; i < n; i++) {
    int x = val[i] / 2;
    pair<int, int> l = dfs(u[i], v[i]);
    pair<int, int> r = dfs(v[i], u[i]);
    if (l.second > r.second) {
      swap(l, r);
    }
    if (l.second == 0) {
      ans.push_back({l.first, {r.first, x}});
      ans.push_back({l.first, {r.second, x}});
      ans.push_back({r.first, {r.second, -x}});
    } else {
      ans.push_back({l.first, {r.first, x}});
      ans.push_back({l.second, {r.second, x}});
      ans.push_back({l.first, {l.second, -x}});
      ans.push_back({r.first, {r.second, -x}});
    }
  }
  printf("YES\n%d\n", ans.size());
  for (auto op : ans) {
    printf("%d %d %d\n", op.first, op.second.first, op.second.second);
  }
  return 0;
}
