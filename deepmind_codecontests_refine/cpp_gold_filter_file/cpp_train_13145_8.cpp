#include <bits/stdc++.h>
using namespace std;
long long fact[1000001], power[1000001];
long long powerr(long long x, long long y);
long long mpower(long long x, long long y, long long p);
long long gcdExtended(long long a, long long b);
bool isPrime(long long n);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, j, k, l, h, p, q, r, x, i, y, z, a, b, c, d, f, n, m,
      M = 1000000007;
  char ch, ch2, ch3;
  string s1, s2, s3;
  set<long long> S;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    long long c1, c2, c3, c4, c5, c6;
    cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
    long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    if (x >= 0 && y > 0) {
      if (x > y) {
        ans1 = c1 * y + c6 * (x - y);
        ans2 = c2 * y + c6 * (x);
        ans3 = c1 * x + c5 * (x - y);
      } else {
        ans1 = c1 * x + c2 * (abs(x - y));
        ans2 = c2 * y + c6 * x;
        ans3 = c1 * y + c3 * (abs(x - y));
      }
      long long ans;
      ans = min(ans2, ans1);
      ans = min(ans, ans3);
      cout << ans;
      cout << "\n";
    } else if (x >= 0 && y <= 0) {
      ans1 = c6 * x + c5 * (abs(y));
      ans2 = c1 * x + c5 * (x - y);
      ans3 = c4 * abs(y) + c6 * (x - y);
      long long ans;
      ans = min(ans2, ans1);
      ans = min(ans, ans3);
      cout << ans;
      cout << "\n";
    } else if (x < 0 && y >= 0) {
      ans1 = c2 * y + c3 * abs(x);
      ans2 = c4 * (abs(x)) + c2 * (y - x);
      ans3 = c1 * y + c3 * (y - x);
      long long ans;
      ans = min(ans2, ans1);
      ans = min(ans, ans3);
      cout << ans;
      cout << "\n";
    } else if (x < 0 && y < 0) {
      if (y > x) {
        ans1 = c4 * abs(y) + c3 * (y - x);
        ans2 = c4 * abs(x) + c2 * (y - x);
        ans3 = c3 * abs(x) + c5 * abs(y);
      } else {
        ans1 = c4 * abs(x) + c5 * (x - y);
        ans2 = c5 * abs(y) + c3 * (abs(x));
        ans3 = c4 * abs(y) + c6 * (x - y);
      }
      long long ans;
      ans = min(ans2, ans1);
      ans = min(ans, ans3);
      cout << ans;
      cout << "\n";
    }
  }
}
long long gcdExtended(long long a, long long b) {
  if (b == 0) {
    return a;
  } else
    return gcdExtended(b, a % b);
}
long long mpower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long powerr(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long p = sqrt(n);
  for (int i = 5; i <= p; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
