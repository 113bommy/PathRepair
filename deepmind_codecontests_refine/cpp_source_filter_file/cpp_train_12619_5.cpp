#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main() {
  int n, q;
  int a[3][maxn];
  scanf("%d%d", &n, &q);
  int x, y;
  int sum = 0;
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &x, &y);
    if (a[x][y])
      sum -= a[3 - x][y - 1] + a[3 - x][y] + a[3 - x][y + 1];
    else
      sum += a[3 - x][y - 1] + a[3 - x][y] + a[3 - x][y + 1];
    if (!sum)
      printf("Yes\n");
    else
      printf("No\n");
    a[x][y] ^= 1;
  }
  return 0;
}
