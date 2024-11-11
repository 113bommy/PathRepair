#include <bits/stdc++.h>
using namespace std;
const int nmax = 123456;
int n;
int a[nmax], b[nmax], c[nmax];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    if (i == a[i]) {
      printf("YES\n");
      for (int j = 1; j <= n; j++)
        if (j != i) printf("%d %d\n", i, j);
      return 0;
    }
  for (int i = 1; i <= n; i++)
    if (i == a[a[i]]) {
      int bb = 0;
      b[i] = 1;
      b[a[i]] = 1;
      for (int j = 1; j <= n; j++)
        if (b[j] != 1) {
          int dd = j;
          int cc = 0;
          while (b[dd] != 1) {
            cc++;
            b[dd] = 1;
            dd = a[dd];
          }
          bb += cc % 2;
        }
      if (bb > 1) {
        printf("No");
        return 0;
      } else {
        printf("YES\n");
        for (int j = 1; j <= n; j++) b[j] = 0;
        b[i] = 1;
        b[a[i]] = 1;
        int y = i;
        for (int j = 1; j <= n; j++)
          if (b[j] != 1) {
            int x = j;
            while (b[x] != 1) {
              printf("%d %d\n", y, x);
              b[x] = 1;
              x = a[x];
              y = a[y];
            }
          }
        printf("%d %d", i, a[i]);
        return 0;
      }
    }
  printf("NO\n");
  return 0;
}
