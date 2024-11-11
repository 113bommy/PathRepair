#include <bits/stdc++.h>
using namespace std;
int main() {
  int n{}, m{}, cnt{}, Two{}, One{}, row{}, column{};
  std::cin >> n >> m;
  char series[105][105];
  for (int x{1}; x <= n; ++x) {
    cnt = 0;
    for (int y{1}; y <= m; ++y) {
      std::cin >> series[x][y];
      if (series[x][y] == '*') cnt++;
    }
    if (cnt == 2) Two = x;
    if (cnt == 1) One = x;
  }
  row = One;
  for (int x{1}; x <= n; x++) {
    if (series[Two][x] == '*' && series[One][x] != '*') {
      column = x;
      break;
    }
  }
  std::cout << row << ' ' << column << std::endl;
  return 0;
}
