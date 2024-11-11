#include <bits/stdc++.h>
using namespace std;
int countTreesFor(bool**, int, int, int, int, int, int);
int main(int argc, char* argv[]) {
  int n, m, a, b;
  cin >> n >> m;
  bool** garden = new bool*[n];
  for (int i = 0; i < n; ++i) {
    garden[i] = new bool[m];
    for (int j = 0; j < m; ++j) {
      cin >> garden[i][j];
    }
  }
  cin >> a >> b;
  int minCount = 50 * 50;
  for (int i = 0; i <= n - a; ++i) {
    for (int j = 0; j <= m - b; ++j)
      minCount = min(minCount, countTreesFor(garden, i, j, a, b, n, m));
  }
  for (int i = 0; i <= n - b; ++i) {
    for (int j = 0; j <= m - a; ++j)
      minCount = min(minCount, countTreesFor(garden, i, j, b, a, n, m));
  }
  cout << minCount;
  for (int i = 0; i < n; ++i) delete[] garden[i];
  delete[] garden;
  return 0;
}
int countTreesFor(bool** garden, int i, int j, int a, int b, int n, int m) {
  int count = 0;
  for (int x = 0; x < i + a; ++x)
    for (int y = 0; y < j + b; ++y) count = garden[i][j] ? (1 + count) : count;
  return count;
}
