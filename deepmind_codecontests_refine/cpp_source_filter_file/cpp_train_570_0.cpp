#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
  int n, b, i, ma = 0, ju, cnt, le, st, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  le = 1;
  ju = a[0];
  for (i = 1; i < n; i++) {
    if (a[i] != ju)
      le++;
    else {
      ma = max(ma, le);
      st = i - le + 1;
      cnt = 0;
      if (le >= 3) {
        if (le % 2 == 0) {
          le = (le - 2) / 2;
          for (j = st; j < i - 1; j++) {
            if (cnt < le) {
              a[j] = a[st - 1];
            } else {
              a[j] = a[i];
            }
            cnt++;
          }
        } else {
          for (j = st; j < i - 1; j++) {
            a[j] = a[st - 1];
          }
        }
      }
      le = 1;
    }
    ju = a[i];
  }
  ma = max(ma, le);
  st = i - le + 1;
  cnt = 0;
  if (le >= 3) {
    if (le % 2 == 0) {
      le = (le - 2) / 2;
      for (j = st; j < i - 1; j++) {
        if (cnt < le) {
          a[j] = a[st - 1];
        } else {
          a[j] = a[i];
        }
        cnt++;
      }
    } else {
      for (j = st; j < i - 1; j++) {
        a[j] = a[st - 1];
      }
    }
  }
  le = (ma - 1) / 2;
  printf("%d\n", le);
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
