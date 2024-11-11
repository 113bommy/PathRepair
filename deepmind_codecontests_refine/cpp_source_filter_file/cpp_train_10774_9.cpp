#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200200;
int n;
long long pre[MAXN];
long double arr[MAXN];
long double getval(long double x, long double s) {
  long double maxval = 0.0;
  long double cur = 0.0;
  for (int i = 0; i < n; i++) {
    long double v = arr[i] - x;
    v *= s;
    cur = max((long double)0.0, cur + v);
    maxval = max(cur, maxval);
  }
  return maxval;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    arr[i] = a;
    pre[i + 1] = pre[i] + a;
  }
  long double lo = -11000.0;
  long double hi = 11000.0;
  while (abs(hi - lo) > 1E-10) {
    long double mid = lo + (hi - lo) / 2;
    if (getval(mid, 1) > getval(mid, -1)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << setprecision(12) << fixed << getval(lo, 1) << endl;
  return 0;
}
