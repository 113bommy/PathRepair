#include <bits/stdc++.h>
template <typename T>
void pMin(T& a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void pMax(T& a, T b) {
  if (b > a) {
    a = b;
  }
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c);
template <typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& c) {
  std::cout << "(" << c.first << ", " << c.second << ")";
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c) {
  if (c.size() == 0) {
    os << "{}";
    return os;
  }
  os << "{" << c[0];
  for (int64_t i = 1; i < (int64_t)c.size(); i++) {
    os << ", " << c[i];
  }
  os << "}";
  return os;
}
const int64_t inf = 2e9;
using namespace std;
int64_t curr = -1;
struct Node;
vector<Node> nodes;
vector<vector<pair<int64_t, int64_t>>> adj;
struct Node {
  Node *left, *right;
  int64_t l, r, m;
  int64_t ind;
  Node() {}
  void init(int64_t lb, int64_t rb, bool goingUp, int64_t pa = -1) {
    ind = curr;
    l = lb;
    r = rb;
    if (goingUp && pa != -1) {
      adj[ind].push_back({pa, 0});
    }
    if (l != r) {
      m = (l + r) / 2;
      if (!goingUp) adj[ind].push_back({curr + 1, 0});
      left = &nodes[++curr];
      left->init(l, m, goingUp, ind);
      if (!goingUp) adj[ind].push_back({curr + 1, 0});
      right = &nodes[++curr];
      right->init(m + 1, r, goingUp, ind);
    }
  }
  int64_t getInd(int64_t x) {
    if (l == r) return ind;
    return (x <= m ? left : right)->getInd(x);
  }
  void addEdgeTo(int64_t lb, int64_t rb, int64_t from, int64_t w) {
    if (lb <= l && rb >= r) {
      adj[from].push_back({ind, w});
    } else if (lb > rb || lb > r || rb < l) {
      return;
    } else {
      left->addEdgeTo(lb, rb, from, w);
      right->addEdgeTo(lb, rb, from, w);
    }
  }
  void addEdgeFrom(int64_t lb, int64_t rb, int64_t to, int64_t w) {
    if (lb <= l && rb >= r) {
      adj[ind].push_back({to, w});
    } else if (lb > rb || lb > r || rb < l) {
      return;
    } else {
      left->addEdgeFrom(lb, rb, to, w);
      right->addEdgeFrom(lb, rb, to, w);
    }
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t n, q, start;
  cin >> n >> q >> start;
  nodes.resize(8 * n);
  adj.resize(8 * n);
  Node* leftTree = &nodes[++curr];
  leftTree->init(1, n, false);
  Node* rightTree = &nodes[++curr];
  rightTree->init(1, n, true);
  for (int64_t i = 1; i <= n; i++) {
    int64_t l = leftTree->getInd(i), r = rightTree->getInd(i);
    adj[l].push_back({r, 0});
    adj[r].push_back({l, 0});
  }
  for (int64_t i = 0; i < q; i++) {
    int64_t type;
    cin >> type;
    if (type == 1) {
      int64_t a, b, w;
      cin >> a >> b >> w;
      adj[leftTree->getInd(a)].push_back({leftTree->getInd(b), w});
      adj[rightTree->getInd(a)].push_back({rightTree->getInd(b), w});
    } else if (type == 2) {
      int64_t a, l, r, w;
      cin >> a >> l >> r >> w;
      int64_t from = rightTree->getInd(a);
      leftTree->addEdgeTo(l, r, from, w);
    } else if (type == 3) {
      int64_t b, l, r, w;
      cin >> b >> l >> r >> w;
      int64_t to = leftTree->getInd(b);
      rightTree->addEdgeFrom(l, r, to, w);
    }
  }
  vector<int64_t> seen(8 * n + 1, inf);
  priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>,
                 greater<pair<int64_t, int64_t>>>
      pq;
  pq.push({0, leftTree->getInd(start)});
  seen[pq.top().second] = 0;
  while (pq.size()) {
    auto curr = pq.top();
    pq.pop();
    for (pair<int64_t, int64_t> pi : adj[curr.second]) {
      if (pi.second + curr.first < seen[pi.first]) {
        seen[pi.first] = pi.second + curr.first;
        pq.push({pi.second + curr.first, pi.first});
      }
    }
  }
  for (int64_t i = 1; i <= n; i++) {
    int64_t val = min(seen[leftTree->getInd(i)], seen[rightTree->getInd(i)]);
    cout << (val == inf ? -1 : val) << " \n"[i == n];
  }
  return 0;
}
