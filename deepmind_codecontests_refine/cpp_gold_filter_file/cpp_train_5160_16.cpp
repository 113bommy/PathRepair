#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main() {
  int n, s12, s13, s23;
  scanf("%d", &n);
  printf("? 1 2\n");
  fflush(stdout);
  scanf("%d", &s12);
  printf("? 1 3\n");
  fflush(stdout);
  scanf("%d", &s13);
  printf("? 2 3\n");
  fflush(stdout);
  scanf("%d", &s23);
  a[1] = (s12 + s13 - s23) / 2;
  a[2] = (s12 + s23 - s13) / 2;
  a[3] = (s13 + s23 - s12) / 2;
  for (int i = 4; i <= n; i++) {
    printf("? 1 %d\n", i);
    fflush(stdout);
    scanf("%d", &s12);
    a[i] = s12 - a[1];
  }
  printf("! ");
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  fflush(stdout);
}
