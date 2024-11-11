#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  scanf("%d", &n);
  int a[n];
  bool err = false;
  scanf("%d", &a[0]);
  for (int i = 1; i < n; i++) {
    scanf("%d", &a[i]);
    if (i > 1) {
      if (a[i] - a[i - 1] != x) err = true;
    }
    x = a[i] - a[i - 1];
  }
  if (err)
    printf("%d\n", a[n - 1]);
  else
    printf("%d\n", a[n - 1] + x);
  return 0;
}
