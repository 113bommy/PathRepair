#include <bits/stdc++.h>
struct room {
  int p;
  int s;
};
int main() {
  int n;
  scanf("%d", &n);
  struct room a[n];
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i].p);
    scanf("%d", &a[i].s);
  }
  int sum = 0;
  for (i = 0; i < n; i++) {
    if ((a[i].p) + 1 < a[i].s) {
      sum = sum + 1;
    }
  }
  printf("%d", sum);
  return 0;
}
