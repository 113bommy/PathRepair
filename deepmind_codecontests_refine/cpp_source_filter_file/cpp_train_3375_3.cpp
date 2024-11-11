#include <bits/stdc++.h>
using namespace std;
struct Query {
  int v, k, result;
};
struct Tree {
  int n;
  vector<vector<int> > conn;
  vector<int> colors;
  vector<vector<Query*> > queries;
  Tree(vector<int> ncolors) {
    colors = ncolors;
    n = colors.size();
    conn.resize(n);
    queries.resize(n);
  }
  void addEdge(int a, int b) {
    conn[a].push_back(b);
    conn[b].push_back(a);
  }
  void addQuery(int pos, Query* query) { queries[pos].push_back(query); }
  struct State {
    map<int, int> colorCount;
    vector<int> smallCount, colors, largeCount;
    static const int BLOCK = 400;
    int size;
    State() {
      smallCount.resize(BLOCK, 0);
      size = 0;
    }
    void addColor(int col) {
      colors.push_back(col);
      if (colorCount.count(col) == 0) colorCount[col] = 0;
      int cnt = colorCount[col]++;
      if (cnt < BLOCK) {
        smallCount[cnt]--;
        if (cnt + 1 >= BLOCK)
          largeCount.push_back(cnt + 1);
        else
          smallCount[cnt + 1]++;
      } else {
        *(upper_bound(largeCount.rbegin(), largeCount.rend(), cnt) + 1)++;
      }
      size++;
    }
    void integrate(State& r) {
      for (auto c : r.colors) addColor(c);
    }
    int report(int cnt) {
      int result = 0;
      for (int i = cnt; i < BLOCK; i++) result += smallCount[i];
      return result + (largeCount.rend() - lower_bound(largeCount.rbegin(),
                                                       largeCount.rend(), cnt));
    }
  };
  State* solve(int pos = 0, int prev = -1) {
    State* state = new State;
    state->addColor(colors[pos]);
    for (int next : conn[pos])
      if (next != prev) {
        State* other = solve(next, pos);
        if (state->size < other->size) swap(state, other);
        state->integrate(*other);
        delete other;
      }
    for (Query* query : queries[pos]) query->result = state->report(query->k);
    return state;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  Tree* t;
  {
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    t = new Tree(c);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    t->addEdge(u - 1, v - 1);
  }
  vector<Query> queries(m);
  for (int i = 0; i < m; i++) {
    cin >> queries[i].v >> queries[i].k;
    queries[i].v--;
    t->addQuery(queries[i].v, &queries[i]);
  }
  t->solve();
  for (Query& query : queries) cout << query.result << '\n';
  return 0;
}
