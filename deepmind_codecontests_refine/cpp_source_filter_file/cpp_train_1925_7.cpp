#include <bits/stdc++.h>
using namespace std;
int a[303], b[303];
int res[1000005][2];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    int len = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != b[i]) {
        for (int j = i + 1; j <= n; j++) {
          if (a[i] == b[j]) {
            for (int k = j; k > i; k--) {
              b[k] = b[k - 1];
              res[len][0] = k;
              res[len++][1] = k - 1;
            }
            b[i] = a[i];
            break;
          }
        }
      }
    }
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
      printf("%d %d\n", res[i][0], res[i][1]);
    }
  }
  return 0;
}
