#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int l = 1;
  int r = m;
  while (l < r) {
    for (int i = 1; i <= m; i++) {
      printf("%d %d\n%d %d\n", l, i, r, m - i + 1);
    }
    l++;
    r--;
  }
  if (l == r) {
    for (int i = 1; i <= m / 2; i++) {
      printf("%d %d\n%d %d\n", l, i, l, m - i + 1);
    }
    if (m % 2) {
      printf("%d %d\n", l, m / 2 + 1);
    }
  }
}
