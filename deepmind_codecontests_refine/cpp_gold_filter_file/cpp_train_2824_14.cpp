#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a;
  scanf("%d", &a);
  int* v = NULL;
  v = (int*)malloc(sizeof(int) * n);
  int i = 0;
  for (;;) {
    if (i >= n) {
      break;
    }
    scanf("%d", &v[i]);
    ++i;
  }
  int num = 0;
  int max = 0;
  i = 0;
  for (;;) {
    if (i >= n) {
      break;
    }
    if (i == 0) {
      ++num;
    }
    if (i != 0) {
      if (v[i] != v[i - 1]) {
        ++num;
      } else {
        num = 1;
      }
    }
    if (num > max) {
      max = num;
    }
    ++i;
  }
  printf("%d", max);
  free(v);
}
