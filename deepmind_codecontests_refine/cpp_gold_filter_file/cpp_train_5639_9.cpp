#include <bits/stdc++.h>
int main() {
  typedef struct {
    int a;
    int b;
    int c;
  } list;
  int n;
  scanf("%d", &n);
  list* s = NULL;
  s = (list*)malloc(sizeof(list) * n);
  int i = 0;
  for (;;) {
    if (i >= n) {
      break;
    }
    scanf("%d", &s[i].a);
    scanf("%d", &s[i].b);
    ++i;
  }
  s[0].c = 0;
  s[0].c = s[0].c - s[0].a;
  s[0].c = s[0].c + s[0].b;
  i = 1;
  for (;;) {
    if (i >= n) {
      break;
    }
    s[i].c = s[i - 1].c;
    s[i].c = s[i].c - s[i].a;
    s[i].c = s[i].c + s[i].b;
    ++i;
  }
  int max = INT_MIN;
  i = 0;
  for (;;) {
    if (i >= n) {
      break;
    }
    if (s[i].c > max) {
      max = s[i].c;
    }
    ++i;
  }
  printf("%d", max);
  free(s);
}
