#include <bits/stdc++.h>
using namespace std;
struct Solver {
  vector<int> parent;
  vector<vector<int>> children;
  vector<int> mask;
  vector<int> in, out;
  vector<vector<pair<int, int>>> parity;
  int test_count;
  int timer = 0;
  void Read() {
    int len;
    cin >> len >> test_count;
    parent.resize(len, -1);
    children.resize(len);
    mask.resize(len);
    in.resize(len);
    out.resize(len);
    for (int i = 1; i < len; ++i) {
      int p;
      cin >> p;
      parent[i] = p - 1;
      children[p - 1].push_back(i);
    }
    for (int i = 0; i < len; ++i) {
      char c;
      cin >> c;
      mask[i] = 1 << (c - 'a');
    }
  }
  void Dfs(int node, int depth) {
    in[node] = ++timer;
    if (parity.size() == depth) {
      parity.push_back(vector<pair<int, int>>(1));
    }
    parity[depth].push_back(
        {in[node], parity[depth].back().second ^ mask[node]});
    for (int w : children[node]) {
      Dfs(w, depth + 1);
    }
    out[node] = ++timer;
  }
  bool Query(int node, int depth) {
    if (depth >= parity.size()) {
      return false;
    }
    auto&& p = parity[depth];
    int l = distance(p.begin(),
                     lower_bound(p.begin(), p.end(), make_pair(in[node], -1))) -
            1;
    int r = distance(p.begin(), lower_bound(p.begin(), p.end(),
                                            make_pair(out[node], -1))) -
            1;
    int t = p[r].second ^ p[l].second;
    return t - (t & -t);
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  auto s = Solver{};
  s.Read();
  s.Dfs(0, 0);
  for (int q = 0; q < s.test_count; ++q) {
    int v, d;
    cin >> v >> d;
    --v;
    --d;
    cout << (s.Query(v, d) ? "Yes" : "No") << endl;
  }
  return 0;
}
