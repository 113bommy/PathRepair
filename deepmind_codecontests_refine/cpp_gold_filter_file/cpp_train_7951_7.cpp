#include <bits/stdc++.h>
using namespace std;
int n, b, c, ans;
int main() {
  scanf("%d", &n);
  for (c = 1; c <= n; c++) {
    for (b = 1; b < c; b++) {
      double a = sqrt(c * c - b * b);
      if (a == int(a) && a <= n && a <= b) ans++;
    }
  }
  printf("%d", ans);
  return 0;
}
