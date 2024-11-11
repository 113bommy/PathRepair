#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long lcm(long long x, long long y) { return (x * y) / gcd(x, y); }
long long glcm(long long x, long long y, long long gcd) {
  return (x * y) / gcd;
}
long long sumDigit(long long n) {
  if (n == 0) return 0;
  return (n % 10 + sumDigit(n / 10));
}
long long _pow(long long n) {
  if (n == 0) return 1;
  long long k = _pow(n / 2);
  k = (k * k) % 1000000007;
  if (n % 2) k = (k * 2) % 1000000007;
  return k;
}
bool _isPrime(long long n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  for (long long i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
bool isPowerOfTwo(long long n) { return (ceil(log2(n)) == floor(log2(n))); }
long long CountBit1(unsigned long long num) {
  unsigned long long one = 1, cnt = 0;
  for (long long i = 0; i < 64; i++) {
    long long tone = one;
    tone &= num;
    if (tone) cnt++;
    one <<= 1;
  }
  return cnt;
}
long long row, col;
long long fx[] = {1, -1, 0, 0};
long long fy[] = {0, 0, 1, -1};
int main() {
  long long x, y;
  cin >> x >> y;
  vector<pair<long long, long long> > v(x);
  vector<long long> w;
  for (long long i = 0; i < x; i++) {
    long long a;
    cin >> a;
    v[i] = make_pair(a, i + 1);
  }
  sort(v.rbegin(), v.rend());
  long long ans = 0;
  for (long long i = 0; i < y; i++) {
    ans += v[i].first;
    w.push_back(v[i].second);
  }
  cout << ans << endl;
  sort(w.begin(), w.end());
  if (w.size() == 1) {
    cout << x << endl;
    return 0;
  }
  cout << w[0] << " ";
  for (long long i = 1; i < y; i++) {
    if (i == y - 1) {
      cout << x - w[i - 1];
      return 0;
    }
    cout << w[i] - w[i - 1] << " ";
  }
}
