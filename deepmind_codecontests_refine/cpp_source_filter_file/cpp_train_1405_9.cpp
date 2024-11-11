#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, p;
  int a[1007];
  while (~scanf("%d", &n)) {
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (j = 0, i = 0; i < n && j < n; i++) {
      for (j = 0; j < n && a[j] == j; j++)
        ;
      for (p = 0; p < n; p++) a[p] = (a[p] + (int)pow(-1, j % 2) + n) % n;
    }
    if (i == n && j < n)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
