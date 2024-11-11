#include <bits/stdc++.h>
using namespace std;
const int maxN = 101000;
int n, m;
vector<int> g[maxN];
map<pair<int, int>, vector<int> > edges;
int used[2 * maxN];
int usedindex[2 * maxN];
vector<int> onev;
set<int> unused;
vector<vector<int> > ans;
vector<int> cur;
vector<int> update(vector<int> buf) {
  vector<int> ret;
  ret.push_back(buf.size());
  for (int i = 0; i < buf.size(); ++i) {
    ret.push_back(buf[i]);
  }
  return ret;
}
bool have(int i, int j) {
  if (edges[make_pair(i, j)].size() == 0) return false;
  if (edges[make_pair(j, i)].size() == 0) return false;
  return true;
}
void dfs2(int v) {
  unused.erase(v);
  for (int i = 0; i < g[v].size(); ++i) {
    if (unused.count(g[v][i]) && have(v, g[v][i])) {
      dfs2(g[v][i]);
    }
  }
}
int iter;
void dfs(int v, int p = -1) {
  dfs2(v);
  vector<int> nodes;
  used[v] = 1;
  cur.push_back(v);
  for (int i = 0; i < g[v].size(); ++i) {
    if (used[g[v][i]] && g[v][i] != p && have(v, g[v][i])) {
      vector<int> buf = edges[make_pair(v, g[v][i])];
      for (int k = 0; k < buf.size(); ++k) {
        if (usedindex[buf[k]]) continue;
        usedindex[buf[k]] = 1;
        if (onev.size() > 0) {
          int t = onev.back();
          onev.pop_back();
          int index = buf[k];
          ans.push_back(update(cur));
          cur.clear();
          vector<int> nv;
          nv.push_back(index);
          nv.push_back(v);
          nv.push_back(t);
          ans.push_back(nv);
          cur.push_back(t);
          cur.push_back(v);
        } else if (unused.size() > 0) {
          int t = *unused.begin();
          ans.push_back(update(cur));
          int index = buf[k];
          cur.clear();
          vector<int> nv;
          nv.push_back(index);
          nv.push_back(v);
          nv.push_back(t);
          ans.push_back(nv);
          dfs(t);
          cur.push_back(v);
        }
      }
    }
  }
  for (int i = 0; i < g[v].size(); ++i) {
    if (!used[g[v][i]] && have(v, g[v][i])) {
      nodes.push_back(g[v][i]);
      used[g[v][i]] = 1;
    }
  }
  for (int i = 0; i < nodes.size(); ++i) {
    dfs(nodes[i], v);
    cur.push_back(v);
    if (i + 1 != nodes.size()) {
      vector<int> buf = edges[make_pair(v, nodes[i])];
      for (int k = 0; k < buf.size(); ++k) {
        if (onev.size() > 0) {
          int t = onev.back();
          onev.pop_back();
          int index = buf[k];
          ans.push_back(update(cur));
          cur.clear();
          vector<int> nv;
          nv.push_back(index);
          nv.push_back(v);
          nv.push_back(t);
          ans.push_back(nv);
          cur.push_back(t);
          cur.push_back(v);
        } else if (unused.size() > 0) {
          int t = *unused.begin();
          ans.push_back(update(cur));
          int index = buf[k];
          cur.clear();
          vector<int> nv;
          nv.push_back(index);
          nv.push_back(v);
          nv.push_back(t);
          ans.push_back(nv);
          dfs(t);
          cur.push_back(v);
        }
      }
    } else {
      vector<int> buf = edges[make_pair(v, nodes[i])];
      for (int k = 0; k < buf.size(); ++k) {
        if ((k + 1 != buf.size() && onev.size() > 0) ||
            (unused.size() == 0 && onev.size() > 0) ||
            (p != -1 && onev.size() > 0)) {
          int t = onev.back();
          onev.pop_back();
          int index = buf[k];
          ans.push_back(update(cur));
          cur.clear();
          vector<int> nv;
          nv.push_back(index);
          nv.push_back(v);
          nv.push_back(t);
          ans.push_back(nv);
          cur.push_back(t);
          cur.push_back(v);
        } else if (unused.size() > 0) {
          int t = *unused.begin();
          ans.push_back(update(cur));
          int index = buf[k];
          cur.clear();
          vector<int> nv;
          nv.push_back(index);
          nv.push_back(v);
          nv.push_back(t);
          ans.push_back(nv);
          dfs(t);
          cur.push_back(v);
        }
      }
    }
  }
}
int deg[maxN];
int timer, tin[maxN], fup[maxN];
set<pair<int, int> > bridges;
void dfsb(int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfsb(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) {
        bridges.insert(make_pair(v, to));
        bridges.insert(make_pair(to, v));
      }
    }
  }
}
void find_bridges() {
  timer = 0;
  for (int i = 0; i < n; ++i) used[i] = false;
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs(i);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    ++deg[x];
    g[y].push_back(x);
    ++deg[y];
    edges[make_pair(x, y)].push_back(i + 1);
    edges[make_pair(y, x)].push_back(i + 1);
  }
  iter = 1;
  int st = 1;
  if (g[1].size() == 0) {
    if (n == 1) {
      cout << "YES" << endl;
      cout << "0" << endl;
      cout << "1 1" << endl;
      return 0;
    } else {
      if (m == 0) {
        cout << "NO" << endl;
        return 0;
      }
      memset(used, 0, sizeof(used));
      for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
          dfs(i);
        }
      }
      int cneed = 0, cneed2 = 0;
      for (map<pair<int, int>, vector<int> >::iterator it = edges.begin();
           it != edges.end(); ++it) {
        if (it->second.size() > 1) {
          cneed = it->first.first;
          cneed2 = it->first.second;
        } else if (!bridges.count(it->first)) {
          cneed = it->first.first;
          cneed2 = it->first.second;
        }
      }
      if (cneed == 0 || cneed2 == 0) {
        for (int i = 1; i <= n; ++i) {
          for (int j = 0; j < g[i].size(); ++j) {
            int u = i, v = g[i][j];
            if (deg[u] > 1) {
              cneed = u, cneed2 = v;
            }
          }
        }
      }
      if (cneed == 0 || cneed2 == 0) {
        cout << "NO" << endl;
        return 0;
      }
      pair<pair<int, int>, vector<int> > val;
      val.first = make_pair(cneed, cneed2);
      val.second = edges[make_pair(cneed, cneed2)];
      if (val.second.size() == 1) {
        edges.erase(val.first);
        edges.erase(make_pair(val.first.second, val.first.first));
      } else {
        edges[val.first].pop_back();
        vector<int> buf = edges[make_pair(val.first.second, val.first.first)];
        vector<int> nv;
        for (int j = 0; j < buf.size(); ++j) {
          if (buf[j] != val.second.back()) {
            nv.push_back(buf[j]);
          }
        }
        edges[make_pair(val.first.second, val.first.first)] = nv;
      }
      --deg[val.first.second];
      --deg[val.first.first];
      vector<int> nval;
      nval.push_back(1);
      ans.push_back(update(nval));
      nval.clear();
      nval.push_back(val.second.back());
      nval.push_back(1);
      nval.push_back(val.first.first);
      st = val.first.first;
      ans.push_back(nval);
      iter = 0;
    }
  }
  memset(used, 0, sizeof(used));
  int nst = 1;
  if (st != 1) nst = 2;
  for (int i = nst; i <= n; ++i) {
    if (deg[i] == 0) {
      onev.push_back(i);
    } else {
      unused.insert(i);
    }
  }
  dfs(st);
  ans.push_back(update(cur));
  if (unused.size() == 0 && onev.size() == 0) {
    printf("YES\n");
    printf("%d\n", (int)(ans.size()) / 2);
    for (int i = 0; i < ans.size(); ++i) {
      for (int j = 0; j < ans[i].size(); ++j) {
        printf("%d ", ans[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("NO\n");
  }
  return 0;
}
