#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int T, n, m, x, y, Max, ans;
tuple<int, int, int> a[maxn];
int main() {
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ca++) {
    scanf("%d%d", &n, &m);
    Max = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &x, &y);
      a[i] = make_tuple(x - y, x, y);
      Max = max(Max, x);
    }
    sort(a + 1, a + 1 + n);
    m -= Max;
    int res = get<0>(a[n]);
    if (m <= 0) {
      printf("1\n");
      continue;
    }
    if (res <= 0) {
      printf("-1");
      continue;
    }
    printf("%d\n", 1 + m / res + (m % res != 0));
  }
}
