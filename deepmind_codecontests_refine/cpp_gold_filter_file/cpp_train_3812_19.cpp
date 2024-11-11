#include <bits/stdc++.h>
using namespace std;
int n;
struct vec {
  int x1, x2, x3, x4, x5;
} tor[20];
int vis[20];
int ans = 0;
bool isgood(int i, int j, int k) {
  if (((tor[j].x1 - tor[i].x1) * (tor[k].x1 - tor[i].x1) +
       (tor[j].x2 - tor[i].x2) * (tor[k].x2 - tor[i].x2) +
       (tor[j].x3 - tor[i].x3) * (tor[k].x3 - tor[i].x3) +
       (tor[j].x4 - tor[i].x4) * (tor[k].x4 - tor[i].x4) +
       (tor[j].x5 - tor[i].x5) * (tor[k].x5 - tor[i].x5)) <= 0)
    return true;
  else
    return false;
}
int main() {
  scanf("%d", &n);
  if (n > 11) {
    printf("0\n");
    return 0;
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d %d %d", &tor[i].x1, &tor[i].x2, &tor[i].x3, &tor[i].x4,
          &tor[i].x5);
    vis[i] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) {
        if (j == i || k == i || j == k) continue;
        if (!isgood(i, j, k)) {
          vis[i] = 0;
          break;
        }
      }
  for (int i = 1; i <= n; i++)
    if (vis[i]) ans++;
  printf("%d\n", ans);
  if (!ans) return 0;
  for (int i = 1; i <= n; i++)
    if (vis[i]) printf("%d\n", i);
  return 0;
}
