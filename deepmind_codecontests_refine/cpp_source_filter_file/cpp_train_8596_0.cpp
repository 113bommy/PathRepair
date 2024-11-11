#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
struct prod {
  int x, y;
};
bool cmp(prod a, prod b) {
  if (abs(a.x - a.y) == abs(b.x - b.y)) return a.x < b.x;
  return abs(a.x - a.y) < abs(b.x - b.y);
}
int n, k;
prod p[200005];
int main() {
  scanf("%d%d", &n, &k);
  for (int(i) = (0); (i) < (n); (i)++) scanf("%d", &p[i].x);
  for (int(i) = (0); (i) < (n); (i)++) scanf("%d", &p[i].y);
  sort(p, p + n, cmp);
  int tmp = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    if (p[i].x < p[i].y) k--;
  }
  int ans = 0;
  if (k <= 0) {
    for (int(i) = (0); (i) < (n); (i)++) ans += min(p[i].x, p[i].y);
    printf("%d\n", ans);
    return 0;
  }
  for (int(i) = (0); (i) < (n); (i)++) {
    if (k > 0) {
      if (p[i].x > p[i].y) k--;
      ans += p[i].x;
    } else
      ans += min(p[i].x, p[i].y);
  }
  printf("%d\n", ans);
  return 0;
}
