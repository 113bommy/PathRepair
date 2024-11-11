#include <bits/stdc++.h>
using namespace std;
int h[1005];
int main() {
  int n, k, pos = 1, m = 0, a, count = 0, b = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
  }
  for (int i = 1; i <= n; i++) {
    a = h[i];
    for (int j = 1; j <= n; j++) {
      b = a + (j - i) * k;
      if (b < 0) break;
      if (b == h[j]) count++;
    }
    if (count > m) {
      m = count;
      pos = i;
    }
    count = 0;
  }
  printf("%d\n", n - m);
  if (n != m) {
    a = h[pos] - (pos - 1) * k;
    for (int i = 1; i <= n; i++) {
      b = h[i] - a - (i - 1) * k;
      if (b > 0)
        printf("- %d %d\n", i, b);
      else if (b < 0)
        printf("+ %d %d\n", i, -b);
    }
  }
  return 0;
}
