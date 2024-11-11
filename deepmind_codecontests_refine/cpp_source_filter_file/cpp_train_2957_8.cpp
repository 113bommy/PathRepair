#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, m;
vector<int> g[maxn];
bool mat[20][20];
set<pair<int, int> > es;
int p[maxn];
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  if (n <= 12) {
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u;
      --v;
      mat[u][v] = mat[v][u] = true;
    }
    do {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (!mat[p[i]][p[(i + 1) % n]]) {
          ++cnt;
        }
      }
      if (cnt >= m) {
        cnt = 0;
        for (int i = 0; i < n; ++i) {
          if (!mat[p[i]][p[(i + 1) % n]]) {
            printf("%d %d\n", p[i] + 1, p[(i + 1) % n] + 1);
            if (++cnt == m) {
              break;
            }
          }
        }
        return 0;
      }
    } while (next_permutation(p + 1, p + n));
    puts("-1");
  } else {
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u;
      --v;
      es.insert({u, v});
      es.insert({v, u});
    }
    for (int i = 0; i < 10; ++i) {
      random_shuffle(p, p + n);
      bool good = true;
      for (int j = 0; j < m; ++j) {
        if (!es.count({p[j], p[(j + 1) % n]})) {
          good = false;
          break;
        }
      }
      if (good) {
        for (int j = 0; j < m; ++j) {
          printf("%d %d\n", p[j] + 1, p[(j + 1) % n] + 1);
        }
        return 0;
      }
    }
    puts("-1");
  }
  return 0;
}
