#include <bits/stdc++.h>
using namespace std;
long long e2(int x) {
  if (x < 30) return 1 << x;
  long long mid = e2(x >> 1);
  mid *= mid;
  mid %= 1000000007;
  if (x & 1) {
    mid <<= 1;
    mid %= 1000000007;
  }
  return mid;
}
int main() {
  int n, m, k, ks;
  long long s;
  cin >> n >> m >> k;
  ks = min(min(n / k, n - m), m / (k - 1));
  m -= (k - 1) * ks;
  n -= ks * k;
  int ls = ks * (k - 1);
  s = 0;
  if (n == m) {
    int d = m / k;
    s = e2(d) * s;
    s %= 1000000007;
    s += (e2(d + 1) - 2) * k;
    s %= 1000000007;
    s += m % k;
    s %= 1000000007;
  } else if (m <= k - 1) {
    s += m;
    s %= 1000000007;
  }
  s += ls;
  s %= 1000000007;
  while (s < 0) {
    s += 1000000007;
  }
  cout << s << endl;
  return 0;
}
