#include <bits/stdc++.h>
const int ma = 100005;
int yes[ma], no[ma], now[ma], wh = 0, n, ok[ma], m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &now[i]);
    if (now[i] > 0)
      yes[now[i]]++;
    else
      no[-now[i]]++, wh++;
  }
  int en = 0;
  for (int i = 1; i <= n; i++) {
    if (wh + yes[i] - no[i] == m) ok[i] = 1, en++;
  }
  for (int i = 1; i <= n; i++) {
    if (now[i] < 0) {
      if (ok[-now[i]] && en == 1)
        puts("Lie");
      else if (ok[-now[i]])
        puts("LNot defined");
      else
        puts("Truth");
    } else {
      if (ok[now[i]] && en == 1)
        puts("Truth");
      else if (ok[now[i]])
        puts("Not defined");
      else
        puts("Lie");
    }
  }
  return 0;
}
