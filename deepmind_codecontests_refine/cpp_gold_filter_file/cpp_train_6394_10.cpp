#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, w, x, c;
  cin >> a >> b >> w >> x >> c;
  if (c <= a) {
    cout << 0;
    return 0;
  }
  long long fir = -1;
  long long las = 1000000000000000;
  while (fir + 1 < las) {
    long long mid = (fir + las) / 2;
    long long at = a - mid;
    long long ct = c - (b + mid * w) / x;
    if (ct <= at)
      las = mid;
    else
      fir = mid;
  }
  if (las == 0) {
    cout << c - a;
    return 0;
  }
  long long at = a - fir;
  long long ct = c - (b + fir * w) / x;
  cout << (b + fir * w) / x + ct - at + 1;
}
