#include <bits/stdc++.h>
using namespace std;
struct unionfind {
  vector<int> par;
  vector<int> sz;
  unionfind(int n) : par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }
  unionfind() {}
  int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    par[a] = b;
    sz[b] += sz[a];
  }
};
struct tree {
  int n;
  vector<pair<int, int>> edges;
  vector<int> ws;
  vector<long long> res;
  void addedge(int a, int b, int w) {
    ws.push_back(w);
    edges.emplace_back(a, b);
  }
  unionfind uf;
  void process(vector<int> gp) {
    vector<int> nds;
    vector<vector<pair<int, int>>> adjlist;
    vector<int> subsz;
    vector<int> szs;
    for (auto e : gp) {
      nds.push_back(uf.find(edges[e].first));
      nds.push_back(uf.find(edges[e].second));
    }
    sort(nds.begin(), nds.end());
    nds.erase(unique(nds.begin(), nds.end()), nds.end());
    auto get = [&](int x) {
      return lower_bound(nds.begin(), nds.end(), x) - nds.begin();
    };
    int nn = nds.size();
    int m = gp.size();
    szs.resize(nn);
    subsz.resize(nn, -1);
    adjlist.resize(nn);
    for (int i = 0; i < nn; i++) {
      szs[i] = uf.sz[nds[i]];
    }
    for (int i = 0; i < m; i++) {
      int a = get(uf.find(edges[gp[i]].first));
      int b = get(uf.find(edges[gp[i]].second));
      adjlist[a].emplace_back(b, gp[i]);
      adjlist[b].emplace_back(a, gp[i]);
    }
    function<int(int, int)> szdfs = [&](int curr, int par) {
      subsz[curr] = szs[curr];
      for (auto np : adjlist[curr]) {
        int next = np.first;
        if (next == par) continue;
        subsz[curr] += szdfs(next, curr);
      }
      return subsz[curr];
    };
    function<void(int, int, int)> resdfs = [&](int curr, int par, int ts) {
      for (auto np : adjlist[curr]) {
        int next = np.first;
        if (next == par) continue;
        resdfs(next, curr, ts);
        res[np.second] =
            ((long long)subsz[next]) * (long long)(ts - subsz[next]);
      }
    };
    for (int i = 0; i < nn; i++) {
      if (subsz[i] != -1) continue;
      szdfs(i, -1);
      resdfs(i, -1, subsz[i]);
    }
  }
  void solve() {
    vector<int> srt(n - 1);
    iota(srt.begin(), srt.end(), 0);
    sort(srt.begin(), srt.end(),
         [&](const int& lhs, const int& rhs) { return ws[lhs] < ws[rhs]; });
    vector<vector<int>> grps;
    grps.emplace_back(1, srt[0]);
    for (int i = 1; i < n - 1; i++) {
      if (ws[grps.back().back()] != ws[srt[i]]) {
        grps.emplace_back();
      }
      grps.back().push_back(srt[i]);
    }
    uf = unionfind(n);
    res.resize(n - 1);
    for (auto g : grps) {
      process(g);
      for (auto i : g) {
        uf.unite(edges[i].first, edges[i].second);
      }
    }
  }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  tree t;
  t.n = n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    t.addedge(a, b, w);
  }
  t.solve();
  long long rs = *max_element(t.res.begin(), t.res.end());
  cout << 2ll * rs << " " << count(t.res.begin(), t.res.end(), rs) << "\n";
  for (int i = 0; i < n - 1; i++) {
    if (t.res[i] == rs) cout << (i + 1) << " ";
  }
  cout << "\n";
}
