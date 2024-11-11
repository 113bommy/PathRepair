#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long n, m, i, j, k, tot, ans, s, t, x, y, z, bu, fir;
long long a[N], b[N], c[N], A[N];
long long abs_(long long a) {
  if (a > 0)
    return a;
  else
    return -a;
}
void dg(long long i) {
  if (i == n) return;
  while (c[i] != 0) {
    if (bu >= 100000) return;
    if (c[i] > 0) {
      if (a[i] < 9 && a[i + 1] < 9) {
        a[i]++;
        a[i + 1]++;
        c[i]--;
        printf("%d 1\n", i);
        bu++;
      } else {
        if (a[i] == 9)
          return;
        else
          dg(i + 1);
      }
    } else {
      if (a[i] > 0 && a[i + 1] > 0 && (i != fir || a[i] > 1)) {
        a[i]--;
        a[i + 1]--;
        c[i]++;
        printf("%d -1\n", i);
        bu++;
      } else {
        if (a[i] == 0)
          return;
        else
          dg(i + 1);
      }
    }
  }
}
int main() {
  scanf("%lld\n", &n);
  for (i = 1; i <= n; i++) a[i] = getchar() - 48;
  scanf("\n");
  for (i = 1; i <= n; i++) b[i] = getchar() - 48;
  for (i = 1; i <= n; i++) A[i] = a[i];
  for (i = 1; i <= n; i++)
    if (a[i] != 0) {
      fir = i;
      break;
    }
  for (i = 1; i <= n - 1; i++) {
    c[i] = b[i] - A[i];
    bu += abs_(c[i]);
    A[i] += c[i];
    A[i + 1] += c[i];
  }
  if (A[n] != b[n]) {
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", bu);
  bu = 0;
  for (i = 1; i <= n; i++) dg(i);
}
