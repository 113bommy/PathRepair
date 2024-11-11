#include <bits/stdc++.h>
using namespace std;
long const M = 1000000 + 10;
long n, t;
long dif[M];
char a[M], b[M];
char ans[M];
int main() {
  scanf("%ld%ld", &n, &t);
  scanf("%s%s", a, b);
  long i, j, cnt = 0;
  for (i = 0, j = 0; i < n; i++) {
    if (a[i] == b[i]) dif[j++];
  }
  long tt = n - t;
  if (tt > j + (n - j) / 2) {
    printf("-1\n");
    return 0;
  }
  if (tt <= j) {
    for (i = 0; i < n; i++) {
      if (a[i] == b[i] && tt) {
        printf("%c", a[i]);
        tt--;
      } else
        for (char h = 'a';; h++) {
          if (h != a[i] && h != b[i]) {
            printf("%c", h);
            break;
          }
        }
    }
  } else {
    tt -= j;
    long k = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        printf("%c", a[i]);
        continue;
      }
      if (tt) {
        if (cnt % 2 == 0) {
          printf("%c", a[i]);
          cnt++;
        } else {
          printf("%c", b[i]);
          cnt++;
        }
        if (cnt % 2 == 0 && cnt != 0) tt--;
        continue;
      } else {
        for (char h = 'a';; h++) {
          if (h != a[i] && h != b[i]) {
            printf("%c", h);
            break;
          }
        }
        continue;
      }
    }
  }
  printf("\n");
  return 0;
}
