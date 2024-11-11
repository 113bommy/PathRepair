#include <bits/stdc++.h>
int main() {
  int n, m;
  char c;
  int id;
  int a[100005], first, check;
  int online, sum;
  while (scanf("%d %d", &n, &m) == 2) {
    memset(a, 0, sizeof(a));
    online = 0, sum = 0;
    for (int i = 0; i < m; i++) {
      getchar();
      scanf("%c,%d", &c, &id);
      if (!i) {
        first = id;
        check = 1;
      }
      if (c == '+') {
        if (id != first && a[first] == -1) check = 0;
        a[id] = 1;
        online++;
      } else {
        if (a[id] == 1) online--;
        if (id != first && a[id] == 0) {
          first = id;
          check = 1;
        }
        if (id == first && online > 0) check = 0;
        a[id] = -1;
      }
    }
    if (check) a[first] = 0;
    for (int i = 1; i <= n; i++)
      if (!a[i]) sum++;
    printf("%d\n", sum);
    for (int i = 1; i <= n; i++)
      if (!a[i]) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
