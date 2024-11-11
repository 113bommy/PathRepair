#include <bits/stdc++.h>
using namespace std;
const long long s = 2100000000;
int main() {
  long long n, H;
  cin >> n >> H;
  if (H == 1) {
    long long l = 0;
    long long r = s;
    while (l + 1 < r) {
      long long mid = (l + r) >> 1;
      long long h = mid / 2;
      long long res = 0;
      if (mid % 2 == 0)
        res = (1 + h) * h;
      else
        res = (1 + h) * h + h + 1;
      if (res >= n)
        r = mid;
      else
        l = mid;
    }
    cout << r << endl;
    return 0;
  }
  if (H > s || H * (H + 1) >= 2 * n) {
    long long l = 0;
    long long r = s;
    while (l + 1 < r) {
      long long mid = (l + r) >> 1;
      long long res = mid * (mid + 1) / 2;
      if (res >= n)
        r = mid;
      else
        l = mid;
    }
    cout << r << endl;
    return 0;
  }
  long long l = H;
  long long r = s;
  while (l + 1 < r) {
    long long mid = (l + r) >> 1;
    long long res = 0;
    if ((mid - H) % 2) {
      long long h = (mid + H - 1) / 2;
      res = (1 + h) * h / 2 + (H + h) * (h - H + 1) / 2;
    } else {
      long long h = (mid + H) / 2;
      res = h * (h - 1) / 2 + (H + h) * (h - H + 1) / 2;
    }
    if (res >= mid)
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
  return 0;
}
