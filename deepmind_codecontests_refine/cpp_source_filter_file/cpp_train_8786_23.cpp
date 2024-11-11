#include <bits/stdc++.h>
using namespace std;
int d[110];
int main() {
  int n;
  scanf(" %d", &n);
  int tol = 0;
  for (int i = 1; i <= n; i++) {
    scanf(" %d", &d[i]);
    tol += d[i];
  }
  int cur = 0;
  int x, y;
  scanf(" %d %d", &x, &y);
  bool f = false;
  for (int i = 1; i <= n; i++) {
    int l = cur, r = tol - cur;
    if (l >= x && l < y && r >= x && r < y) {
      printf("%d\n", i);
      f = true;
      break;
    }
    cur += d[i];
  }
  if (!f) {
    puts("0");
  }
  return 0;
}
