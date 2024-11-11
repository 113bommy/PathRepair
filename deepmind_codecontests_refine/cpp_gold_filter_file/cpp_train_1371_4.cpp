#include <bits/stdc++.h>
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const double eps = 1e-8;
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n / 2 + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      printf("%d %d\n", i, j);
      printf("%d %d\n", n - i + 1, m - j + 1);
    }
  }
  if (n % 2) {
    int l = 1, r = m;
    for (int i = 1; i < m + 1; i++) {
      if (i % 2) {
        printf("%d %d\n", n / 2 + 1, l++);
      } else {
        printf("%d %d\n", n / 2 + 1, r--);
      }
    }
  }
  return 0;
}
