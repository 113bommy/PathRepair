#include <bits/stdc++.h>
using namespace std;
int ispr[1111111 * 2];
int n, a[1111];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < 1111111 * 2; ++i) {
    ispr[i] = 1;
  }
  for (int i = 2; i < 1111111 * 2; ++i) {
    if (ispr[i]) {
      for (int j = 2 * i; j < 1111111 * 2; j += i) {
        ispr[j] = 0;
      }
    }
  }
  sort(a, a + n);
  int ptr = 0;
  while (ptr < n && a[ptr] < 2) ++ptr;
  if (ptr < n && a[ptr] == 2) ++ptr;
  if (ptr < n && a[ptr] > 2 && a[0] == 1) {
    for (int i = 0; i < n; ++i) {
      if (a[i] > 2 && ispr[a[i] + 1]) {
        a[ptr] = a[i];
        ++ptr;
        break;
      }
    }
  }
  int bi = -1, bj = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i] > 1 && a[j] > 1) {
        if (ispr[a[i] + a[j]]) {
          bi = i, bj = j;
        }
      }
    }
  }
  if (ptr > 2) {
    printf("%d\n", ptr);
    for (int i = 0; i < ptr; ++i) {
      if (i) printf(" ");
      printf("%d", a[i]);
    }
    printf("\n");
    exit(0);
  }
  if (bi != -1) {
    printf("%d\n", 2);
    printf("%d %d\n", a[bi], a[bj]);
    exit(0);
  }
  printf("%d\n", 1);
  printf("%d\n", a[0]);
}
