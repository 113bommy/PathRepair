#include <bits/stdc++.h>
long long mod(long long x) {
  if (x < 0) return -x;
  return x;
}
long long expo(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x);
    y = y >> 1;
    x = x * x;
  }
  return res;
}
using namespace std;
vector<long long> v;
long long a[1000000], p[1000000];
long long b, c, s, m;
long long f(long long x) {
  long long y = 0;
  if (max(0LL, b * x - a[0]) * p[0] + max(0LL, s * x - a[1]) * p[1] +
          max(0LL, c * x - a[2]) * p[2] <=
      m) {
    return 1;
  } else
    return 0;
}
long long bs(long long lo, long long hi) {
  long long res = 1;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (f(mid) == 1) {
      lo = mid + 1;
      res = mid;
    } else {
      hi = mid - 1;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  string q;
  cin >> q;
  for (long long i = 0; i < q.length(); i++) {
    if (q[i] == 'B') {
      b++;
    }
    if (q[i] == 'C') {
      c++;
    }
    if (q[i] == 'S') {
      s++;
    }
  }
  for (long long i = 0; i < 3; i++) cin >> a[i];
  for (long long i = 0; i < 3; i++) cin >> p[i];
  cin >> m;
  long long n = bs(1, 1e14);
  cout << n;
  return 0;
}
