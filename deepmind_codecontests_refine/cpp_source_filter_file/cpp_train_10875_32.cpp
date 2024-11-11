#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  uint16_t n, m, a, b, best = 2500, current;
  cin >> n >> m;
  bool garden[n][m];
  for (uint16_t i = 0; i < n; i++)
    for (uint16_t j = 0; j < m; j++) cin >> garden[i][j];
  cin >> a >> b;
  for (uint16_t i = 0; i < n - a + 1; i++) {
    for (uint16_t j = 0; j < n - b + 1; j++) {
      current = 0;
      for (uint16_t _i = i; _i < i + a; _i++)
        for (uint16_t _j = j; _j < j + b; _j++) current += garden[_i][_j];
      if (current < best) best = current;
    }
  }
  for (uint16_t i = 0; i < n - b + 1; i++) {
    for (uint16_t j = 0; j < n - a + 1; j++) {
      current = 0;
      for (uint16_t _i = i; _i < i + b; _i++)
        for (uint16_t _j = j; _j < j + a; _j++) current += garden[_i][_j];
      if (current < best) best = current;
    }
  }
  cout << best;
}
