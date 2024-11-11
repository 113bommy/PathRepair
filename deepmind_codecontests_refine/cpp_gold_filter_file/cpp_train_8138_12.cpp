#include <bits/stdc++.h>
using namespace std;
int x[200005];
long long offset[200005];
int main() {
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);
  memset(x, 0, 200005);
  memset(offset, 0, 200005);
  long long orginal = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", x + i);
    if (i == 0) continue;
    if (x[i - 1] == x[i]) continue;
    int x1 = x[i - 1];
    int x2 = x[i];
    if (x1 < x2) {
      x1 ^= x2;
      x2 ^= x1;
      x1 ^= x2;
    }
    int dx = x1 - x2;
    orginal += dx;
    offset[x2] -= dx;
    offset[x2] += (x1 - 1);
    offset[x2 + 1] -= (x1 - 1);
    offset[x2 + 1] += (x1 - x2 - 1);
    offset[x1] -= (x1 - x2 - 1);
    offset[x1] += x2;
    offset[x1 + 1] -= x2;
    offset[x1 + 1] += dx;
  }
  for (int i = 1; i <= n; i++) {
    offset[i] += offset[i - 1];
    printf("%lld ", orginal + offset[i]);
  }
}
