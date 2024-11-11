#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int n, m, nn;
int ncc = 0, top = 0, number = 0;
int cnt = 0;
int st[N];
struct Node {
  vector<int> adj;
  int num, low;
  int scc;
  Node() {
    num = -1;
    scc = -1;
  }
} nodes[N];
void dfs(int u) {
  nodes[u].num = nodes[u].low = ++number;
  st[++top] = u;
  for (__typeof(nodes[u].adj.begin()) it = nodes[u].adj.begin();
       it != nodes[u].adj.end(); ++it) {
    int v = *it;
    if (nodes[v].num == -1) {
      dfs(v);
      nodes[u].low = min(nodes[u].low, nodes[v].low);
    } else if (nodes[v].scc == -1) {
      nodes[u].low = min(nodes[u].low, nodes[v].num);
    }
  }
  if (nodes[u].num == nodes[u].low) {
    while (true) {
      int v = st[top--];
      nodes[v].scc = ncc;
      if (v == u) break;
    }
    ncc++;
  }
}
bool haveSolution() {
  for (int i = 0; i < nn; ++i)
    if (nodes[i].num == -1) dfs(i);
  for (int i = 0; i < n; ++i)
    if (nodes[i].scc == nodes[i + n].scc) return false;
  return true;
}
struct Component {
  vector<int> adj, negative;
  int topo, value;
  Component() {
    value = -1;
    topo = -1;
  }
};
vector<Component> components;
vector<pair<int, int> > topos;
void dfsTopo(int u) {
  for (__typeof(components[u].adj.begin()) it = components[u].adj.begin();
       it != components[u].adj.end(); ++it) {
    int v = *it;
    if (components[v].topo == -1) dfsTopo(v);
  }
  components[u].topo = --cnt;
}
void setValue(int u, int value) {
  if (components[u].value > 0) return;
  components[u].value = value;
  for (__typeof(components[u].negative.begin()) it =
           components[u].negative.begin();
       it != components[u].negative.end(); ++it) {
    setValue(*it, 1 - value);
  }
  if (value > 0) {
    for (__typeof(components[u].adj.begin()) it = components[u].adj.begin();
         it != components[u].adj.end(); ++it) {
      setValue(*it, value);
    }
  }
}
void creatSolution() {
  components = vector<Component>(ncc, Component());
  for (int u = 0; u < n; ++u) {
    components[nodes[u].scc].negative.push_back(nodes[u + n].scc);
    components[nodes[u + n].scc].negative.push_back(nodes[u].scc);
  }
  for (int u = 0; u < nn; ++u) {
    for (__typeof(nodes[u].adj.begin()) it = nodes[u].adj.begin();
         it != nodes[u].adj.end(); ++it) {
      int v = *it;
      if (nodes[u].scc != nodes[v].scc) {
        components[nodes[u].scc].adj.push_back(nodes[v].scc);
      }
    }
  }
  cnt = ncc;
  for (int i = 0; i < ncc; ++i)
    if (components[i].topo == -1) dfsTopo(i);
  topos.clear();
  for (int i = 0; i < ncc; ++i)
    topos.push_back(make_pair(components[i].topo, i));
  sort(topos.begin(), topos.end());
  for (int i = 0; i < ncc; ++i)
    if (components[i].value == -1) setValue(i, 1);
  int ret = 0;
  for (int i = 0; i < n; ++i)
    if (components[nodes[i].scc].value > 0) ret++;
  printf("%d\n", ret);
  for (int i = 0; i < n; ++i)
    if (components[nodes[i].scc].value > 0) printf("%d ", i + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  nn = n + n;
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    if (c == 0) {
      nodes[u + n].adj.push_back(v);
      nodes[v + n].adj.push_back(u);
      nodes[u].adj.push_back(v + n);
      nodes[v].adj.push_back(u + n);
    } else {
      nodes[u].adj.push_back(v);
      nodes[u + n].adj.push_back(v + n);
      nodes[v].adj.push_back(u);
      nodes[v + n].adj.push_back(u + n);
    }
  }
  bool solve = haveSolution();
  if (solve) {
    creatSolution();
  } else
    puts("Impossible");
  return 0;
}
