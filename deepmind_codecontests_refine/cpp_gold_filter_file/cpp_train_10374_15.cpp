#include <bits/stdc++.h>
struct seal {
  int age, pos;
};
int compare(const void* a, const void* b) {
  return ((seal*)a)->age - ((seal*)b)->age;
}
int main() {
  int n;
  seal Q[100000];
  int ans[100000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &Q[i].age);
    Q[i].pos = i;
  }
  qsort(Q, n, sizeof(seal), compare);
  int irr1 = 0, irr2 = 0, max_age = 0;
  for (int i = 0; i < n; i++) {
    ans[Q[i].pos] =
        (Q[i].age > max_age) ? irr1 - Q[i].pos - 1 : irr2 - Q[i].pos - 1;
    if (Q[i].age > max_age) {
      max_age = Q[i].age;
      irr2 = irr1;
      if (Q[i].pos > irr1) {
        irr1 = Q[i].pos;
      }
    } else {
      if (Q[i].pos > irr1) {
        irr1 = Q[i].pos;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] >= 0)
      printf("%d ", ans[i]);
    else
      printf("-1 ");
  }
  printf("\n");
  return 0;
}
