#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long dd(int x, int y) { return (long long)(n - x + 1) * (m - y + 1); }
long long ans;
int s;
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1; j <= m; j += 2) {
      int r = s - i * j;
      if (r < 0) break;
      if (r == 0) {
        ans += ((i + 1) * (j + 1) / 2 - 1) * dd(i, j);
      } else {
        for (int k = 1; k < j; k += 2)
          if (r % (k * 2) == 0) {
            if (i + r / k <= n) {
              ans += dd(i + r / k, j) * 2;
            }
          }
      }
    }
  }
  printf("%lld\n", (ans));
  return 0;
}
