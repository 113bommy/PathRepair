#include <bits/stdc++.h>
using namespace std;
struct flist {
  int pos;
  int val;
};
bool acomp(flist a, flist b) { return (a.val < b.val); }
long long floorSqrt(long long x) {
  if (x == 0 || x == 1) return x;
  long long start = 1, end = INT_MAX, ans;
  while (start <= end) {
    long long mid = (start + end) / (long long)(2);
    if (mid * mid == x) return mid;
    if (mid * mid < x) {
      start = mid + (long long)1;
      ans = mid;
    } else
      end = mid - (long long)1;
  }
  return ans;
}
using namespace std;
int main() {
  int i, j, k;
  long long r, x, y, x1, y1;
  cin >> r >> x >> y >> x1;
  ;
  cin >> y1;
  ;
  long long dissquare = abs(x - x1) * abs(x - x1) + abs(y - y1) * abs(y - y1);
  long long disroot = floorSqrt(dissquare);
  if (x == x1 && y == y1) {
    printf("0\n");
  } else if (disroot * disroot == dissquare) {
    if (disroot % r == 0)
      printf("%lld\n", disroot / (2 * r));
    else {
      printf("%lld\n", disroot / (2 * r) + 1);
    }
  } else {
    printf("%lld\n", disroot / (2 * r) + 1);
  }
}
