#include <bits/stdc++.h>
using namespace std;
const int inf = 1.01e9;
const double eps = 1e-9;
const int N = 1e5 + 10;
int m, n;
int calc(int x, int R, int L, int st, int *a) {
  for (int i = st; i < n; ++i) {
    if (a[i] <= R + 1) {
      R = a[i] + x;
    } else {
      if (i + 1 < n && a[i + 1] - a[i] > 1 && a[i + 1] - x <= R + 1) {
        R = a[i] + x;
        i++;
      } else if (a[i] - x <= R + 1) {
        R = a[i];
      } else
        break;
    }
  }
  int res = 0;
  if (R + L >= m - 1) res = 1;
  return res;
}
int right(int x, int *a) { return calc(x, x, 0, 1, a); }
int left(int x, int *a) {
  if (a[1] >= x) return 0;
  return calc(x, x, x - a[1], 2, a);
}
bool can(int x, int *a) { return left(x, a) || right(x, a); }
int a[N];
int b[N];
bool can(int x) { return can(x, a) || can(x, b); }
int main() {
  scanf("%d%d", &m, &n);
  if (n == m) return 0 * printf("0\n");
  if (n == 1) return 0 * printf("%d\n", m - 1);
  for (int i = 0; (i) < (n); ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = n - 1; i >= 0; --i) a[i] -= a[0];
  for (int i = n - 1; i >= 1; --i) b[n - i] = m - a[i];
  int l = 0;
  int r = 1e9;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", r);
  return 0;
}
