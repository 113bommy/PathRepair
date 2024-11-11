#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long x;
  long long y;
  Node(long long a, long long b) {
    x = a;
    y = b;
  }
};
bool cmp(Node A, Node B) {
  if (A.x != B.x) {
    return A.x < B.x;
  } else {
    return A.y < B.y;
  }
}
signed main() {
  long long x, y;
  vector<Node> nodes;
  cin >> x >> y;
  nodes.push_back(Node(x, y));
  cin >> x >> y;
  nodes.push_back(Node(x, y));
  cin >> x >> y;
  nodes.push_back(Node(x, y));
  vector<Node> ans;
  sort(nodes.begin(), nodes.end(), cmp);
  for (long long i = nodes[0].x; i <= nodes[1].x; i++) {
    ans.push_back(Node(i, nodes[0].y));
  }
  if (nodes[0].y < nodes[1].y) {
    for (long long i = nodes[0].y + 1; i <= nodes[1].y; i++) {
      ans.push_back(Node(nodes[1].x, i));
    }
  } else {
    for (long long i = nodes[1].y; i <= nodes[0].y - 1; i++) {
      ans.push_back(Node(nodes[1].x, i));
    }
  }
  if ((nodes[2].y >= nodes[1].y && nodes[2].y <= nodes[0].y) ||
      (nodes[2].y <= nodes[1].y && nodes[2].y >= nodes[0].y)) {
    for (long long i = nodes[1].x + 1; i <= nodes[2].x; i++) {
      ans.push_back(Node(i, nodes[2].y));
    }
  } else if ((nodes[2].y <= nodes[1].y && nodes[2].y <= nodes[0].y)) {
    for (long long i = nodes[1].x; i <= nodes[2].x; i++) {
      ans.push_back(Node(i, nodes[2].y));
    }
    for (long long i = nodes[2].y + 1; i <= min(nodes[1].y, nodes[0].y) - 1;
         i++) {
      ans.push_back(Node(nodes[2].x, i));
    }
  } else if ((nodes[2].y >= nodes[1].y && nodes[2].y >= nodes[0].y)) {
    for (long long i = nodes[1].x; i <= nodes[2].x; i++) {
      ans.push_back(Node(i, nodes[2].y));
    }
    for (long long i = max(nodes[1].y, nodes[0].y) + 1; i <= nodes[2].y - 1;
         i++) {
      ans.push_back(Node(nodes[2].x, i));
    }
  }
  cout << ans.size() << "\n";
  for (auto n : ans) {
    cout << n.x << " " << n.y << "\n";
  }
  return 0;
}
