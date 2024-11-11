#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(void) {
  int n, x;
  int i;
  int o;
  scanf("%d %d", &n, &x);
  for (i = 0, o = x; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] < x) --o;
    if (a[i] == x) ++o;
  }
  printf("%d\n", o);
  return 0;
}
