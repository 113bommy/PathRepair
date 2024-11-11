#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 100;
const long long limit = 1e17;
struct Node {
  long long x, y;
  Node(long long X, long long Y) {
    x = X;
    y = Y;
  }
};
vector<Node> node;
long long dis(Node a, Node b) { return llabs(a.x - b.x) + llabs(a.y - b.y); }
int main() {
  long long x0, y0, ax, ay, bx, by, xs, ys, t;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  long long x = x0, y = y0;
  Node start = Node(xs, ys);
  while (x <= limit && y <= limit) {
    node.push_back(Node(x, y));
    x = x * ax + bx, y = y * ay + by;
  }
  long long min_dis = 0x3f3f3f3f3f3f3f3f;
  int ans = 0;
  for (int st = 0; st < node.size(); st++)
    for (int ed = 0; ed < node.size(); ed++) {
      if (dis(node[st], node[ed]) + dis(start, node[st]) <= t)
        ans = max(ans, abs(st - ed) + 1);
    }
  printf("%d\n", ans);
  return 0;
}
