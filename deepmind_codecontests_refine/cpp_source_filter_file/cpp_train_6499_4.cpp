#include <bits/stdc++.h>
using namespace std;
int str[2010][2010];
int main() {
  int i, j, k;
  int n, m;
  int op, tmp;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &str[i][j]);
      }
    }
    int ans = 0;
    for (i = 0; i < n; i++) {
      ans ^= str[i][i];
    }
    cin >> m;
    while (m--) {
      scanf("%d", &op);
      if (op == 1 || op == 2) {
        scanf("%d", &tmp);
        ans ^= 1;
      } else {
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
