#include <bits/stdc++.h>
using table = std::vector<std::vector<std::string> >;
using result =
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > >;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n = 0, m = 0;
  std::cin >> n >> m;
  int s = 0;
  table start(n), end(n);
  for (int i = 0; i < n; ++i) {
    start[i].resize(m);
    end[i].resize(m);
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      std::cin >> start[i][j];
      s += start[i][j].size();
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) std::cin >> end[i][j];
  std::vector<int> z(m), o(m);
  std::vector<int> rz(m), ro(m);
  result res(4 * s);
  int k = 0;
  for (int i = 0; i < m; ++i) z[i] = o[i] = rz[i] = ro[i] = 0;
  for (int i = 2; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int p = start[i][j].size() - 1; p >= 0; --p)
        if (start[i][j][p] == '0') {
          ++z[j];
          res[k++] = {{i, j}, {0, j}};
        } else {
          ++o[i];
          res[k++] = {{i, j}, {1, j}};
        }
  for (int j = 0; j < m; ++j) {
    for (int p = start[0][j].size() - 1; p >= 0; --p)
      if (start[0][j][p] == '0') {
        ++z[(j + 1) % m];
        res[k++] = {{0, j}, {0, (j + 1) % m}};
      } else {
        ++o[j];
        res[k++] = {{0, j}, {1, j}};
      }
    for (int p = start[1][j].size() - 1; p >= 0; --p)
      if (start[1][j][p] == '1') {
        ++o[(j + 1) % m];
        res[k++] = {{1, j}, {1, (j + 1) % m}};
      } else {
        ++z[j];
        res[k++] = {{1, j}, {0, j}};
      }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int p = 0; p < end[i][j].size(); ++p)
        if (end[i][j][p] == '0')
          if (i == 0)
            ++rz[(j + 1) % m];
          else
            ++rz[j];
        else if (i == 1)
          ++ro[(j + 1) % m];
        else
          ++ro[j];
  int a = 0, b = 0;
  for (; a < m && b < m;) {
    for (; a < m && z[a] <= rz[a]; ++a)
      ;
    for (; b < m && z[b] >= rz[b]; ++b)
      ;
    if (a < m && b < m) {
      --z[a];
      ++z[b];
      res[k++] = {{0, a}, {0, b}};
    }
  }
  a = 0;
  b = 0;
  for (; a < m && b < m;) {
    for (; a < m && o[a] <= ro[a]; ++a)
      ;
    for (; b < m && o[b] >= ro[b]; ++b)
      ;
    if (a < m && b < m) {
      --o[a];
      ++o[b];
      res[k++] = {{1, a}, {1, b}};
    }
  }
  for (int i = 2; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int p = end[i][j].size() - 1; p >= 0; --p)
        if (end[i][j][p] == '0') {
          res[k++] = {{0, j}, {i, j}};
          --z[j];
        } else {
          res[k++] = {{1, j}, {i, j}};
          --o[j];
        }
  for (int j = 0; j < m; ++j) {
    for (int p = end[0][j].size() - 1; p >= 0; --p)
      if (end[0][j][p] == '0') {
        res[k++] = {{0, (j + 1) % m}, {0, j}};
        --z[(j + 1) % m];
      } else {
        res[k++] = {{1, j}, {0, j}};
        --o[j];
      }
    for (int p = end[1][j].size() - 1; p >= 0; --p)
      if (end[1][j][p] == '0') {
        res[k++] = {{0, j}, {1, j}};
        --z[j];
      } else {
        res[k++] = {{1, (j + 1) % m}, {1, j}};
        --o[(j + 1) % m];
      }
  }
  std::cout << k << "\n";
  for (int i = 0; i < k; ++i)
    std::cout << res[i].first.first + 1 << " " << res[i].first.second + 1 << " "
              << res[i].second.first + 1 << " " << res[i].second.second + 1
              << "\n";
}
