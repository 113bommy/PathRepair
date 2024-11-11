#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;
const int N = 2e4 + 10;
int a[N], n, b[N], bn, c[N], cn;
void Print(int x) {
  printf("%d", x);
  fflush(stdout);
}
int Query(int x, int y) {
  if (x < -inf || x > inf || y < -inf || y > inf) return -1;
  printf("0 %d %d\n", x, y);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
void Solve1(int l, int r) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  int len, len1, len2;
  len = Query(mid, mid);
  if (len == 0) {
    a[++n] = mid;
    Solve1(l, mid - 1);
    Solve1(mid + 1, r);
    return;
  }
  len1 = mid - len >= l ? Query(mid - len, mid - len) : -1;
  len2 = mid + len <= r ? Query(mid + len, mid + len) : -1;
  if (len1 == 0) a[++n] = mid - len;
  if (len2 == 0) a[++n] = mid + len;
  Solve1(l, mid - len - 1);
  Solve1(mid + len + 1, r);
}
void Solve2() {
  sort(a + 1, a + n + 1);
  int space = a[1] != -inf ? a[1] - 1 : a[n] + 1;
  for (int i = 2; i <= n; ++i)
    if (a[i] - a[i - 1] > 1) {
      space = a[i] - 1;
      break;
    }
  bn = cn = 0;
  for (int i = 1; i <= n; ++i) {
    int len1 = Query(space, a[i]);
    int len2 = Query(a[i], space);
    if (len1 == 0) c[++cn] = a[i];
    if (len2 == 0) b[++bn] = a[i];
  }
  printf("1 %d %d\n", bn, cn);
  for (int i = 1; i <= bn; ++i) printf("%d ", b[i]);
  puts("");
  for (int i = 1; i <= cn; ++i) printf("%d ", c[i]);
  puts("");
  fflush(stdout);
}
int main() {
  n = 0;
  Solve1(-inf, inf);
  Solve2();
  return 0;
}
