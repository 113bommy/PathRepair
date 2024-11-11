#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
const int N = 1e4 + 5;
class edge {
 public:
  static int glnum;
  int v, to, flow, num;
  edge(int q, int w) {
    v = q;
    to = w;
    flow = 0;
    num = glnum++;
  }
};
int edge::glnum = 0;
vector<edge> A;
vector<int> g[N];
void add(int q, int w) {
  edge first = edge(q, w);
  edge second = edge(w, q);
  g[q].push_back(first.num);
  g[w].push_back(second.num);
  A.push_back(first);
  A.push_back(second);
}
int n, m;
int iter[N], d[N];
bool bfs(int s, int f) {
  for (int i = 0; i <= f; i++) {
    d[i] = inf;
  }
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); i++) {
      edge first = A[g[v][i]];
      if (first.flow > 0 && d[first.to] > d[v] + 1) {
        d[first.to] = d[v] + 1;
        q.push(first.to);
      }
    }
  }
  return (d[f] != inf);
}
int dfs(int v, int f, int flow) {
  if (v == f) {
    return flow;
  }
  for (int &i = iter[v]; i < g[v].size(); i++) {
    edge *first = &A[g[v][i]];
    edge *second = &A[g[v][i] ^ 1];
    if (d[first->to] == d[v] + 1) {
      int r = dfs(first->to, f, min(first->flow, flow));
      if (r > 0) {
        first->flow -= r;
        second->flow += r;
        return r;
      }
    }
  }
  return 0;
}
bool can(int first) {
  for (int i = 0; i < 6 * m; i += 2) {
    A[i].flow = 1;
    A[A[i].num ^ 1].flow = 0;
  }
  for (int i = 6 * m; i < A.size(); i += 2) {
    A[i].flow = first;
    A[A[i].num ^ 1].flow = 0;
  }
  int val = 0;
  while (bfs(0, m + n + 1)) {
    memset(iter, 0, sizeof(iter));
    while (int r = dfs(0, m + n + 1, inf)) {
      val += r;
    }
  }
  return (val == m);
}
int main() {
  cin >> n >> m;
  pair<int, int> a[m + 1];
  for (int i = 1; i <= m; i++) {
    add(0, i);
  }
  for (int i = 1; i <= m; i++) {
    int q, w;
    cin >> q >> w;
    a[i] = {q, w};
    add(i, m + q);
    add(i, m + w);
  }
  for (int i = 1; i <= n; i++) {
    add(m + i, n + m + 1);
  }
  int l = 1;
  int r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (can(l)) {
    cout << l << "\n";
    for (int i = 2 * m; i < 6 * m; i += 4) {
      if (A[i].flow == 1) {
        int first = (i - 2 * m) / 4;
        swap(a[first + 1].first, a[first + 1].second);
      }
    }
  } else if (can(r)) {
    cout << r << "\n";
    for (int i = 2 * m; i < 6 * m; i += 4) {
      if (A[i].flow == 1) {
        int first = (i - 2 * m) / 4;
        swap(a[first + 1].first, a[first + 1].second);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
