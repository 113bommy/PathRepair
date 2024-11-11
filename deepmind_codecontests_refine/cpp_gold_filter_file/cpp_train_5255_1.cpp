#include <bits/stdc++.h>
using namespace std;
int n, m, a[102][102], c, d, mx = 0, k = -1, tempk, r[102];
pair<int, int> b[102];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      mx = max(mx, a[i][j]);
    }
  }
  for (int i = 0; i < m; i++) b[i] = make_pair(a[0][i], i);
  sort(b, b + m);
  for (int i = 1; i < n; i++) {
    int fl = 0;
    for (int j = 0; j < m; j++) {
      d = a[i][b[j].second] - b[j].first;
      if (j) {
        if (d == c) {
          if (c < 0) fl = 1;
        } else {
          if (fl) {
            printf("NO");
            return 0;
          }
          fl = 1;
          tempk = r[i] + b[j].first - a[i][b[j].second];
          if (tempk > mx) {
            if (k == -1)
              k = tempk;
            else {
              if (k > tempk) {
                if (k % tempk == 0)
                  k = tempk;
                else {
                  printf("NO");
                  return 0;
                }
              } else {
                if (tempk % k) {
                  printf("NO");
                  return 0;
                }
              }
            }
          } else {
            printf("NO");
            return 0;
          }
        }
      } else
        r[i] = d;
      c = d;
    }
  }
  if (k == -1) k = mx + 1;
  for (int i = 1; i < n; i++) {
    r[i] %= k;
    if (r[i] < 0) r[i] += k;
  }
  printf("YES\n%d\n", k);
  for (int i = 0; i < n; i++) printf("%d ", r[i]);
  printf("\n");
  for (int i = 0; i < m; i++) printf("%d ", a[0][i]);
}
