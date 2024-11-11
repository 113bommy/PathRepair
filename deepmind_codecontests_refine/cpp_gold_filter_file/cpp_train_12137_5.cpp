#include <bits/stdc++.h>
typedef struct {
  int id;
  int i;
} person;
int main() {
  int n;
  scanf("%d", &n);
  int i;
  scanf("%d", &i);
  if (i == 0) {
    printf("-1");
    return 0;
  }
  person a[n];
  a[0].id = 1;
  a[0].i = i;
  int j;
  for (j = 1; j < n; j++) {
    scanf("%d", &a[j].i);
    a[j].id = j + 1;
    i = i + a[j].i;
  }
  if (i < (n - 1)) {
    printf("-1");
    return 0;
  }
  int k = n;
  while (k--) {
    int l = n - 2;
    while (l > 0) {
      if (a[l].i < a[l + 1].i) {
        person h;
        h = a[l];
        a[l] = a[l + 1];
        a[l + 1] = h;
      }
      l--;
    }
  }
  printf("%d", (n - 1));
  int b, c = 1;
  for (b = 0; b < n; b++) {
    while (a[b].i--) {
      printf("\n%d %d", a[b].id, a[c].id);
      c++;
      if (c == n) {
        return 0;
      }
    }
  }
  return 0;
}
