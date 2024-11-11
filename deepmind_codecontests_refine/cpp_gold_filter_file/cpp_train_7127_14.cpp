#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
struct edge {
  int u;
  int w;
  int flow;
  int capacity;
  int cost;
  char wha;
  edge() = default;
  edge(int a, int b, int cap, char c) {
    u = a;
    w = b;
    flow = 0;
    capacity = cap;
    cost = 0;
    wha = c;
  }
};
vector<int> dawey(int start, int end, vector<vector<int>> &vert,
                  vector<edge> &edges) {
  vector<int> d(vert.size(), INF);
  d[start] = 0;
  vector<int> p(vert.size(), -1);
  for (;;) {
    bool any = false;
    for (auto &edge : edges) {
      if (edge.capacity - edge.flow == 0) continue;
      if (d[edge.u] < INF)
        if (d[edge.w] > d[edge.u] + edge.cost) {
          d[edge.w] = d[edge.u] + edge.cost;
          p[edge.w] = edge.u;
          any = true;
        }
    }
    if (!any) break;
  }
  vector<int> ans;
  if (d[end] == INF) return ans;
  for (int cur = end; cur != -1; cur = p[cur]) ans.push_back(cur);
  reverse(ans.begin(), ans.end());
  return ans;
}
void doaction(vector<int> &path, vector<vector<int>> &vert, vector<edge> &edges,
              map<pair<int, int>, int> &vedge) {
  for (int i = 0; i < path.size() - 1; i++) {
    edges[vedge[{path[i], path[i + 1]}]].flow += 1;
    edges[vedge[{path[i + 1], path[i]}]].flow -= 1;
  }
}
int main() {
  int n, k;
  string a, b;
  cin >> n >> k;
  cin >> a >> b;
  vector<vector<int>> vert(2 * k + 2);
  vector<edge> edges;
  map<pair<int, int>, int> vedge;
  vector<char> letters;
  map<char, int> letint;
  for (int i = 'a'; i <= 'z'; i++) {
    letters.push_back(i);
    letint[i] = letters.size() - 1;
  }
  for (int i = 'A'; i <= 'Z'; i++) {
    letters.push_back(i);
    letint[i] = letters.size() - 1;
  }
  letters.resize(k);
  for (int u = 0; u < k; u++) {
    for (int v = 0; v < k; v++) {
      edges.emplace_back(u, v + k, 1, letters[v]);
      vert[u].push_back(edges.size() - 1);
      vedge[{u, v + k}] = edges.size() - 1;
      edges.emplace_back(v + k, u, 0, letters[u]);
      vert[v + k].push_back(edges.size() - 1);
      vedge[{v + k, u}] = edges.size() - 1;
    }
  }
  for (int i = 0; i < k; i++) {
    edges.emplace_back(2 * k, i, 1, letters[i]);
    vert[2 * k].push_back(edges.size() - 1);
    vedge[{2 * k, i}] = edges.size() - 1;
    edges.emplace_back(i, 2 * k, 0, 0);
    vert[i].push_back(edges.size() - 1);
    vedge[{i, 2 * k}] = edges.size() - 1;
  }
  for (int i = 0; i < k; i++) {
    edges.emplace_back(i + k, 2 * k + 1, 1, letters[i]);
    vert[i + k].push_back(edges.size() - 1);
    vedge[{i + k, 2 * k + 1}] = edges.size() - 1;
    edges.emplace_back(2 * k + 1, i + k, 0, 0);
    vert[2 * k + 1].push_back(edges.size() - 1);
    vedge[{2 * k + 1, i + k}] = edges.size() - 1;
  }
  for (int i = 0; i < a.length(); i++) {
    edges[vedge[{letint[a[i]], letint[b[i]] + k}]].cost -= 1;
    edges[vedge[{letint[b[i]] + k, letint[a[i]]}]].cost += 1;
  }
  for (int i = 0; i < k; i++) {
    auto p = dawey(2 * k, 2 * k + 1, vert, edges);
    doaction(p, vert, edges, vedge);
  }
  int count = 0;
  vector<char> ans;
  for (int i = 0; i < k; i++) {
    for (auto &e : vert[i]) {
      if (edges[e].flow == 1) {
        ans.push_back(edges[e].wha);
        count += edges[e].cost;
        break;
      }
    }
  }
  cout << -count << endl;
  for (auto &i : ans) {
    cout << i;
  }
  cout << endl;
  return 0;
}
