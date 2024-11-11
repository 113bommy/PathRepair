#include <bits/stdc++.h>
using namespace std;
int n;
int m;
const int MAXN = 400000;
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
int mark[MAXN];
set<pair<int, int> > Set;
vector<int> Comp[MAXN];
void IS_BRIDGE(int v1, int v2) {
  Set.insert(make_pair(v1, v2));
  Set.insert(make_pair(v2, v1));
}
void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) IS_BRIDGE(v, to);
    }
  }
}
void find_bridges() {
  timer = 0;
  for (int i = 0; i < n; ++i) used[i] = false;
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs(i);
}
int color = 0;
void dfsComp(int v) {
  mark[v] = color;
  for (int i = 0; i < g[v].size(); i++) {
    int v2 = g[v][i];
    if (mark[v2] == 0 && Set.find(make_pair(v, v2)) == Set.end()) {
      dfsComp(v2);
    }
  }
}
void make_comp() {
  for (int i = 0; i < n; i++) {
    if (mark[i] == 0) {
      ++color;
      mark[i] = color;
      dfsComp(i);
    }
  }
}
vector<int> V[MAXN];
void make_new_graph() {
  set<pair<int, int> >::iterator it = Set.begin();
  while (it != Set.end()) {
    int f = it->first;
    int s = it->second;
    V[mark[f]].push_back(mark[s]);
    it++;
  }
}
int kolMost[MAXN];
int markFin[MAXN];
pair<int, int> Mesto[MAXN];
int obratn[MAXN];
vector<int> Priam;
void dfsFinish(int v, int kol = 0) {
  Priam.push_back(kol);
  Mesto[v].first = Priam.size() - 1;
  obratn[Priam.size() - 1] = v;
  markFin[v] = 1;
  kolMost[v] = kol;
  for (int i = 0; i < V[v].size(); i++) {
    if (markFin[V[v][i]] == 0) {
      dfsFinish(V[v][i], kol + 1);
    }
    Priam.push_back(kol);
    obratn[Priam.size() - 1] = v;
  }
  if (V[v].size() == 0) {
    Priam.push_back(kol);
    obratn[Priam.size() - 1] = v;
  }
  Mesto[v].second = Priam.size() - 1;
}
int Finish(int v, int v2) {
  for (int i = 0; i <= n; i++) {
    markFin[i] = 0;
    kolMost[i] = -1;
  }
  dfsFinish(v, 0);
  return kolMost[v2];
}
vector<int> t;
void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = tl - 1;
  else {
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    if (Priam[t[v * 2]] < Priam[t[v * 2 + 1]])
      t[v] = t[v * 2];
    else
      t[v] = t[v * 2 + 1];
  }
}
int sum(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  int f1 = -1, f2 = -1;
  if (min(r, tm) >= l) {
    f1 = sum(v * 2, tl, tm, l, min(r, tm));
  }
  if (max(l, tm + 1) <= r) {
    f2 = sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  if (f1 == -1) return f2;
  if (f2 == -1) return f1;
  if (f1 != -1 && f2 != -1 && Priam[f1] < Priam[f2])
    return f1;
  else
    return f2;
}
int predok(int x, int y) {
  if (Mesto[x].second < Mesto[y].first) {
    int temp = sum(1, 1, Priam.size(), Mesto[x].second, Mesto[y].first);
    return obratn[temp];
  } else {
    int temp = sum(1, 1, Priam.size(), Mesto[y].second, Mesto[x].first);
    return obratn[temp];
  }
}
int main() {
  cin >> n;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  find_bridges();
  make_comp();
  make_new_graph();
  dfsFinish(1);
  t.resize(4 * Priam.size());
  build(1, 1, Priam.size());
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if ((Mesto[mark[x]].first <= Mesto[mark[y]].first &&
         Mesto[mark[x]].second >= Mesto[mark[y]].second) ||
        (Mesto[mark[x]].first >= Mesto[mark[y]].first &&
         Mesto[mark[x]].second <= Mesto[mark[y]].second)) {
      cout << abs(kolMost[mark[x]] - kolMost[mark[y]]) << endl;
    } else {
      int obsPr = predok(mark[x], mark[y]);
      cout << kolMost[mark[x]] + kolMost[mark[y]] - 2 * kolMost[obsPr] << endl;
    }
  }
  return 0;
}
