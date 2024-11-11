#include <bits/stdc++.h>
using namespace std;
struct Node {
  int index;
  vector<pair<Node*, int>> nodes;
};
void calc(Node* to, Node* from, double beat) {
  double order = 2.0 / to->nodes.size();
  for (pair<Node*, int> child : to->nodes)
    if (child.first != from) {
      beat += order;
      while (beat >= 2.0) beat -= 2.0f;
      while (beat < 0.0) beat += 2.0;
      int a, b;
      if (beat < 1.0) {
        a = to->index;
        b = child.first->index;
      } else {
        a = child.first->index;
        b = to->index;
      }
      cout << "1 " << child.second << " " << a + 1 << " " << b + 1 << " "
           << (beat < 1.0 ? beat : beat - 1.0) << endl;
      calc(child.first, to, 1.0 - beat);
    }
}
int main() {
  int n;
  cin >> n;
  vector<Node> nodes(n);
  for (int i = 0; i < n; ++i) {
    nodes[i].index = i;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    nodes[u - 1].nodes.emplace_back(&nodes[v - 1], i);
    nodes[v - 1].nodes.emplace_back(&nodes[u - 1], i);
  }
  cout.precision(10);
  cout << n - 1 << endl;
  calc(&nodes[0], nullptr, 0.0);
}
