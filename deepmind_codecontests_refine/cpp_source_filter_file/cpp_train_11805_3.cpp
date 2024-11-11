#include <bits/stdc++.h>
using namespace std;
int x[100500];
int y[100500];
int main() {
  int a, b, k;
  while (scanf("%d%d%d", &a, &b, &k) == 3) {
    for (int i = 0; i < a; i++) scanf("%d", &x[i]);
    for (int i = 0; i < b; i++) scanf("%d", &y[i]);
    sort(x, x + a);
    sort(y, y + b);
    int p = a - 1, q = b - 1, lose = 0, flag = 0;
    while (p >= 0 && q >= 0) {
      if (x[p] == y[q]) {
        p--;
        q--;
      } else if (x[p] > y[q] && lose == 0) {
        flag = 1;
        break;
      } else if (x[p] > y[q]) {
        lose--;
        p--;
      } else {
        lose++;
        q--;
      }
    }
    if (q < 0)
      lose -= p + 1;
    else if (p < 0)
      lose++;
    if (lose <= 0) flag = 1;
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
