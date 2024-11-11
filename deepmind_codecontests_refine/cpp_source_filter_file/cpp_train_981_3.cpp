#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int col[3000];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int y = 0; y < n; ++y)
    for (int x = 0; x < m; ++x) {
      char c;
      scanf(" %c", &c);
      if (c == 'U') col[x] += !(y % 2);
      if (c == 'R' and y - x >= 0) col[x + y]++;
      if (c == 'L' and x - y >= 0) col[x - y]++;
    }
  for (int i = 0; i < m; ++i) printf("%d ", col[i]);
  printf("\n");
  return 0;
}
