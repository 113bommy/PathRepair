#include <bits/stdc++.h>
int cmpfunc(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int main() {
  int a1, a2, x1, y1, x2, y2, p, q, r = 0;
  scanf("%d %d %d %d %d %d", &a1, &a2, &x1, &x2, &y1, &y2);
  if (x1 + y1 <= a1 && x2 <= a2 && y2 <= a2) {
    r = 1;
  } else if (x1 + y1 <= a2 && x2 <= a1 && y2 <= a1) {
    r = 1;
  } else if (x1 + y2 <= a1 && x2 <= a2 && y1 <= a2) {
    r = 1;
  } else if (x1 + y2 <= a2 && x2 <= a1 && y1 <= a1) {
    r = 1;
  } else if (x2 + y1 <= a1 && x1 <= a2 && y2 <= a2) {
    r = 1;
  } else if (x2 + y1 <= a2 && x1 <= a1 && y2 <= a1) {
    r = 1;
  } else if (x2 + y2 <= a1 && x1 <= a2 && y1 <= a2) {
    r = 1;
  } else if (x2 + y2 <= a2 && x1 <= a1 && y1 <= a1) {
    r = 1;
  }
  if (r == 1)
    printf("YES");
  else
    printf("NO");
  return 0;
}
