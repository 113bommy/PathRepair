#include <bits/stdc++.h>
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int cm(const void *A, const void *B) { return *(int *)A - *(int *)B; }
const int MAX = 1e5;
int main() {
  int i;
  int sum, n;
  int a, b, c = 1, m = 1;
  scanf("%d", &n);
  scanf("%d", &a);
  scanf("%d", &b);
  n -= 2;
  while (a == b && n > 0) {
    c++;
    a = b;
    scanf("%d", &b);
    n--;
  }
  m = c;
  if (n > 0 || a != b) c = 1;
  a = b;
  for (i = n; i > 0; i--) {
    scanf("%d", &b);
    if (a == b)
      c++;
    else {
      if (m == c) {
        c = 1;
        a = b;
      } else {
        printf("NO\n");
        return 0;
      }
    }
  }
  if (c == m)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
