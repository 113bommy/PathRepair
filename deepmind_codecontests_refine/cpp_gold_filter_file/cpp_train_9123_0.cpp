#include <bits/stdc++.h>
using namespace std;
int n, m;
double w;
double eps = 1e-8;
int main() {
  while (cin >> n >> w >> m) {
    if (n >= m) {
      printf("YES\n");
      int idx = 1;
      double aver = w * n / m, sy = w;
      for (int i = 0; i < m; i++) {
        bool p = false;
        double tmp = aver;
        while (true) {
          if (p)
            printf(" ");
          else
            p = true;
          if (sy + eps > tmp) {
            printf("%d %.10f", idx, tmp);
            sy -= tmp;
            if (sy < eps) {
              idx++;
              sy = w;
            }
            break;
          } else {
            tmp -= sy;
            printf("%d %.10f", idx, sy);
            idx++;
            sy = w;
          }
        }
        printf("\n");
      }
    } else {
      if (n % (m - n) != 0) {
        printf("NO\n");
        continue;
      }
      printf("YES\n");
      double aver = w * n / m;
      for (int i = 1; i <= n; i++) {
        printf("%d %.10f\n", i, aver);
      }
      int idx = 1;
      for (int i = n + 1; i <= m; i++) {
        bool p = false;
        for (int j = 1; j <= n / (m - n); j++) {
          if (p)
            printf(" ");
          else
            p = true;
          printf("%d %.10f", idx++, (m - n) * w / m);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
