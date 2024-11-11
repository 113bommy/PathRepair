#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[1001];
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int s = 1001, index = -1;
    for (int i = 0; i < n; i++) {
      int pre = a[i];
      int cur = 0;
      int flag = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (a[j] != pre - k) cur++;
        pre -= k;
        if (pre <= 0) flag = 1;
      }
      if (flag) continue;
      pre = a[i];
      for (int j = i + 1; j < n; j++) {
        if (a[j] != pre + k) cur++;
        pre += k;
      }
      if (cur < s) {
        index = i;
        s = cur;
      }
    }
    printf("%d\n", s);
    for (int i = 0; i < n; i++) {
      if (i < index) {
        int c = a[index] - (index - i) * k;
        if (a[i] < c)
          printf("+ %d %d\n", i + 1, c - a[i]);
        else if (a[i] > c)
          printf("- %d %d\n", i + 1, a[i] - c);
      } else if (i > index) {
        int c = a[index] + (i - index) * k;
        if (a[i] < c)
          printf("+ %d %d\n", i + 1, c - a[i]);
        else if (a[i] > c)
          printf("- %d %d\n", i + 1, a[i] - c);
      }
    }
  }
  return 0;
}
