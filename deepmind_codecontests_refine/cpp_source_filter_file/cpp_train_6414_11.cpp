#include <bits/stdc++.h>
using namespace std;
const int mod = 1E9 + 7;
const double eps = 1e-6;
template <typename T>
T abs(T val) {
  return val > 0 ? val : -val;
}
inline int max2(int a, int b) { return ((a > b) ? a : b); }
inline int min2(int a, int b) { return ((a < b) ? a : b); }
inline int max3(int a, int b, int c) { return max2(a, max2(b, c)); }
inline int min3(int a, int b, int c) { return min2(a, min2(b, c)); }
template <class T>
inline void read(T &ret) {
  char c;
  ret = 0;
  while ((c = getchar()) < '0' || c > '9')
    ;
  while (c >= '0' && c <= '9') ret = ret * 10 + (c - '0'), c = getchar();
}
template <class T>
inline void out(T x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 + '0');
}
int n, w, h;
struct Node {
  int x, y, g;
  Node(int x = 0, int y = 0, int g = 0) : x(x), y(y), g(g) {}
} node[100005], ans[100005];
vector<int> stat[100005 << 1];
vector<int> xs, ys;
void solve() {
  for (int i = 0; i <= 2E5; i++) stat[i].clear();
  for (int i = 1; i <= n; i++) {
    int tmp = node[i].x + node[i].y + 100005;
    stat[tmp].push_back(i);
  }
  for (int s = 0; s <= 2E5; s++) {
    if (stat[s].size() == 0) continue;
    xs.clear(), ys.clear();
    for (auto id : stat[s]) {
      if (node[id].g == 2)
        ys.push_back(node[id].y);
      else
        xs.push_back(node[id].x);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    sort(stat[s].begin(), stat[s].end(), [](int a, int b) {
      if (node[a].g != node[b].g)
        return (node[a].g == 2);
      else
        return node[a].g == 2 ? node[a].y > node[b].y : node[a].x < node[b].x;
    });
    for (int j = 0; j < xs.size(); j++) {
      ans[stat[s][j]] = Node(xs[j], h);
    }
    for (int j = 0; j < ys.size(); j++) {
      ans[stat[s][j + xs.size()]] = Node(w, ys[ys.size() - 1 - j]);
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d %d\n", ans[i].x, ans[i].y);
}
int main() {
  while (~scanf("%d%d%d", &n, &w, &h)) {
    int g, p, t;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &g, &p, &t);
      if (g == 1)
        node[i] = Node(p, -t, g);
      else
        node[i] = Node(-t, p, g);
    }
    solve();
  }
}
