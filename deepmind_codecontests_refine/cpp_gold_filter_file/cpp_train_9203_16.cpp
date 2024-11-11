#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a1, a2, b1, b2, k = 1, f = 0, ans = 0;
  scanf("%d", &n);
  while (k <= 4) {
    scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
    if (n >= a1 + b1 || n >= a1 + b2)
      ans = a1;
    else if (n >= a2 + b1 || n >= a2 + b2)
      ans = a2;
    if (ans > 0) {
      f = 1;
      printf("%d %d %d", k, ans, n - ans);
      break;
    }
    k++;
  }
  if (f == 0) printf("-1");
  return 0;
}
