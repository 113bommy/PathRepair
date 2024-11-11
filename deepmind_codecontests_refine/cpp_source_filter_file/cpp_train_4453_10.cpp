#include <bits/stdc++.h>
using namespace std;
long long n, h;
long long sum = 0;
long long ans = 0;
bool check(long long x) {
  if (x >= n) return 1;
  if (x <= h) return (x * (x + 1) >= 2 * n) ? 1 : 0;
  long long t = x - h + 1;
  if (t % 2)
    return (2 * h + t / 2 - 1) * t / 2 + h + t / 2 + h * (h - 1) / 2 > n ? 1
                                                                         : 0;
  else
    return ((2 * h + t / 2 - 1) * t + h * (h - 1)) >= 2 * n ? 1 : 0;
}
int main() {
  cin >> n >> h;
  long long l = 0, r = 2e9 + 3;
  while (l + 1 < r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
}
