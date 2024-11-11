#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int c, v0, v1, a, l;
  scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);
  int ans = 0;
  while (c > 0) {
    c = c - v0;
    ans++;
    if (c == 0) break;
    v0 = min(v0 + a, v1);
    c = c + l;
  }
  printf("%d\n", ans);
  return 0;
}
