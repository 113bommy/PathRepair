#include <bits/stdc++.h>
using namespace std;
int a[2001];
int main() {
  int n, b, s = 0, m, s1, i;
  scanf("%d%d", &n, &b);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) {
    if (i == n - 1)
      s1 = a[i];
    else {
      m = *max_element(a + i, a + n);
      s1 = (b / a[i]) * m + b % a[i];
    }
    if (s1 > s) s = s1;
  }
  printf("%d", s);
  return 0;
}
