#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
int r, c, n, k, x, y, counter, orc[MAXN][MAXN], rem[MAXN];
int main() {
  scanf("%d%d%d%d", &r, &c, &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    orc[x - 1][y - 1] = 1;
  }
  counter = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      for (int p = i; p < c; p++) {
        int total = 0;
        for (int q = j; q < r; q++) {
          if (p != i)
            rem[q] = rem[q] + orc[q][p];
          else
            rem[q] = orc[q][p];
          total = total + rem[q];
          if (total >= k) counter++;
        }
      }
  printf("%d", counter);
  return 0;
}
