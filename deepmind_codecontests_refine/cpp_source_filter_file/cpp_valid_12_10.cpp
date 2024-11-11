#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int main() {
  int t, n, m, k, i, j;
  scanf("%d", &t);
  while (t--) {
    int f = 0;
    scanf("%d%d%d", &n, &m, &k);
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0) {
        f = 1;
      }
    } else if (n % 2 == 1 && m % 2 == 0) {
      int x = m, y = n;
      int kk = (x * y) / 2 - k;
      if (kk <= x * (y / 2) * 2 && kk % 2 == 0) {
        f = 1;
      }
    } else {
      if (k <= n * (m / 2) * 2) {
        if (k % 2 == 0) {
          f = 1;
        }
      }
    }
    if (f)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
