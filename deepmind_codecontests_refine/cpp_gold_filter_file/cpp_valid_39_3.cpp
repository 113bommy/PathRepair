#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
int main() {
  int t;
  scanf("%d", &t);
  long long W, H, w, h, x1, y1, x2, y2, x3, y3, x4, y4, mih, miw;
  while (t--) {
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &W, &H, &x1, &y1, &x2, &y2, &w,
          &h);
    double mid1 = (x1 + x2) / 2.0;
    double mid2 = (y1 + y2) / 2.0;
    double mid3 = W / 2.0;
    double mid4 = H / 2.0;
    double ans = -1;
    if (mid1 < mid3 && mid2 >= mid4) {
      x3 = W, y3 = 0;
      x4 = W - w, y4 = h;
      mih = y4 - y1, miw = x2 - x4;
      if (mih <= 0 || miw <= 0) {
        ans = 0.0;
      } else if (H - y2 >= mih && x1 >= miw) {
        ans = min((double)mih, (double)miw);
      } else if (H - y2 >= mih && x1 < miw) {
        ans = (double)mih;
      } else if (H - y2 < mih && x1 >= miw) {
        ans = (double)miw;
      } else {
        ans = -1;
      }
    } else if (mid1 < mid3 && mid2 < mid4) {
      x3 = W, y3 = H;
      x4 = W - w, y4 = H - h;
      mih = y2 - y4, miw = x2 - x4;
      if (mih <= 0 || miw <= 0) {
        ans = 0.0;
      } else if (y1 >= mih && x1 >= miw) {
        ans = min((double)mih, (double)miw);
      } else if (y1 >= mih && x1 < miw) {
        ans = (double)mih;
      } else if (y1 < mih && x1 >= miw) {
        ans = (double)miw;
      } else {
        ans = -1;
      }
    } else if (mid1 >= mid3 && mid2 < mid4) {
      x3 = 0, y3 = H;
      x4 = w, y4 = H - h;
      mih = y2 - y4, miw = x4 - x1;
      if (mih <= 0 || miw <= 0) {
        ans = 0.0;
      } else if (y1 >= mih && W - x2 >= miw) {
        ans = min((double)mih, (double)miw);
      } else if (y1 >= mih && W - x2 < miw) {
        ans = (double)mih;
      } else if (y1 < mih && W - x2 >= miw) {
        ans = (double)miw;
      } else {
        ans = -1;
      }
    } else {
      x3 = 0, y3 = 0;
      x4 = w, y4 = h;
      mih = y4 - y1, miw = x4 - x1;
      if (mih <= 0 || miw <= 0) {
        ans = 0.0;
      } else if (H - y2 >= mih && W - x2 >= miw) {
        ans = min((double)mih, (double)miw);
      } else if (H - y2 >= mih && W - x2 < miw) {
        ans = (double)mih;
      } else if (H - y2 < mih && W - x2 >= miw) {
        ans = (double)miw;
      } else {
        ans = -1;
      }
    }
    if (ans == -1) {
      printf("-1\n");
    } else {
      printf("%.9lf\n", ans);
    }
  }
  return 0;
}
