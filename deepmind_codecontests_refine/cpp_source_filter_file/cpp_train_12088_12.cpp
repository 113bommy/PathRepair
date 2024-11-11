#include <bits/stdc++.h>
using namespace std;
const bool debug = false;
const int MAXN = 2e5;
const long long INF = 1e18;
int n, m, q, z = 1;
vector<vector<pair<int, int>>> g, spt;
vector<int> order, pos, h, binlog(MAXN + 1, 0);
set<pair<int, int>> NotUsedEdges;
vector<vector<long long>> d(21, vector<long long>(MAXN, INF));
ostream &operator<<(ostream &os, pair<int, int> p) {
  os << '<' << p.first << ',' << p.second << '>';
  return os;
}
void dfs(int v, int curh, long long curw, int p = -1) {
  order.push_back(curh);
  pos[v] = (int)order.size() - 1;
  h[v] = curh;
  d[0][v] = curw;
  for (auto to : g[v]) {
    if (pos[to.second] != -1) {
      if (to.second != p) {
        NotUsedEdges.insert(make_pair(min(v, to.second), max(v, to.second)));
      }
    } else {
      dfs(to.second, curh + 1, curw + to.first, v);
      order.push_back(v);
    }
  }
}
void build() {
  int sz = (int)order.size();
  spt.resize(binlog[sz] + 1);
  spt[0].resize(sz);
  for (int i = 0; i < sz; ++i) {
    spt[0][i] = make_pair(h[order[i]], order[i]);
  }
  for (int i = 1; i <= binlog[sz]; ++i) {
    int len = 1 << i;
    spt[i].resize(sz - len + 1);
    for (int j = 0; j < sz - len + 1; ++j) {
      spt[i][j] = min(spt[i - 1][j], spt[i - 1][j + len / 2]);
    }
  }
}
int lca(int v, int u) {
  int l = pos[v], r = pos[u];
  if (r < l) swap(r, l);
  int len = 1 << binlog[r - l + 1];
  return min(spt[binlog[len]][l], spt[binlog[len]][r - len + 1]).second;
}
void Dijkstra(vector<long long> &d_) {
  set<pair<long long, int>> s;
  for (int i = 0; i < n; ++i) {
    s.insert(make_pair(d_[i], i));
  }
  for (int i = 0; i < n; ++i) {
    int v = s.begin()->second;
    long long curd = s.begin()->first;
    s.erase(s.begin());
    for (size_t j = 0; j < g[v].size(); ++j) {
      int to = g[v][j].second;
      long long e = g[v][j].first;
      if (curd + e < d_[to]) {
        s.erase(make_pair(d_[to], to));
        d_[to] = curd + e;
        s.insert(make_pair(d_[to], to));
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i <= MAXN; i <<= 1) {
    binlog[i] = binlog[i - 1] + 1;
    for (int j = i + 1; j < (i << 1) && j <= MAXN; ++j) {
      binlog[j] = binlog[i];
    }
  }
  if (debug) {
    cout << "binlogs: ";
    for (int i = 1; i <= 30; i++) {
      cout << binlog[i] << ' ';
    }
    cout << endl;
  }
  cin >> n >> m;
  g.resize(n);
  pos.resize(n, -1);
  h.resize(n);
  for (int i = 0; i < m; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    from--, to--;
    g[from].push_back(make_pair(weight, to));
    g[to].push_back(make_pair(weight, from));
  }
  dfs(0, 0, 0);
  if (debug) {
    cout << "order: ";
    for (auto &i : order) cout << i << ' ';
    cout << endl;
    cout << "pos: ";
    for (auto &i : pos) cout << i << ' ';
    cout << endl;
    cout << "h: ";
    for (auto &i : h) cout << i << ' ';
    cout << endl;
    cout << "d[0]: ";
    for (int i = 0; i < n; ++i) {
      cout << d[0][i] << ' ';
    }
    cout << endl;
    cout << "NotUsedEdges: ";
    for (auto &i : NotUsedEdges) cout << i << ' ';
    cout << endl;
  }
  build();
  if (debug) {
    cout << "spt:" << endl;
    for (size_t i = 0; i < spt.size(); ++i) {
      cout << '[' << i << "]: ";
      for (size_t j = 0; j < spt[i].size(); ++j) {
        cout << spt[i][j] << ' ';
      }
      cout << endl;
    }
    cout << "test lca:" << endl;
    for (int i = 0; i < 10; i++) {
      int v, u;
      cin >> v >> u;
      v--, u--;
      cout << "lca: " << lca(v, u) << endl;
    }
  }
  for (auto &e : NotUsedEdges) {
    d[z][e.first] = 0;
    Dijkstra(d[z]);
    z++;
  }
  if (debug) {
    cout << "Dijkstra" << endl;
    for (int i = 1; i < z; ++i) {
      cout << "d[" << i << "]: ";
      for (int j = 0; j < n; ++j) {
        cout << d[i][j] << ' ';
      }
      cout << endl;
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    int k = lca(v, u);
    assert(k >= 0 && k < n);
    long long ans = d[0][v] + d[0][u] - 2 * d[0][k];
    for (int j = 1; j < z; ++j) {
      ans = min(ans, d[j][v] + d[j][u]);
    }
    cout << ans << endl;
  }
  return 0;
}
