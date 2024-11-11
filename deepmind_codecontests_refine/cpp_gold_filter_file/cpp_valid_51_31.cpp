#include <bits/stdc++.h>
using namespace std;
struct dsu {
  vector<int> id;
  dsu() {}
  dsu(int n) { id = vector<int>(n, -1); }
  int find(int a) {
    while (id[a] >= 0) {
      if (id[id[a]] >= 0) id[a] = id[id[a]];
      a = id[a];
    }
    return a;
  }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (id[a] > id[b]) {
      swap(a, b);
    }
    id[a] += id[b];
    id[b] = a;
    return true;
  }
};
struct GroundSetElement {
  int x, y;
  int id;
  int cost;
  bool in_independent_set = false;
  int independent_set_position = -1;
  int parent = -1;
  GroundSetElement(int a, int b, int c) {
    x = a;
    y = b;
    cost = c;
  }
};
int n;
vector<GroundSetElement> ground_set;
vector<int> independent_set;
vector<int> d;
vector<int> limit;
dsu g1;
vector<pair<int, int>> other;
vector<dsu> if_rem;
bool graphic_matroid_oracle(int inserted) {
  const auto &e = ground_set[inserted];
  return g1.find(e.x) != g1.find(e.y);
}
bool graphic_matroid_oracle(int inserted, int removed) {
  const auto &e = ground_set[inserted];
  return if_rem[removed].find(e.x) != if_rem[removed].find(e.y);
}
bool matroid2_oracle(int inserted) {
  const auto &ei = ground_set[inserted];
  return d[ei.x] + 1 <= limit[ei.x] && d[ei.y] + 1 <= limit[ei.y];
}
bool matroid2_oracle(int inserted, int removed) {
  const auto &er = ground_set[removed];
  const auto &ei = ground_set[inserted];
  int degx = d[ei.x] + 1;
  int degy = d[ei.y] + 1;
  if (ei.x == er.x || ei.x == er.y) degx--;
  if (ei.y == er.x || ei.y == er.y) degy--;
  return degx <= limit[ei.x] && degy <= limit[ei.y];
}
void prepare_oracle1() {
  g1 = dsu(n);
  for (const auto &[x, y] : other) {
    g1.unite(x, y);
  }
  for (int id : independent_set) {
    const auto &e = ground_set[id];
    g1.unite(e.x, e.y);
  }
  if_rem.assign(ground_set.size(), dsu());
  for (int id : independent_set) {
    if_rem[id] = dsu(n);
    for (const auto &[x, y] : other) {
      if_rem[id].unite(x, y);
    }
    for (int id2 : independent_set) {
      if (id == id2) continue;
      const auto &e2 = ground_set[id2];
      if_rem[id].unite(e2.x, e2.y);
    }
  }
}
void prepare_oracle2() {
  d.assign(n, 0);
  for (int id : independent_set) {
    const auto &e = ground_set[id];
    d[e.x]++;
    d[e.y]++;
  }
}
bool augment() {
  prepare_oracle1();
  prepare_oracle2();
  const int SOURCE = -1;
  const int NOT_FOUND = -2;
  for (int i = 0; i < (int)ground_set.size(); i++) {
    ground_set[i].parent = -1;
  }
  int endpoint = NOT_FOUND;
  const int INF = 1e9 + 5;
  vector<pair<int, int>> dist(ground_set.size(), make_pair(INF, INF));
  for (int i = 0; i < (int)ground_set.size(); i++) {
    if (!ground_set[i].in_independent_set && graphic_matroid_oracle(i)) {
      ground_set[i].parent = SOURCE;
      dist[i] = {ground_set[i].cost, 0};
    }
  }
  vector<vector<int>> adj(ground_set.size());
  for (int i : independent_set) {
    for (int j = 0; j < (int)ground_set.size(); j++) {
      if (ground_set[j].in_independent_set) continue;
      if (graphic_matroid_oracle(j, i)) {
        adj[i].push_back(j);
      }
      if (matroid2_oracle(j, i)) {
        adj[j].push_back(i);
      }
    }
  }
  bool go = true;
  for (int rep = 0; go; rep++) {
    go = false;
    vector<pair<int, int>> ndist = dist;
    for (int i = 0; i < (int)ground_set.size(); i++) {
      for (int j : adj[i]) {
        assert(ground_set[i].in_independent_set !=
               ground_set[j].in_independent_set);
        int c;
        if (ground_set[j].in_independent_set) {
          c = -ground_set[j].cost;
        } else {
          c = ground_set[j].cost;
        }
        if (dist[i].first != INF) {
          pair<int, int> ncost = {dist[i].first + c, dist[i].second + 1};
          if (ncost < ndist[j]) {
            go = true;
            ndist[j] = ncost;
            ground_set[j].parent = i;
          }
        }
      }
    }
    dist.swap(ndist);
    if (rep == (int)ground_set.size() - 1) assert(!go);
  }
  pair<int, int> best = {INF, INF};
  for (int i = 0; i < (int)ground_set.size(); i++) {
    if (!ground_set[i].in_independent_set && dist[i] < best &&
        matroid2_oracle(i)) {
      endpoint = i;
      best = dist[i];
    }
  }
  if (endpoint == NOT_FOUND) return false;
  do {
    ground_set[endpoint].in_independent_set ^= true;
    endpoint = ground_set[endpoint].parent;
  } while (endpoint != SOURCE);
  independent_set.clear();
  for (int i = 0; i < (int)ground_set.size(); i++) {
    if (ground_set[i].in_independent_set) {
      ground_set[i].independent_set_position = independent_set.size();
      independent_set.push_back(i);
    }
  }
  return true;
}
void foo() {
  int k;
  cin >> n >> k;
  vector<int> L(k);
  for (int i = 0; i < k; i++) {
    cin >> L[i];
  }
  vector<vector<int>> c(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> c[i][j];
    }
  }
  vector<pair<int, int>> mst, all;
  for (int i = k; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      all.emplace_back(i, j);
    }
  }
  sort(all.begin(), all.end(),
       [&](const pair<int, int> &e1, const pair<int, int> &e2) {
         return c[e1.first][e1.second] < c[e2.first][e2.second];
       });
  dsu g(n);
  for (const auto &e : all) {
    if (g.unite(e.first, e.second)) {
      mst.push_back(e);
    }
  }
  const int INF = 1e9 + 5;
  int ans = INF;
  limit = vector<int>(n, INF);
  function<void(int, vector<pair<int, int>> &)> rec =
      [&](int v, const vector<pair<int, int>> &edges) {
        if (v == k) {
          vector<int> al(k);
          for (const auto &[x, y] : edges) {
            al[x]++;
            al[y]++;
          }
          for (int i = 0; i < k; i++) {
            if (al[i] > L[i]) return;
            limit[i] = L[i] - al[i];
          }
          other = edges;
          ground_set.clear();
          independent_set.clear();
          for (const auto &[x, y] : mst) {
            ground_set.emplace_back(x, y, c[x][y]);
          }
          for (int i = 0; i < k; i++) {
            for (int j = k; j < n; j++) {
              ground_set.emplace_back(i, j, c[i][j]);
            }
          }
          while (augment())
            ;
          const int cnt = edges.size() + independent_set.size();
          if (cnt == n - 1) {
            int sum = 0;
            for (const auto &[x, y] : edges) {
              sum += c[x][y];
            }
            for (int id : independent_set) {
              sum += ground_set[id].cost;
            }
            ans = min(ans, sum);
          }
          return;
        }
        const int cases = 1 << v;
        for (int m = 0; m < cases; m++) {
          dsu G(k);
          for (const auto &[x, y] : edges) {
            G.unite(x, y);
          }
          bool good = true;
          vector<pair<int, int>> ne = edges;
          for (int i = 0; i < v; i++) {
            if (!(m & (1 << i))) continue;
            if (G.find(i) == G.find(v)) {
              good = false;
              break;
            }
            ne.emplace_back(i, v);
            G.unite(i, v);
          }
          if (good) {
            rec(v + 1, ne);
          }
        }
      };
  vector<pair<int, int>> vv;
  rec(0, vv);
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
}
