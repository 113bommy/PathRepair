#include <bits/stdc++.h>
using namespace std;
int a[2 * 100010], b[2 * 100010];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      int c;
      scanf("%d", &c);
      b[c] = i;
    }
    int pos = 0;
    for (int i = 2; i <= n; i++) {
      if (b[a[i]] < b[a[i - 1]]) {
        pos = i;
        break;
      }
    }
    if (pos == 0)
      printf("0\n");
    else
      printf("%d\n", n - pos + 1);
  }
  return 0;
}
