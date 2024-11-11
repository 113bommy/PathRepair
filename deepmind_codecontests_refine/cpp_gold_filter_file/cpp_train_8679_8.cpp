#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  int a[3007];
  while (~scanf("%d", &n)) {
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for (i = 0; i < n; i++)
      if (a[i] != i + 1) break;
    printf("%d\n", i + 1);
  }
  return 0;
}
