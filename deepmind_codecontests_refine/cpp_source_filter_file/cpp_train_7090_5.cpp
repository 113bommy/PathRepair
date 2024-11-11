#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
inline int read() {
  int x;
  scanf(" %d", &x);
  return x;
}
void solve() {
  int n = read();
  int q = read();
  vector<vector<pair<int, int>>> locs(n + 1);
  vector<vector<int>> c(q);
  vector<int> sz(q);
  int tot = 0;
  for (int i = 0; i < q; i++) {
    sz[i] = read();
    c[i] = vector<int>(sz[i]);
    for (int j = 0; j < sz[i]; j++) {
      c[i][j] = read();
      locs[c[i][j]].push_back({i, j});
    }
    tot += sz[i];
  }
  int k = 1;
  while (k * k <= tot) {
    ++k;
  }
  vector<vector<pair<int, int>>> buckets(n + 1);
  for (int i = 0; i < q; i++) {
    if (sz[i] > k) {
      vector<int> first_bad(q, 1e5 + 100);
      for (int j = 0; j < sz[i]; j++) {
        for (auto [xi, xj] : locs[c[i][j]])
          if (xi != i) {
            if (first_bad[xi] < xj) {
              printf("Human\n");
              return;
            }
            if (j + 1 < sz[i] && xj + 1 < sz[xi] &&
                c[xi][xj + 1] != c[i][j + 1]) {
              first_bad[xi] = min(first_bad[xi], xj);
            }
          }
      }
    } else {
      for (int u = 0; u < sz[i]; u++) {
        for (int v = u + 1; v < sz[i]; v++) {
          int cu = c[i][u];
          int cv = c[i][v];
          int cm = c[i][u + 1];
          buckets[cv].push_back({cu, cm});
        }
      }
    }
  }
  for (int x = 1; x <= n; x++) {
    vector<pair<int, int>> &bucket = buckets[x];
    sort(bucket.begin(), bucket.end());
    for (int i = 0; i + 1 < bucket.size(); i++) {
      if (bucket[i].first == bucket[i + 1].first &&
          bucket[i].second != bucket[i + 1].second) {
        printf("Human\n");
        return;
      }
    }
  }
  printf("Robot\n");
}
int main() {
  int t = read();
  while (t--) {
    solve();
  }
  return 0;
}
