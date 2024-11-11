#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} s[1000050];
bool cmp(node a, node b) { return a.y > b.y; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d%d", &s[i].x, &s[i].y);
  sort(s, s + m, cmp);
  int now = 0;
  while (true) {
    now++;
    if (now & 1) {
      if ((now - 1) * now + 1 > n) break;
    } else {
      if ((now - 1) * now + (now - 1) / 2 + 1 > n) break;
    }
  }
  now--;
  int ans = 0;
  if (now > m) now = m;
  for (int i = 0; i < now; ++i) ans += s[i].y;
  printf("%d\n", ans);
  return 0;
}
