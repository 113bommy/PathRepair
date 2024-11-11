#include <bits/stdc++.h>
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  char que[n + 1];
  scanf("%s", que);
  int res = 0;
  for (int i = 0; res < t; ++i) {
    for (int j = 0; j <= n; j++) {
      if (que[j] == 'B' && que[j + 1] == 'G') {
        char tmp = que[j];
        que[j] = que[j + 1];
        que[j + 1] = tmp;
        j += 2;
      }
    }
    res++;
  }
  printf("%s\n", que);
}
