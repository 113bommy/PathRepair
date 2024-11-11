#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[7];
  int i, x;
  scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
  sort(a, a + 6);
  if (a[0] == a[1] && a[2] == a[3] && a[1] == a[2]) {
    if (a[4] == a[5])
      printf("Elephant\n");
    else
      printf("Bear\n");
  } else if (a[1] == a[2] && a[3] == a[4] && a[2] == a[3]) {
    printf("Bear\n");
  } else if (a[2] == a[3] && a[4] == a[5] && a[3] == a[4]) {
    if (a[0] == a[1])
      printf("Elephant\n");
    else
      printf("Bear\n");
  } else
    printf("Alien\n");
  return 0;
}
