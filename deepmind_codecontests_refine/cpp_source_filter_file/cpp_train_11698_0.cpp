#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, s = 0, k = 0, l = 0, v = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &a, &b, &c);
    if (a == 1) {
      s += b;
      k += 10;
    } else {
      l += b;
      v += 10;
    }
  }
  if (s * s >= k)
    printf("LIVE\n");
  else
    printf("DEAD\n");
  if (l * l >= v)
    printf("LIVE\n");
  else
    printf("DEAD\n");
  return 0;
}
