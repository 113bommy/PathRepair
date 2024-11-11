#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vvvpii = vector<vvpii>;
struct UnionFind {
  const int V;
  vector<int> par, rank, cnt;
  UnionFind(int V) : V(V), par(V), rank(V), cnt(V) { init(); }
  void init() {
    for (int i = 0; i < V; i++) par[i] = i;
    fill(rank.begin(), rank.end(), 0);
    fill(cnt.begin(), cnt.end(), 1);
  }
  int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
  bool unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    cnt[y] = cnt[x] = cnt[x] + cnt[y];
    if (rank[x] < rank[y])
      par[x] = y;
    else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int count(int x) { return cnt[find(x)]; }
};
struct Kruskal {
  struct edge {
    int u, v, cost;
    bool operator<(const edge& right) const { return cost < right.cost; }
  };
  UnionFind uf;
  vector<edge> es;
  Kruskal(int V) : uf(V) {}
  void add_edge(int u, int v, int cost) { es.push_back((edge){u, v, cost}); }
  long long kruskal() {
    int E = (int)es.size();
    sort(es.begin(), es.end());
    long long ret = 0;
    for (int i = 0; i < E; i++) {
      edge& e = es[i];
      if (!uf.same(e.u, e.v)) {
        uf.unite(e.u, e.v);
        ret += e.cost;
      }
    }
    return ret;
  }
};
void Main() {
  int N, M;
  scanf("%d%d", &N, &M);
  vvi E(N);
  for (int i = int(0); i < int(M); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  int S, T, Ds, Dt;
  scanf("%d%d%d%d", &S, &T, &Ds, &Dt);
  S--;
  T--;
  bool st = 0;
  for (auto&& v : E[S])
    if (v == T) {
      st = 1;
      break;
    }
  vpii ans;
  UnionFind uf(N);
  if (st) {
    UnionFind uf(N);
    for (int u = int(0); u < int(N); ++u)
      for (auto&& v : E[u]) {
        if (u == S && v == T) continue;
        if (u == T && v == S) continue;
        uf.unite(u, v);
      }
    if (uf.same(S, T)) {
      E[S].erase(remove(E[S].begin(), E[S].end(), T), E[S].end());
      E[T].erase(remove(E[T].begin(), E[T].end(), S), E[T].end());
    } else {
      uf.unite(S, T);
      ans.emplace_back(S, T);
      Ds--;
      Dt--;
    }
  }
  for (int u = int(0); u < int(N); ++u)
    if (u != S && u != T) {
      for (auto&& v : E[u])
        if (v != S && v != T) {
          if (!uf.same(u, v)) {
            uf.unite(u, v);
            ans.emplace_back(u, v);
          }
        }
    }
  set<int> ss, tt;
  for (auto&& v : E[S]) {
    if (uf.same(S, v)) continue;
    if (uf.same(T, v)) continue;
    ss.insert(uf.find(v));
  }
  for (auto&& v : E[T]) {
    if (uf.same(S, v)) continue;
    if (uf.same(T, v)) continue;
    tt.insert(uf.find(v));
  }
  for (auto&& v : E[S]) {
    if (uf.same(S, v)) continue;
    if (uf.same(T, v)) continue;
    if (tt.count(v)) {
    } else {
      uf.unite(S, v);
      ans.emplace_back(S, v);
      Ds--;
    }
  }
  for (auto&& v : E[T]) {
    if (uf.same(S, v)) continue;
    if (uf.same(T, v)) continue;
    if (ss.count(v)) {
    } else {
      uf.unite(T, v);
      ans.emplace_back(T, v);
      Dt--;
    }
  }
  for (auto&& v : E[S]) {
    if (uf.same(S, v)) continue;
    if (uf.same(T, v)) continue;
    if (Ds > Dt) {
      uf.unite(S, v);
      ans.emplace_back(S, v);
      Ds--;
    } else {
      uf.unite(T, v);
      ans.emplace_back(T, v);
      Dt--;
    }
  }
  if (!uf.same(S, T)) {
    vi st;
    if (Ds > Dt) {
      st = {S, T};
    } else {
      st = {T, S};
    }
    for (auto&& u : st) {
      for (auto&& v : E[u]) {
        if (uf.same(u, v)) continue;
        uf.unite(u, v);
        ans.emplace_back(u, v);
        if (u == S)
          Ds--;
        else
          Dt--;
        break;
      }
    }
  }
  if (Ds < 0 || Dt < 0) {
    puts("No");
    return;
  }
  if (!uf.same(S, T)) {
    puts("No");
    return;
  }
  puts("Yes");
  for (auto&& uv : ans) {
    (void)printf("%d %d\n", uv.first + 1, uv.second + 1);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  Main();
  return 0;
}
