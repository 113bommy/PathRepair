#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, w;
  bool operator<(const edge &o) const { return w < o.w; }
};
struct query {
  int index, weight;
  vector<int> edgeIds;
  query(int index) : index(index) {}
  bool operator<(const query &o) const { return weight < o.weight; }
};
struct DSU {
  vector<int> Par, Rank;
  vector<tuple<int, int, int>> changes;
  DSU(int n) {
    Par.assign(n + 5, 0);
    Rank.assign(n + 5, 0);
  }
  int findSet(int u) { return Par[u] ? findSet(Par[u]) : u; }
  bool unionSet(int u, int v, bool needRoll) {
    u = findSet(u);
    v = findSet(v);
    if (u == v) return false;
    if (Rank[u] == Rank[v]) {
      if (needRoll) changes.emplace_back(u, Par[u], Rank[u]);
      Rank[u]++;
    }
    if (Rank[u] > Rank[v]) {
      if (needRoll) changes.emplace_back(v, Par[v], Rank[v]);
      Par[v] = u;
    } else {
      if (needRoll) changes.emplace_back(u, Par[u], Rank[u]);
      Par[u] = v;
    }
    return true;
  }
  void rollBack() {
    int u, par, rank;
    while (changes.size()) {
      tie(u, par, rank) = changes.back();
      changes.pop_back();
      Par[u] = par;
      Rank[u] = rank;
    }
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<edge> edges(m);
  for (edge &e : edges) cin >> e.u >> e.v >> e.w;
  auto cmp = [&](int i, int j) { return edges[i].w < edges[j].w; };
  vector<edge> sorted = edges;
  sort(sorted.begin(), sorted.end());
  int q;
  DSU dsu(n);
  cin >> q;
  vector<char> answer(q, 1);
  vector<query> queries;
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    vector<int> edgeIds(k);
    for (int &id : edgeIds) {
      cin >> id;
      id--;
    }
    sort(edgeIds.begin(), edgeIds.end(), cmp);
    for (int x = 0; x < int(edgeIds.size()); x++) {
      int y = x;
      queries.emplace_back((i));
      queries.back().weight = edges[edgeIds[x]].w;
      while (y < int(edgeIds.size()) &&
             edges[edgeIds[y]].w == edges[edgeIds[x]].w)
        queries.back().edgeIds.emplace_back(edgeIds[y++]);
      x = y;
    }
  }
  sort(queries.begin(), queries.end());
  int last = 0;
  for (const auto &que : queries) {
    while (last < m && sorted[last].w < que.weight) {
      dsu.unionSet(sorted[last].u, sorted[last].v, 0);
      last++;
    }
    for (int id : que.edgeIds)
      if (!dsu.unionSet(edges[id].u, edges[id].v, 1)) answer[que.index] = false;
    dsu.rollBack();
  }
  for (int i = 0; i < q; i++) cout << (answer[i] ? "YES" : "NO") << '\n';
}
