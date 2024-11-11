#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, k, w;
int p[1005], ans[1005];
int main() {
  scanf("%d", &n);
  for (int i = 2; i * i <= 1000; i++) {
    if (p[i] == 1) continue;
    for (int j = i * i; j <= 100; j += i) p[j] = 1;
  }
  for (int i = (2); i <= (n); i++) {
    if (p[i] == 1) continue;
    x = 1;
    for (int j = (0); j < (20); j++) {
      x *= i;
      if (x > n) break;
      ans[w++] = x;
    }
  }
  printf("%d\n", w);
  for (int i = (0); i < (w); i++) printf("%d ", ans[i]);
  return 0;
}
