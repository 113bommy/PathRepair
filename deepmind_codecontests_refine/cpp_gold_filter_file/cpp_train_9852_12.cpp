#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main() {
  int n, m, c;
  cin >> n >> m >> c;
  int p;
  int l1 = 0, r1 = 0, l2 = n, r2 = n;
  for (int t = 0; t < m; ++t) {
    cin >> p;
    if (p <= c / 2) {
      if (r1 == 0 || a[r1 - 1] <= p) {
        a[r1++] = p;
        printf("%d\n", r1);
        fflush(stdout);
      } else {
        int l = -1, r = r1 - 1, m;
        while (r - l > 1) {
          m = (r + l + 1) / 2;
          if (a[m + 1] > p) {
            r = m;
          } else {
            l = m;
          }
        }
        a[r] = p;
        printf("%d\n", r + 1);
        fflush(stdout);
      }
    } else {
      if (r2 - l2 == 0 || a[l2] >= p) {
        a[--l2] = p;
        printf("%d\n", l2 + 1);
        fflush(stdout);
      } else {
        int l = l2, r = r2, m;
        while (r - l > 1) {
          m = (r + l) / 2;
          if (a[m] < p) {
            l = m;
          } else {
            r = m;
          }
        }
        a[l] = p;
        printf("%d\n", l + 1);
        fflush(stdout);
      }
    }
    if (r1 == l2) {
      return 0;
    }
  }
  return 0;
}
