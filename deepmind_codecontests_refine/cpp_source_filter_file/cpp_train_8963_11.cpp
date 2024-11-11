#include <bits/stdc++.h>
using namespace std;
long long fpow(long long n, long long k, long long p = 1000000007) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = 1000000007 - 1) {
  return fpow(a, p - 2, p);
}
long long Sqrt(long long x) {
  if (x == 0 || x == 1) return x;
  long long start = 1, end = x, ans;
  while (start <= end) {
    long long mid = (start + end) / 2;
    if (mid * mid == x) return mid;
    if (mid * mid < x) {
      start = mid + 1;
      ans = mid;
    } else
      end = mid - 1;
  }
  return ans;
}
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void in(long long &no) {
  bool neg = false;
  register long long c;
  no = 0;
  c = getchar();
  if (c == '-') {
    neg = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) no = no * 10 + c - 48;
  if (neg) no *= -1;
}
long long maxx(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long minn(long long a, long long b) {
  if (a < b) return a;
  return b;
}
int main() {
  long long p = 0, n = 0;
  long long q;
  cin >> q;
  map<long long, long long> m;
  q--;
  char c;
  long long r;
  cin >> c >> r;
  m[r] = 1;
  while (q--) {
    cin >> c;
    cin >> r;
    if (c == 'L') {
      n--;
      m[r] = n;
    } else if (c == 'R') {
      p++;
      m[r] = p;
    } else {
      cout << min(abs(p - m[r]), abs(n - m[r])) << "\n";
    }
  }
}
