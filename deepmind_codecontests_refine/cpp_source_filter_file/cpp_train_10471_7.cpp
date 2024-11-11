#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int low[maxn], dfn[maxn];
int head[maxn], tot, scc[maxn];
int n, m, Index, ins[maxn], cnt;
int a[maxn];
stack<int> st;
struct Edge {
  int u, v, next;
} edge[maxn << 1];
vector<int> vec[maxn];
void init() {
  memset(head, -1, sizeof(head));
  tot = 1;
}
void add(int u, int v) {
  edge[++tot].u = u;
  edge[tot].v = v;
  edge[tot].next = head[u];
  head[u] = tot;
}
void tarjan(int u) {
  low[u] = dfn[u] = ++Index;
  ins[u] = 1;
  st.push(u);
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int to = edge[i].v;
    if (!dfn[to]) {
      tarjan(to);
      low[u] = min(low[u], low[to]);
    } else if (ins[to]) {
      low[u] = min(low[u], dfn[to]);
    }
  }
  if (low[u] == dfn[u]) {
    ++cnt;
    int v;
    do {
      v = st.top();
      ins[v] = 0;
      st.pop();
      scc[v] = cnt;
    } while (v != u);
  }
}
int sat() {
  for (int i = 1; i <= n; i++) {
    if (scc[i] == scc[i + n]) {
      return false;
    }
  }
  return true;
}
int main() {
  init();
  int x, y;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> y;
    for (int j = 1; j <= y; j++) {
      cin >> x;
      vec[x].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    int u = vec[i][0], v = vec[i][1];
    if (a[i]) {
      add(u, v);
      add(v, u);
      add(u + m, v + m);
      add(v + m, u + m);
    } else {
      add(u, v + m);
      add(v + m, u);
      add(u + m, v);
      add(v, u + m);
    }
  }
  for (int i = 1; i <= 2 * m; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  if (sat()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
