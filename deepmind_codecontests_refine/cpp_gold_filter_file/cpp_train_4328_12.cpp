#include <bits/stdc++.h>
using namespace std;
int l[100010], r[100010];
int main() {
  int n, tl = 0, tr = 0, res = 0, b = 0;
  scanf("%d ", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d %d ", l + i, r + i);
    tl += l[i];
    tr += r[i];
  }
  b = abs(tl - tr);
  for (int i = 1; i < n + 1; i++) {
    int x = tl - l[i] + r[i];
    int y = tr - r[i] + l[i];
    if (abs(x - y) > b) {
      res = i;
      b = abs(x - y);
    }
  }
  printf("%d", res);
  return 0;
}
