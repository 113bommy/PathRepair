#include <bits/stdc++.h>
const int kN = 61 + 5;
int m, a[kN];
bool f[kN][kN][kN * (kN - 1) / 2];
bool ok(int i, int j, int k) {
  if (i < 0 || i > m || j < 0 || j > 61 || k < 0 || k > 61 * 30) return false;
  if ((j - 1) * j / 2 > k) return false;
  return true;
}
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", a + i);
  std::sort(a + 1, a + m + 1);
  f[0][0][0] = true;
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= 61; ++j) {
      for (int k = j * (j - 1) / 2; k <= 61 * 60 / 2; ++k) {
        if (!f[i][j][k]) continue;
        if (ok(i + 1, j + 1, k + a[i + 1]))
          f[i + 1][j + 1][k + a[i + 1]] = true;
        if (i && ok(i, j + 1, k + a[i])) f[i][j + 1][k + a[i]] = true;
      }
    }
  }
  bool flag = false;
  int i = m, j, k;
  for (j = m; j <= 61; ++j) {
    if (f[i][j][j * (j - 1) / 2]) {
      k = j * (j - 1) / 2;
      flag = true;
      break;
    }
  }
  if (!flag) return puts("=("), 0;
  std::vector<std::pair<int, int>> deg;
  while (j) {
    if (ok(i, j - 1, k - a[i]) && f[i][j - 1][k - a[i]]) {
      deg.emplace_back(a[i], j - 1);
      k -= a[i];
      j--;
      continue;
    } else if (ok(i - 1, j - 1, k - a[i]) && f[i - 1][j - 1][k - a[i]]) {
      deg.emplace_back(a[i], j - 1);
      k -= a[i];
      j--;
      i--;
    }
  }
  int n = deg.size();
  std::vector<std::vector<int>> graph(n, std::vector<int>(n));
  while (true) {
    std::sort(deg.begin(), deg.end());
    if (deg.empty()) break;
    int d, id;
    std::tie(d, id) = deg.back();
    deg.pop_back();
    assert(d <= deg.size());
    for (int i = 0; i < d; ++i) {
      graph[id][deg[i].second] = 1;
    }
    for (int i = d; i < deg.size(); ++i) {
      graph[deg[i].second][id] = 1;
      deg[i].first--;
    }
  }
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) printf("%d", graph[i][j]);
    puts("");
  }
}
