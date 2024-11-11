#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int r1, r2, r3, a1;
  scanf("%d", &n);
  int arr[n + 1];
  printf("? 1 2\n");
  fflush(stdout);
  scanf("%d", &r1);
  printf("? 2 3\n");
  fflush(stdout);
  scanf("%d", &r2);
  printf("? 3 1\n");
  fflush(stdout);
  scanf("%d", &r3);
  a1 = (r1 + r2 + r3) / 2 - r2;
  arr[1] = a1;
  arr[2] = r1 - a1;
  arr[3] = r3 - a1;
  for (int i = 4; i <= n; i++) {
    printf("? 1 %d\n", i);
    fflush(stdout);
    scanf("%d", &r3);
    arr[i] = r3 - a1;
  }
  printf("?");
  for (int i = 1; i <= n; i++) {
    printf(" %d", arr[i]);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}
