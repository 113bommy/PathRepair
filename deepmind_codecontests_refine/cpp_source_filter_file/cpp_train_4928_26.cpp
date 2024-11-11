#include <bits/stdc++.h>
using namespace std;
int a, b, n, c[2020];
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
  }
  sort(c, c + n);
  printf("%d", c[a + 1] - c[a]);
  return 0;
}
