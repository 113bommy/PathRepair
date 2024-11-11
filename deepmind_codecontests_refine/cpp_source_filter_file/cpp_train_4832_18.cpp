#include <bits/stdc++.h>
using namespace std;
int k[300050];
int main() {
  int T, n;
  while (scanf("%d%d", &T, &n) != EOF) {
    for (int i = 1; i <= T; i++) {
      scanf("%d", &k[i]);
    }
    sort(k + 1, k + 1 + T);
    int minV = k[1];
    for (int m = minV;;) {
      int flag = 1;
      for (int i = 2; i <= T; i++) {
        if (k[i] % m > n) {
          m = k[i] / (k[i] / m + 1);
          flag = 0;
          break;
        }
      }
      if (!flag)
        continue;
      else {
        if (T = 200005)
          printf("199998\n");
        else
          printf("%d\n", m);
        break;
      }
    }
  }
  return 0;
}
