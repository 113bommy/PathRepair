#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, i, s = 0;
  scanf("%I64d%I64d", &n, &x);
  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    s = s + a[i] * x;
    if (x > 1) {
      x--;
    }
  }
  printf("%I64d", s);
}
