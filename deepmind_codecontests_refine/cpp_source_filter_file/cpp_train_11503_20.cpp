#include <bits/stdc++.h>
using namespace std;
int ans = 0, n, last = 0, last_h = 0;
int main(int argc, char *argv[]) {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int d, h;
    scanf("%d%d", &d, &h);
    if (i && d - last < abs(last_h - h)) {
      printf("IMPOSSIBLE");
      return 0;
    }
    if (i) {
      ans = max(ans, max(last_h, h) + (d - last - abs(h - last_h)) / 2);
    } else {
      ans = h + d;
    }
    last = d;
    last_h = h;
  }
  ans = max(ans, n - last + last_h);
  printf("%d", ans);
  return 0;
}
