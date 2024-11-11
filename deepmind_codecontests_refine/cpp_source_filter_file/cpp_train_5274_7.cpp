#include <bits/stdc++.h>
using namespace std;
static char buf[100000], *p1 = buf, *p2 = buf;
static const int MAXN = 1e5 + 10;
static const int OO = 0x3fffffff;
int read() {
  int ret = 0;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (ch < '0' || ch > '9')
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  while (ch >= '0' && ch <= '9')
    ret = ret * 10 + ch - '0',
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  return ret;
}
int n, u;
int data[MAXN];
int main() {
  scanf("%d%d", &n, &u);
  double ans = -1;
  for (int i = 1; i <= n; ++i) scanf("%d", &data[i]);
  for (int i = 2; i <= n; ++i) {
    double ei = data[i - 1], ej = data[i];
    double ek = 0;
    int l = i, r = n;
    while (l <= r) {
      int mid = l + r >> 1;
      if (data[mid] - ei <= u) {
        ek = data[mid];
        ans = max(ans, (ek - ej) / (ek - ei));
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  if (ans < -0.5) {
    puts("-1");
  } else {
    printf("%.10f\n", ans);
  }
  return 0;
}
