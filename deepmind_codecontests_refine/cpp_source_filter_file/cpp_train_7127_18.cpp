#include <bits/stdc++.h>
using namespace std;
int const inf = (1 << 30) - 1;
int const maxn = 4 * (55 + 55);
struct Edge {
  int from, to, cap, flow, cost;
  Edge(int _from, int _to, int _cap, int _flow, int _cost) {
    from = _from;
    to = _to;
    cap = _cap;
    flow = _flow;
    cost = _cost;
  }
  Edge() {}
};
Edge E[2 * (maxn * maxn + maxn + maxn)];
vector<int> g[maxn];
int n, k;
char second[2123456], t[212345];
map<pair<char, char>, int> M;
map<char, char> T;
int d[maxn], flow[maxn], from[maxn], ID[maxn];
int phi[maxn];
int en;
bool DJ(int end) {
  for (int i = 0; i <= end; i++) d[i] = inf;
  for (int i = 0; i <= end; i++) flow[i] = 0;
  for (int i = 0; i <= end; i++) from[i] = ID[i] = -1;
  flow[0] = inf;
  d[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  pq.push(make_pair(d[0], 0));
  while (!pq.empty()) {
    pair<int, int> temp = pq.top();
    pq.pop();
    int val = temp.first;
    int u = temp.second;
    if (val > d[u]) continue;
    for (typeof(g[u].begin()) it = g[u].begin(); it != g[u].end(); it++) {
      int id = *it;
      int v = E[id].to;
      int cost = E[id].cost;
      if (E[id].cap - E[id].flow > 0 && d[u] + cost + phi[u] - phi[v] < d[v]) {
        flow[v] = min(flow[u], E[id].cap - E[id].flow);
        d[v] = d[u] + cost + phi[u] - phi[v];
        ID[v] = id;
        from[v] = u;
        pq.push(make_pair(d[v], v));
      }
    }
  }
  for (int i = 0; i <= end; i++) phi[i] += d[i];
  return flow[end] > 0;
}
void addEdge(int from, int to, int cap, int flow, int cost) {
  E[en++] = Edge(from, to, cap, flow, cost);
  g[from].push_back(en - 1);
  E[en++] = Edge(to, from, 0, -flow, -cost);
  g[to].push_back(en - 1);
}
void Solve() {
  en = 0;
  scanf("%d%d\n", &n, &k);
  scanf("%s\n", second);
  scanf("%s\n", t);
  for (int i = 0; i < n; i++) {
    M[make_pair(second[i], t[i])]--;
  }
  vector<char> v;
  for (int i = 0; i < 26; i++) {
    v.push_back(char(i + 'a'));
  }
  for (int i = 0; i < 26; i++) {
    v.push_back(char(i + 'A'));
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      addEdge(i + 1, k + 1 + j, 1, 0, M[make_pair(v[i], v[j])]);
    }
    addEdge(0, i + 1, 1, 0, 0);
    addEdge(i + 1 + k, k + k + 1, 1, 0, 0);
  }
  int end = k + k + 1;
  while (DJ(end)) {
    int v = end;
    while (v != 0) {
      int u = from[v];
      int id = ID[v];
      E[id].flow += flow[end];
      E[id ^ 1].flow -= flow[end];
      v = u;
    }
  }
  int ans = 0;
  for (int i = 0; i < en; i++) {
    if (E[i].flow > 0 && E[i].from != 0 && E[i].to != end) {
      ans += E[i].cost;
      int from = E[i].from;
      int to = E[i].to;
      char aa = v[from - 1];
      char bb = v[to - k - 1];
      T[aa] = bb;
    }
  }
  printf("%d\n", -ans);
  for (int i = 0; i < k; i++) {
    cout << T[v[i]];
  }
  cout << endl;
}
int main() {
  Solve();
  return 0;
}
