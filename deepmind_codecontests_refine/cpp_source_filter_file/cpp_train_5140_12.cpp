#include <bits/stdc++.h>
using namespace std;
long long n, x, y, c;
long long colored(long long n) { return n * n + (n - 1) * (n - 1); }
bool valid(int t) {
  long long colored = 1LL * t * t + (t - 1LL) * (t - 1LL);
  long long right = 0, left = 0, top = 0, bottom = 0;
  if (y + t > n) right = y + t - n - 1;
  if (y - t < 1) left = 1 - y + t - 1;
  if (x + t > n) bottom = x + t - n - 1;
  if (x - t < 1) top = 1 - x + t - 1;
  colored -= right * right + left * left + top * top + bottom * bottom;
  long long tr = right - x;
  long long tl = left - x;
  long long br = right - (n - x + 1);
  long long lr = left - (n - x + 1);
  if (tr > 0) colored += tr * (tr + 1) / 2;
  if (tl > 0) colored += tl * (tl + 1) / 2;
  if (br > 0) colored += br * (br + 1) / 2;
  if (lr > 0) colored += lr * (lr + 1) / 2;
  return colored >= c;
}
int main() {
  cin >> n >> x >> y >> c;
  long long lo = 1, hi = n * n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (valid(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo - 1 << endl;
  return 0;
}
