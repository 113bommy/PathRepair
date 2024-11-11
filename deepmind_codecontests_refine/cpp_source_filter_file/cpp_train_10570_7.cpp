#include <bits/stdc++.h>
using namespace std;
const int maxn = 1E5 + 10;
int main() {
  int n, a, b, tmp;
  a = b = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    if (tmp > a) {
      b += a;
      a = tmp;
    } else
      b += tmp;
  }
  int ans = a - b;
  printf("%d\n", ans);
  return 0;
}
