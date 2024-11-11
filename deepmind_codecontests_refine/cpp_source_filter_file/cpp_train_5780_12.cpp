#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int n, m, d[MAX];
pair<int, int> s[MAX];
struct par {
  int w, v, id;
  bool operator<(const par &p) const {
    if (w != p.w) return w < p.w;
    return v < p.v;
  }
} e[MAX];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &e[i].w, &e[i].v);
    e[i].id = i;
  }
  sort(e + 1, e + m + 1);
  int from = 2, to = 3, v = 1;
  for (int i = 1; i <= m; i++) {
    if (e[i].v == 1) {
      v++;
      d[v]++;
      s[e[i].id] = make_pair(1, v);
      continue;
    }
    if (from == to) {
      from = 2;
      to++;
    }
    if (to <= v) {
      s[e[i].id] = make_pair(from, to);
      from++;
    } else {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d %d\n", s[i].first, s[i].second);
  return 0;
}
