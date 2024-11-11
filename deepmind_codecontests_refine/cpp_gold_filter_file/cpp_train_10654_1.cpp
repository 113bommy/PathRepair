#include <bits/stdc++.h>
using namespace std;
int v[7], x[7];
int main() {
  for (int i = 0; i < 6; ++i) scanf("%d", &v[i]);
  int ans = -1;
  for (int i = 0; i <= 100000; ++i) {
    x[1] = v[1] - v[2] + v[3] - v[4] + 2 * i;
    if (x[1] % 2 || x[1] < 0) continue;
    x[2] = v[2] + v[4] - v[0] - 2 * i;
    if (x[2] % 2 || x[2] < 0) continue;
    x[3] = v[0] - v[2] - v[5] + v[3] + 2 * i;
    if (x[3] % 2 || x[3] < 0) continue;
    x[4] = v[2] + v[5] - v[1] - 2 * i;
    if (x[4] % 2 || x[4] < 0) continue;
    x[5] = v[4] + v[5] - v[3] - 2 * i;
    if (x[5] % 2 || x[5] < 0) continue;
    x[6] = v[0] - v[5] + v[1] - v[4] + 2 * i;
    if (x[6] % 2 || x[6] < 0) continue;
    ans = i;
    break;
  }
  if (ans != -1) {
    x[0] = ans;
    int res = ans;
    for (int i = 1; i <= 6; ++i) {
      x[i] /= 2;
      res += x[i];
    }
    printf("%d\n", res);
    for (int i = 0; i < res; ++i) printf("a");
    printf("\n");
    for (int i = 0; i < x[0] + x[1] + x[2]; ++i) printf("a");
    for (int i = 0; i < x[3] + x[4] + x[5] + x[6]; ++i) printf("b");
    printf("\n");
    for (int i = 0; i < x[0]; ++i) printf("a");
    for (int i = 0; i < x[1] + x[2]; ++i) printf("b");
    for (int i = 0; i < x[3] + x[4]; ++i) printf("a");
    for (int i = 0; i < x[5] + x[6]; ++i) printf("b");
    printf("\n");
    for (int i = 0; i < x[0]; ++i) printf("b");
    for (int i = 0; i < x[1]; ++i) printf("a");
    for (int i = 0; i < x[2]; ++i) printf("b");
    for (int i = 0; i < x[3]; ++i) printf("a");
    for (int i = 0; i < x[4]; ++i) printf("b");
    for (int i = 0; i < x[5]; ++i) printf("a");
    for (int i = 0; i < x[6]; ++i) printf("b");
    printf("\n");
  } else {
    printf("-1\n");
  }
  return 0;
}
