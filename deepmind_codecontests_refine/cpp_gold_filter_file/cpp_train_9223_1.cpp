#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int inf = (1 << 30);
const int Sq = 400;
const int MX = 1e6 + 9;
long long n, a, b, pr;
long long bn(long long l, long long r) {
  while (l <= r) {
    long long mid = (l + r) / 2;
    if ((mid * mid * mid) == pr) return mid;
    if ((mid * mid * mid) > pr) r = mid - 1;
    if ((mid * mid * mid) < pr) l = mid + 1;
  }
  return -1;
}
int main() {
  cin >> n;
  while (n--) {
    scanf("%lld%lld", &a, &b);
    pr = a * b;
    long long x = bn(1ll, 1e6);
    if (x == -1) {
      puts("No");
      continue;
    }
    if (a % x == 0 && b % x == 0) {
      puts("Yes");
      continue;
    }
    puts("No");
  }
}
