#include <bits/stdc++.h>
using namespace std;
int a[1003];
int b[1003];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  a[0] = 1e9 + 7;
  int flag = 1, o = 1;
  b[0] = 1e9 + 7;
  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; i++) {
      if (a[i] > b[o - 1]) {
        flag = 0;
        break;
      } else {
        b[o] = a[i];
        o++;
      }
      if (a[n - i + 1] < b[o - 1]) {
        flag = 0;
        break;
      } else {
        b[o] = a[n - i + 1];
        o++;
      }
    }
  } else {
    for (int i = 1; i <= n / 2; i++) {
      if (a[i] > b[o - 1]) {
        flag = 0;
        break;
      } else {
        b[o] = a[i];
        o++;
      }
      if (a[n - i + 1] < b[o - 1]) {
        flag = 0;
        break;
      } else {
        b[o] = a[n - i + 1];
        o++;
      }
    }
    if (a[n / 2 + 1] > a[n / 2 + 2]) {
      flag = 0;
    } else {
      b[o] = a[n / 2 + 1];
      o++;
    }
  }
  if (flag) {
    for (int i = 1; i < o; i++) {
      printf(i == 1 ? "%d" : " %d", b[i]);
    }
    printf("\n");
  } else
    printf("Impossible\n");
}
