#include <bits/stdc++.h>
using namespace std;
int n, m, nc;
vector<vector<pair<int, int>>> g;
vector<vector<int>> gc, gc2g;
vector<int> g2gc;
vector<pair<int, int>> bridges, result;
vector<int> tin, fup, used, temp;
int timer;
void is_bridge(int v, int to) {
  bridges.push_back(pair<int, int>(v, to));
  for (int i = 0; i < g[v].size(); i++)
    if (g[v][i].first == to) {
      g[v][i].second = 0;
      break;
    }
  for (int i = 0; i < g[to].size(); i++)
    if (g[to][i].first == v) {
      g[to][i].second = 0;
      break;
    }
}
void dfs1(int v, int p = -1) {
  used[v] = 1;
  tin[v] = fup[v] = timer++;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i].first;
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs1(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) is_bridge(v, to);
    }
  }
}
void find_bridges() {
  timer = 0;
  tin.resize(n);
  fup.resize(n);
  used.resize(n, 0);
  for (int i = 0; i < n; i++)
    if (!used[i]) dfs1(i);
}
void dfs2(int v, int p = -1) {
  used[v] = 1;
  g2gc[v] = p;
  temp.push_back(v);
  for (int i = 0; i < g[v].size(); i++) {
    if (g[v][i].second) {
      int to = g[v][i].first;
      if (!used[to]) dfs2(to, p);
    }
  }
}
void find_components() {
  g2gc.resize(n);
  used.assign(n, 0);
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (!used[i]) {
      temp.clear();
      dfs2(i, cnt++);
      gc2g.push_back(temp);
    }
}
void make_gc() {
  nc = gc2g.size();
  gc.resize(nc);
  for (int i = 0; i < bridges.size(); i++) {
    int a = g2gc[bridges[i].first];
    int b = g2gc[bridges[i].second];
    gc[a].push_back(b);
    gc[b].push_back(a);
  }
}
void condensation() {
  find_bridges();
  find_components();
  make_gc();
}
void find_result(int v, int &f, int &s, bool st = false) {
  used[v] = true;
  f = -1;
  s = -1;
  if (gc[v].size() == 1) {
    f = gc2g[v][0];
    return;
  }
  for (int i = 0; i < gc[v].size(); i++) {
    int to = gc[v][i];
    if (used[to]) continue;
    int nf, ns;
    find_result(to, nf, ns);
    if (f == -1) {
      f = nf;
      s = ns;
      continue;
    }
    if (s == -1) {
      if (ns == -1)
        s = nf;
      else {
        result.push_back(pair<int, int>(f, nf));
        if (st && i == (gc[v].size() - 1)) {
          result.push_back(pair<int, int>(f, ns));
          f = -1;
        } else
          f = ns;
      }
    } else {
      result.push_back(pair<int, int>(s, nf));
      if (st && i == (gc[v].size() - 1) && ns == -1) {
        result.push_back(pair<int, int>(s, f));
        f = -1;
      }
      s = ns;
    }
  }
  if (st && s != -1) {
    result.push_back(pair<int, int>(s, f));
    f = -1;
    s = -1;
  }
}
void handle() {
  if (n == 2) {
    cout << -1;
    exit(0);
  }
  if (!nc) {
    cout << 0;
    exit(0);
  }
  if (nc == 2) {
    int v = bridges[0].first;
    int to = bridges[0].second;
    int vc = g2gc[v];
    if (gc2g[vc].size() == 1) {
      swap(v, to);
      vc = g2gc[v];
    }
    int nv = gc2g[vc][0];
    if (nv == v) nv = gc2g[vc][1];
    cout << 1 << endl;
    cout << nv + 1 << " " << to + 1;
    exit(0);
  }
  used.assign(nc, 0);
  int v = 0;
  if (gc[v].size() == 1) v = gc[v][0];
  int f, s;
  find_result(v, f, s, true);
}
int main() {
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(pair<int, int>(b, 1));
    g[b].push_back(pair<int, int>(a, 1));
  }
  condensation();
  handle();
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << result[i].first + 1 << " " << result[i].second + 1 << endl;
  }
  cin >> n;
  return 0;
}
