#include <bits/stdc++.h>
using namespace std;
int n;
int contain(int a, int b, int c, int d) {
  int t = (a < b) ^ (c < d);
  if (t) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    if ((a <= c && c <= b) || (a <= d && d <= b) || (c <= a && a <= d) ||
        (c <= b && b <= d))
      return 1;
    return 0;
  }
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  if ((a <= c && d <= b) || (c <= a && b <= d)) return 1;
  return 0;
}
void out(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}
int ask(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
int main() {
  scanf("%d", &n);
  if ((n / 2) & 1) return out(-1), 0;
  for (int l = 1, r = n / 2, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) {
    int x = ask(l);
    int y = ask(l + n / 2);
    if (x == y) return out(l), 0;
    int a = ask(mid);
    int b = ask(mid + n / 2);
    if (a == b) return out(mid), 0;
    if (l != mid && contain(x, y, a, b))
      r = mid - 1;
    else
      l = mid + 1;
  }
  out(-1);
}
