#include <bits/stdc++.h>
using namespace std;
class Point {
 public:
  int v, c;
  void read() {
    char in;
    scanf("%d %c", &v, &in);
    if (in == 'R')
      c = 1;
    else if (in == 'B')
      c = 2;
    else
      c = 0;
  }
  bool operator<(const Point &arg) const { return v < arg.v; }
};
int n;
Point a[303030];
int main() {
  int ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) a[i].read();
  sort(a + 1, a + n + 1);
  int lg = 0, lr = 0, lb = 0;
  int bc = 0, rc = 0;
  int mbi = 0, mri = 0;
  for (int i = 1; i <= n; i++)
    if (a[i].c == 0) {
      if (lb != 0) {
        bc += a[i].v - lb;
        mbi = max(mbi, a[i].v - lb);
      }
      if (lr != 0) {
        mri = max(mri, a[i].v - lr);
        rc += a[i].v - lr;
      }
      if (lg == 0)
        ans += bc + bc;
      else
        ans += 3 * (a[i].v - lg) - max(a[i].v - lg, mri + mbi);
      lg = lb = lr = a[i].v;
      bc = rc = 0;
      mbi = mri = 0;
    } else if (a[i].c == 1) {
      if (lr != 0) {
        mri = max(mri, a[i].v - lr);
        rc += a[i].v - lr;
      }
      lr = a[i].v;
    } else if (a[i].c == 2) {
      if (lb != 0) {
        bc += a[i].v - lb;
        mbi = max(mbi, a[i].v - lb);
      }
      lb = a[i].v;
    }
  ans += rc + bc;
  printf("%d\n", ans);
  return 0;
}
