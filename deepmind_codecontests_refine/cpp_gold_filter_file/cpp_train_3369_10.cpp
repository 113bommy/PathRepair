#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char tp = getchar();
  int ans = 0;
  while (tp > '9' || tp < '0') tp = getchar();
  while (tp <= '9' && tp >= '0') {
    ans = ans * 10 + tp - '0';
    tp = getchar();
  }
  return ans;
}
int ma[120][120], k;
int main() {
  scanf("%d", &k);
  int n = 100;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= i - 1; j++) {
      if (ma[i][j]) continue;
      int ans = 0;
      for (int k = 1; k <= j - 1; k++)
        if (ma[i][k] && ma[j][k]) ans++;
      if (ans <= k) {
        k -= ans;
        ma[i][j] = ma[j][i] = 1;
        if (k == 0) break;
      }
    }
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d", ma[i][j]);
    printf("\n");
  }
  return 0;
}
