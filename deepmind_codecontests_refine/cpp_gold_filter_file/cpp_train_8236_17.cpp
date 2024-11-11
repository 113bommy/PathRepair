#include <bits/stdc++.h>
using namespace std;
struct node {
  long long su;
  long long pre;
  long long suf;
  long long ans;
};
vector<node> g;
vector<int> parent;
void mer(int u, int v) {
  node tmp;
  tmp.su = g[u].su + g[v].su;
  tmp.pre = max(g[u].pre, g[u].su + g[v].pre);
  tmp.suf = max(g[v].suf, g[v].su + g[u].suf);
  tmp.ans = max(max(g[u].ans, g[v].ans), g[u].suf + g[v].pre);
  g[u] = g[v] = tmp;
}
int find(int u) {
  if (parent[u] == u) {
    return u;
  }
  parent[u] = find(parent[u]);
  return parent[u];
}
void join(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  parent[v] = u;
  mer(u, v);
}
int main() {
  int n;
  long long a;
  cin >> n >> a;
  parent.resize(n);
  vector<pair<long long, int> > gaps;
  vector<long long> d(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long c;
    cin >> d[i] >> c;
    node tmp;
    tmp.su = a - c;
    tmp.pre = max(0ll, a - c);
    tmp.suf = max(0ll, a - c);
    tmp.ans = max(0ll, a - c);
    parent[i] = i;
    ans = max(ans, a - c);
    g.push_back(tmp);
    if (i > 0) {
      long long gap = (d[i] - d[i - 1]) * (d[i] - d[i - 1]);
      gaps.push_back(make_pair(gap, i));
    }
  }
  sort(gaps.begin(), gaps.end());
  for (int i = 0; i < gaps.size(); i++) {
    long long gap = gaps[i].first;
    int ind = gaps[i].second;
    join(ind - 1, ind);
    int p = find(ind);
    ans = max(ans, g[p].ans - gap);
  }
  cout << ans << '\n';
}
