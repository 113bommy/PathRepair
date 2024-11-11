#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long num = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num * neg;
}
struct node {
  double l, r;
} s[200010];
int n, q;
long long sum[200010];
double getx(int sx, int sy, int tx, int ty) {
  double k = (ty - sy) * 1.0 / (tx - sx);
  return sx - sy * 1.0 / k;
}
inline int findl(double x) {
  int l = 1, r = n + 1, mid;
  while (r > l + 1) {
    int mid = l + r >> 1;
    if (s[mid].r >= x)
      r = mid;
    else
      l = mid;
  }
  return r;
}
inline int findr(double x) {
  int l = 1, r = n + 1, mid;
  while (r > l + 1) {
    int mid = l + r >> 1;
    if (s[mid].l <= x)
      l = mid;
    else
      r = mid;
  }
  return l;
}
int main() {
  int sy = read(), a = read(), b = read();
  n = read();
  for (int i = 1; i <= n; i++) s[i].l = read() * 1.0, s[i].r = read() * 1.0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i].r - s[i].l;
  q = read();
  while (q--) {
    int x = read(), y = read();
    double l = getx(x, y, a, sy), r = getx(x, y, b, sy), ans;
    int tl = findl(l), tr = findr(r);
    if (s[tl].l > l) l = s[tl].l;
    if (s[tr].r < r) r = s[tr].r;
    if (tl == tr)
      ans = r - l;
    else
      ans = s[tl].r - l + r - s[tr].l + (sum[tr - 1] - sum[tl]) * 1.0;
    ans = ans * 1.0 / y * (y - sy);
    if (ans < 0) ans = 0.0;
    printf("%.10lf\n", ans);
  }
  return 0;
}
