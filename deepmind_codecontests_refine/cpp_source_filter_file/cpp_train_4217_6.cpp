#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0;
  int a[10], i, j;
  for (i = 1; i <= 6; i++) scanf("%d", &a[i]);
  int ceng = a[2] + a[3];
  int t = a[1], d = a[1] + 1;
  for (i = 1; i <= ceng; i++) {
    ans += t;
    ans += d;
    if (i < a[2]) {
      if (i < a[6]) {
        t++;
        d++;
      } else if (i == a[6]) {
        t++;
      }
    } else if (i == a[2]) {
      if (i <= a[6]) {
        t = d;
      } else {
        t = d;
        d--;
      }
    } else {
      if (i < a[6]) {
        t = d;
      } else {
        t = d;
        d--;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
