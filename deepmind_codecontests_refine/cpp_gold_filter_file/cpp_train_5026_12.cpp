#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int t;
int a, b, c, d;
int ans[5];
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(ans, 0, sizeof(ans));
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if ((a + b) & 1) {
      if (a > 0 || d > 0)
        ans[1] = 0;
      else
        ans[1] = 1;
    } else {
      ans[1] = 1;
    }
    if ((a + b) & 1) {
      if (b > 0 || c > 0)
        ans[2] = 0;
      else
        ans[2] = 1;
    } else {
      ans[2] = 1;
    }
    if ((a + b) % 2 == 0) {
      if (c > 0 || b > 0)
        ans[3] = 0;
      else
        ans[3] = 1;
    } else {
      ans[3] = 1;
    }
    if ((a + b) % 2 == 0) {
      if (d > 0 || a > 0)
        ans[4] = 0;
      else
        ans[4] = 1;
    } else {
      ans[4] = 1;
    }
    for (int i = 1; i <= 4; i++) {
      if (ans[i])
        printf("Tidak ");
      else
        printf("Ya ");
    }
    printf("\n");
  }
  return 0;
}
