#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
struct greateri {
  template <class T>
  bool operator()(T const &a, T const &b) const {
    return a > b;
  }
};
void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
vector<long long> trt[100001], tree[100001];
long long tin[100001], tout[100001], impo[100001], dep[100001];
long long par[100001][37];
long long n, in, l;
void dfs(long long node, long long p, long long d) {
  tin[node] = in++;
  par[node][0] = p;
  dep[node] = d;
  for (long long i = 1; i <= l; ++i) {
    par[node][i] = par[par[node][i - 1]][i - 1];
  }
  for (auto it : tree[node]) {
    if (it != p) {
      dfs(it, node, d + 1);
    }
  }
  tout[node] = in++;
}
bool up(long long u, long long v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}
long long lca(long long u, long long v) {
  if (up(u, v)) return u;
  if (up(v, u)) return v;
  for (long long i = l; i >= 0; --i) {
    if (!up(par[u][i], v)) u = par[u][i];
  }
  return par[u][0];
}
bool ka = true;
pair<long long, long long> solve(long long node, long long p) {
  pair<long long, long long> ans;
  ans.first = 0;
  ans.second = 0;
  long long counti = 0;
  long long cna = 0;
  for (auto it : trt[node]) {
    if (it != p) {
      long long len = dep[it] - dep[node];
      if (impo[node]) {
        if (impo[it] && len == 1) ka = false;
        auto v = solve(it, node);
        ans.first += v.first;
        if ((v.second) != 0) counti++;
      } else {
        auto v = solve(it, node);
        ans.first += v.first;
        if ((v.second) != 0) cna++;
      }
    }
  }
  if (impo[node]) {
    ans.first += counti;
    ans.second = 1;
  } else {
    if (cna <= 1) {
      ans.second += cna;
    } else {
      ans.first++;
      ans.second = 0;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  l = log2(n);
  for (long long i = 0; i < n - 1; ++i) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  dfs(0, 0, 0);
  long long q;
  cin >> q;
  while (q--) {
    ka = true;
    long long k;
    cin >> k;
    vector<pair<long long, long long> > imp;
    set<pair<long long, long long> > cum;
    for (long long i = 0; i < k; ++i) {
      long long yo;
      cin >> yo;
      yo--;
      impo[yo]++;
      imp.push_back({tin[yo], yo});
      cum.insert({tin[yo], yo});
    }
    sort((imp).begin(), (imp).end());
    for (long long i = 0; i < k - 1; ++i) {
      long long k = lca(imp[i].second, imp[i + 1].second);
      cum.insert({tin[k], k});
    }
    imp.clear();
    for (auto it : cum) {
      imp.push_back(it);
    }
    vector<long long> yom;
    yom.push_back(imp[0].second);
    for (long long i = 1; i < (long long)imp.size(); ++i) {
      long long cur = imp[i].second;
      while ((long long)yom.size() >= 2 &&
             !up(yom[(long long)yom.size() - 1], cur)) {
        trt[yom[(long long)yom.size() - 2]].push_back(yom.back());
        yom.pop_back();
      }
      yom.push_back(cur);
    }
    while ((long long)yom.size() >= 2) {
      trt[yom[(long long)yom.size() - 2]].push_back(yom.back());
      yom.pop_back();
    }
    auto ans = solve(yom[0], -1);
    if (ka)
      cout << ans.first << '\n';
    else
      cout << -1 << '\n';
    for (long long i = 0; i < imp.size(); ++i) {
      trt[imp[i].second].clear();
      if (impo[imp[i].second]) impo[imp[i].second]--;
    }
    imp.clear();
  }
  return 0;
}
