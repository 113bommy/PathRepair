#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int INF = 0x3f3f3f3f;
long long mod = 1e9 + 7;
struct Node {
  int x, y;
  Node(int x, int y) : x(x), y(y) {}
  Node() {}
  bool operator<(const Node &rhs) const {
    if (x == rhs.x) return y < rhs.y;
    return x < rhs.x;
  }
};
set<int> wc;
set<Node> se;
map<int, Node> mp;
vector<Node> ans;
int main() {
  int n, t;
  int ok = 1;
  Node tmp;
  scanf("%d", &n);
  int dx = 0, dy = 0, ex = 0, ey = 0, x, y;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    if (x >= dx) {
      dx = x;
      dy = max(dy, y);
    }
    if (y >= ey) {
      ex = max(ex, x);
      ey = y;
    }
  }
  wc.insert(0);
  mp[0] = Node(0, 0);
  se.insert(Node(0, 0));
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (wc.count(t) > 0) {
      wc.erase(t);
      tmp = mp[t];
      ans.push_back(tmp);
      if (((tmp.x + 1 <= dx && tmp.y <= dy) ||
           (tmp.x + 1 <= ex && tmp.y <= ey)) &&
          se.count(Node(tmp.x + 1, tmp.y)) == 0) {
        wc.insert(tmp.y - (tmp.x + 1));
        mp[tmp.y - (tmp.x + 1)] = Node(tmp.x + 1, tmp.y);
        se.insert(Node(tmp.x + 1, tmp.y));
      }
      if ((tmp.x <= ex && tmp.y + 1 <= ey || tmp.x <= dx && tmp.y + 1 <= dy) &&
          se.count(Node(tmp.x, tmp.y + 1)) == 0) {
        wc.insert(tmp.y + 1 - (tmp.x));
        mp[tmp.y + 1 - (tmp.x)] = Node(tmp.x, tmp.y + 1);
        se.insert(Node(tmp.x, tmp.y + 1));
      }
    } else {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (auto &i : ans) {
    printf("%d %d\n", i.x, i.y);
  }
  return 0;
}
