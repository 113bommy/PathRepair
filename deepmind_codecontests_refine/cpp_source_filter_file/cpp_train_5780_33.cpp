#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
struct edge {
  int w, used, id;
  edge(int w = 0, bool used = false, int id = 0) {
    this->w = w;
    this->used = used;
    this->id = id;
  }
  bool operator<(const edge &o) const {
    if (w != o.w) return w < o.w;
    return used > o.used;
  }
};
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    edge e[m];
    pair<int, int> ans[n];
    for (int i = 0; i < m; i++) {
      scanf("%d %d", &x, &y);
      e[i] = edge(x, y, i);
    }
    sort(e, e + m);
    int tree_counter = 2;
    int from = 3;
    int to = 2;
    for (int i = 0; i < m; i++) {
      if (e[i].used) {
        ans[e[i].id] = make_pair(1, tree_counter++);
      } else {
        if (to >= from) {
          from++;
          to = 2;
        }
        if (from >= tree_counter) {
          puts("-1");
          return 0;
        }
        ans[e[i].id] = make_pair(from, to++);
      }
    }
    for (int i = 0; i < m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
