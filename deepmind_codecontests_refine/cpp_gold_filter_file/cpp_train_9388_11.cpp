#include <bits/stdc++.h>
using namespace std;
bool f[105];
struct mzls {
  int x, y;
} a[105];
bool operator<(mzls x1, mzls y1) { return x1.x - x1.y > y1.x - y1.y; }
int main() {
  int T, n, m;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    int m2 = -10000, m1 = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].x, &a[i].y);
      m1 = max(m1, a[i].x);
      m2 = max(m2, a[i].x - a[i].y);
    }
    if (m <= m1) {
      printf("1\n");
      continue;
    }
    if (m2 <= 0) {
      printf("-1\n");
      continue;
    }
    m -= m1;
    int ans = (m % m2 == 0) ? m / m2 + 1 : m / m2 + 2;
    printf("%d\n", ans);
  }
}
