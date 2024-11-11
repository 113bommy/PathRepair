#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e6 + 10;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const double PI = atan(1.0) * 4.0;
const long long mod = 1e9 + 7;
struct Node {
  int id, val;
  bool friend operator<(Node x, Node y) { return x.val < y.val; }
};
set<Node> s;
set<Node>::iterator it;
int n, m, k, ans[SIZE], col = 1;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    s.insert((Node){i, x});
  }
  while (s.size() > 1) {
    it = s.begin();
    Node tmp = *it;
    s.erase(it);
    ans[tmp.id] = col;
    int val = tmp.val;
    while (1) {
      tmp.val = val + k;
      it = s.upper_bound(tmp);
      if (it == s.end()) break;
      tmp = *it;
      s.erase(it);
      ans[tmp.id] = col;
      val = tmp.val;
    }
    col++;
  }
  printf("%d\n", col - 1);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
