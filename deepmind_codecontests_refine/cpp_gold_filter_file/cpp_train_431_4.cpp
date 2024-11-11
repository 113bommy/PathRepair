#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e5 + 10;
set<int> g[maxN];
int t, n, m;
pair<int, int> edge[maxN];
int deg[maxN];
int id[maxN];
int main() {
  scanf("%d", &t);
  int nc = 1;
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 3 * n; ++i) g[i].clear();
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].insert(v);
      g[v].insert(u);
      deg[u] += 1;
      deg[v] += 1;
      edge[i] = {u, v};
    }
    int zero = 0;
    for (int i = 1; i <= 3 * n; ++i) zero += deg[i] == 0;
    if (zero >= n) {
      puts("IndSet");
      zero = n;
      for (int i = 1; i <= 3 * n; ++i) {
        if (deg[i] == 0) {
          printf("%d ", i);
          zero -= 1;
        }
        if (zero == 0) break;
      }
      puts("");
      continue;
    }
    set<int> v;
    bool fun = 0;
    for (int i = 1; i <= m; ++i) id[i] = i;
    for (int k = 0; k < 7; ++k) {
      v.clear();
      random_shuffle(id + 1, id + m + 1);
      int e = 0;
      for (int i = 1; i <= m; ++i) {
        if (v.count(edge[id[i]].first) or v.count(edge[id[i]].second)) {
          continue;
        }
        e += 1;
        v.emplace(edge[id[i]].first);
        v.emplace(edge[id[i]].second);
      }
      if (e >= n) {
        fun = 1;
        break;
      }
    }
    if (fun) {
      puts("Matching");
      v.clear();
      int e = 0;
      for (int i = 1; i <= m; ++i) {
        if (v.count(edge[id[i]].first) or v.count(edge[id[i]].second)) {
          continue;
        }
        e += 1;
        v.emplace(edge[id[i]].first);
        v.emplace(edge[id[i]].second);
        printf("%d ", id[i]);
        if (e == n) break;
      }
      puts("");
      continue;
    } else {
      for (int i = 1; i <= 3 * n; ++i) id[i] = i;
      for (int i = 1; i <= 7; ++i) {
        random_shuffle(id + 1, id + 3 * n + 1);
        set<int> s;
        bool fun = 0;
        for (int j = 1; j <= 3 * n; ++j) {
          bool p = 1;
          for (int v : g[id[j]])
            if (s.count(v)) {
              p = 0;
              break;
            }
          if (p) s.insert(id[j]);
          if (s.size() == n) {
            fun = 1;
            break;
          }
        }
        if (fun) {
          puts("IndSet");
          for (int x : s) printf("%d ", x);
          puts("");
          break;
        }
        s.clear();
      }
    }
  }
  return 0;
}
