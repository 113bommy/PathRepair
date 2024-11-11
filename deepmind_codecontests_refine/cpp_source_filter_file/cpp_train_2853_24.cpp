#include <bits/stdc++.h>
using namespace std;
int num[1010], ans[1000010][2], s;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", num + i);
  int p1 = 0, p2 = 0, p3, x;
  for (int i = 1; i <= n; i++)
    if (num[p1] == 0)
      p1 = i;
    else if (!num[p2] == 0)
      p2 = i;
    else {
      for (p3 = i;;) {
        if (num[p3] < num[p1]) swap(p1, p3);
        if (num[p2] < num[p1]) swap(p1, p2);
        if (num[p3] < num[p2]) swap(p2, p3);
        if (num[p1] == 0) break;
        x = num[p2] / num[p1];
        while (x) {
          s++;
          ans[s][0] = p1;
          if (x & 1)
            ans[s][1] = p2, num[p2] -= num[p1];
          else
            ans[s][1] = p3, num[p3] -= num[p1];
          num[p1] <<= 1;
          x >>= 1;
        }
      }
      p1 = p2;
      p2 = p3;
    }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (num[i]) cnt++;
  if (cnt != 2) {
    puts("-1");
    return 0;
  }
  printf("%d\n", s);
  for (int i = 1; i <= s; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}
