#include <bits/stdc++.h>
using namespace std;
const int N = 207;
int n, m;
vector<pair<int, int> > ans;
struct Node {
  int x, y;
  Node() {}
  Node(int _x, int _y) { x = _x, y = _y; }
  Node operator-(const Node &p) const { return Node(x - p.x, y - p.y); }
  long long operator^(const Node &p) const {
    return 1ll * x * p.y - 1ll * y * p.x;
  }
};
bool check() {
  for (int i = (0); i < (((int)(ans).size())); ++i)
    for (int j = (i + 1); j < (((int)(ans).size())); ++j)
      for (int k = (j + 1); k < (((int)(ans).size())); ++k) {
        Node p =
            Node(ans[j].first - ans[i].first, ans[j].second - ans[i].second);
        Node q =
            Node(ans[k].first - ans[i].first, ans[k].second - ans[i].second);
        if ((p ^ q) == 0) return false;
      }
  return true;
}
void solve() {
  if (m == 3) {
    if (n == 3) {
      printf("0 0\n1 0\n0 1");
    } else if (n == 4) {
      printf("0 0\n3 0\n0 3\n1 1");
    } else if (n == 5 || n == 6) {
      puts("-1");
    }
    return;
  }
  for (int i = (0); i < (m); ++i)
    ans.push_back(make_pair(100 * i, i * (i - 1) >> 1));
  for (int i = (0); i < (n - m); ++i)
    ans.push_back(make_pair(1e5 + 100 * i, -1 - (i * (i - 1) >> 1)));
  for (int i = (0); i < (n); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
int main() {
  scanf("%d%d", &n, &m);
  solve();
  return 0;
}
