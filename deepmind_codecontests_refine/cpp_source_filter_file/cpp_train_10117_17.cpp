#include <bits/stdc++.h>
using namespace std;
const int n = 500000;
const int block = 708;
int ans[block + 1][block];
int a[n + 1];
void update(int x, int y) {
  for (int j = 1; j <= block; j++) {
    int t = x % j;
    ans[j][t] += y;
  }
  a[x] += y;
}
int calc(int x, int y) {
  if (x <= block)
    return ans[x][y];
  else {
    int ret = 0;
    if (!y) y = x;
    while (y <= n) {
      ret += y;
      y += x;
    }
    return ret;
  }
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      update(x, y);
    } else {
      printf("%d\n", calc(x, y));
    }
  }
  return 0;
}
