#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a[100], c[8] = {}, p = 0, ans;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &n);
    if (a >= 3200)
      p++;
    else
      c[a / 400] = 1;
  }
  ans = count(c, c + 8, 1);
  printf("%d %d\n", max(1, ans), ans + p);
  return 0;
}
