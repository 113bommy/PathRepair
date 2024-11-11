#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, i;
  int a[300010];
  while (scanf("%d", &n) == 1) {
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    printf("%d\n", a[n / 2]);
  }
}
