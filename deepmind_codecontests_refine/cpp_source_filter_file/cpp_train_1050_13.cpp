#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto i = begin(v); i != end(v); i++)
    os << *i << (i == end(v) - 1 ? "" : " ");
  return os;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto i = begin(v); i != end(v); i++) is >> *i;
  return is;
}
struct DsuNode {
  int parent_id;
  int node_cnt = 1;
  int edge_cnt = 0;
};
class Dsu {
 private:
  vector<DsuNode> nodes;
  vector<int> tmp_stack;

 public:
  Dsu(const int cnt) {
    nodes.resize(cnt);
    for (int i = 0; i < cnt; i++) nodes[i].parent_id = i;
  }
  int find_id(int id) {
    if (nodes[id].parent_id == id) return id;
    return (nodes[id].parent_id = find_id(nodes[id].parent_id));
  }
  DsuNode& find(const int id) { return nodes[find_id(id)]; }
  bool are_same(const int a, const int b) { return find_id(a) == find_id(b); }
  void join(int a, int b) {
    a = find_id(a);
    b = find_id(b);
    if (a != b) {
      if (nodes[a].node_cnt < nodes[b].node_cnt) swap(a, b);
      nodes[b].parent_id = a;
      nodes[a].node_cnt += nodes[b].node_cnt;
      nodes[a].edge_cnt += nodes[b].edge_cnt;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > pairs;
  vector<int> days;
  for (int i = 0; i < n; i++) {
    int aa, bb;
    scanf("%d %d", &aa, &bb);
    pairs.push_back({aa, bb});
    days.push_back(aa);
    days.push_back(bb);
  }
  sort((days).begin(), (days).end());
  (days).erase(unique((days).begin(), (days).end()), (days).end());
  map<int, int> day_to_id;
  for (int i = 0; i < days.size(); i++) day_to_id[days[i]] = i;
  for (auto& x : pairs) {
    x.first = day_to_id[x.first];
    x.second = day_to_id[x.second];
  }
  Dsu dsu(days.size());
  int max_left = 0;
  for (auto x : pairs) {
    dsu.find(x.first).edge_cnt++;
    max_left = max(x.first, max_left);
  }
  int bad_cases = 0;
  for (int i = 0; i < days.size(); i++) {
    bad_cases += dsu.find(i).edge_cnt > dsu.find(i).node_cnt;
  }
  sort((pairs).begin(), (pairs).end(),
       [&](pair<int, int>& a, pair<int, int>& b) {
         return a.second < b.second;
       });
  if (bad_cases == 0) {
    cout << days[max_left];
    return 0;
  }
  for (auto x : pairs) {
    auto& xf = dsu.find(x.first);
    auto& xs = dsu.find(x.second);
    if (dsu.are_same(x.first, x.second)) continue;
    bad_cases -= xf.edge_cnt > xs.node_cnt;
    bad_cases -= xs.edge_cnt > xs.node_cnt;
    dsu.join(x.first, x.second);
    bad_cases += dsu.find(x.first).edge_cnt > dsu.find(x.first).node_cnt;
    max_left = max(max_left, x.second);
    if (bad_cases == 0) {
      cout << days[max_left];
      return 0;
    }
  }
  cout << -1;
  return 0;
}
