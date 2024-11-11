#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long powerM(long long x, long long y, long long M = mod) {
  long long v = 1;
  x = x % M;
  while (y > 0) {
    if (y & 1) v = (v * x) % M;
    y = y >> 1;
    x = (x * x) % M;
  }
  return v;
}
long long power(long long x, long long y) {
  long long v = 1;
  while (y > 0) {
    if (y & 1) v = v * x;
    y = y >> 1;
    x = x * x;
  }
  return v;
}
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long p = k % 2;
  long long e2 = k / 2;
  if (e2 > n) {
    long long rem = 2 * (e2 - n);
    if (rem + p >= n)
      cout << 0;
    else
      cout << n - (rem + p);
  } else {
    cout << (n - p);
  }
  return (0);
}
