#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 100001;
int main() {
  int n, m, h;
  while (~scanf("%d%d%d", &n, &m, &h)) {
    int s = 0, ah;
    for (int i = 1; i <= m; i++) {
      int a;
      scanf("%d", &a);
      if (i == h) ah = a;
      s += a;
    }
    s--;
    n--;
    ah--;
    if (s < n)
      printf("-1\n");
    else if (s - ah < n)
      printf("1\n");
    else {
      double ans = 1;
      for (int i = 1; i <= n; i++) ans = ans * (s - ah - n + i) / (s - n + i);
      ans = 1.0 - ans;
      printf("%.12f\n", ans);
    }
  }
  return 0;
}
