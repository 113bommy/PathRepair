#include <bits/stdc++.h>
struct solver {
  int mod, inv_10_mod_mod;
  int64_t ans;
  struct edge {
    int node, digit;
    bool constexpr operator==(edge e) const {
      return node == e.node and digit == e.digit;
    }
  };
  struct edge_hash {
    size_t operator()(edge e) const { return e.digit + 13 * (size_t)e.node; }
  };
  std::vector<std::unordered_set<edge, edge_hash>> adjl;
  solver(int nnode, int mod)
      : mod(mod), ans(), adjl(nnode), treeSizeResult(nnode) {
    int64_t one_MOD_mod = 1;
    while (one_MOD_mod % 10) one_MOD_mod += mod;
    inv_10_mod_mod = one_MOD_mod / 10;
  }
  void addEdge(int x, int y, int digit) {
    adjl[x].insert({y, digit});
    adjl[y].insert({x, digit});
  }
  std::vector<int> treeSizeResult;
  int treeSize(int node, int parent = -1) {
    int ans = 1;
    for (edge e : adjl[node])
      if (e.node != parent) ans += treeSize(e.node, node);
    return treeSizeResult[node] = ans;
  }
  int findCentroid(int node) {
    int componentSize = treeSize(node);
    int maxSTSize = (componentSize + 1) / 2;
    int centroid = node, parent = -1;
  continue_finding:
    for (edge e : adjl[centroid])
      if (e.node != parent)
        if (treeSizeResult[e.node] > maxSTSize) {
          parent = centroid;
          centroid = e.node;
          goto continue_finding;
        }
    return centroid;
  }
  std::unordered_map<int, int> upValuesCount, downValuesCount;
  std::vector<int> upValues, downValues;
  void findPathValues(int node, int parent, int selfUpValue, int selfDownValue,
                      int multiplier, int divider) {
    upValues.push_back(selfUpValue);
    downValues.push_back(selfDownValue);
    for (edge e : adjl[node])
      if (e.node != parent) {
        int childUpValue = (selfUpValue + e.digit * (int64_t)multiplier) % mod;
        int childDownValue = (selfDownValue + e.digit * (int64_t)divider) % mod;
        findPathValues(e.node, node, childUpValue, childDownValue,
                       multiplier * 10LL % mod,
                       divider * (int64_t)inv_10_mod_mod % mod);
      }
  }
  void solve(int node) {
    int const root = findCentroid(node);
    assert(std::cout << "solve(" << node << ") => root=" << root << '\n');
    if (adjl[root].empty()) return;
    upValuesCount.clear();
    downValuesCount.clear();
    for (edge e : adjl[root]) {
      assert(std::cout << "  branch " << e.node << "\n");
      upValues.clear();
      downValues.clear();
      findPathValues(e.node, root, e.digit,
                     e.digit * (int64_t)inv_10_mod_mod % mod, 10 % mod,
                     inv_10_mod_mod * (int64_t)inv_10_mod_mod % mod);
      for (int upv : upValues) {
        assert(std::cout << "    upv " << upv << '\n');
        auto it = downValuesCount.find((mod - upv) % mod);
        if (it != downValuesCount.end()) ans += it->second;
      }
      for (int downv : downValues) {
        assert(std::cout << "    downv " << downv << '\n');
        auto it = upValuesCount.find((mod - downv) % mod);
        if (it != upValuesCount.end()) ans += it->second;
      }
      for (int upv : upValues) ++upValuesCount[upv];
      for (int downv : downValues) ++downValuesCount[downv];
    }
    ans += upValuesCount[0];
    ans += downValuesCount[0];
    for (edge e : adjl[root]) {
      adjl[e.node].erase({root, e.digit});
      solve(e.node);
    }
    adjl[root].clear();
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int nnode, mod;
  std::cin >> nnode >> mod;
  solver s(nnode, mod);
  for (int i = nnode - 1; i-- > 0;) {
    int u, v, digit;
    std::cin >> u >> v >> digit;
    s.addEdge(u, v, digit % mod);
  }
  s.solve(0);
  std::cout << s.ans << '\n';
}
