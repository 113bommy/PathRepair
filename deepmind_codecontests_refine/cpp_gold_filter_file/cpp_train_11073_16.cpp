#include <bits/stdc++.h>
using namespace std;
int a[200];
void cal() {
  int i, j, k;
  for (i = 0; i < 100; i++) a[i] = 100 - i;
}
int main() {
  int n, i;
  cal();
  scanf("%d", &n);
  if (n == 1 || n == 2)
    printf("%d\n", -1);
  else {
    printf("%d", a[0]);
    for (i = 1; i < n; i++) printf(" %d ", a[i]);
    printf("\n");
  }
  return 0;
}
