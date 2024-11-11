#include <bits/stdc++.h>
using namespace std;
long long n, k, p;
bool r(long long n, long long k, long long x) {
  if (k == 0) return 1;
  if (n & 1) {
    if (x == n)
      return 0;
    else
      return r(n - 1, k - 1, x);
  } else {
    if (k <= (n >> 1)) {
      if (x & 1) return 1;
      long long t = n - 2 * k;
      if (x <= t) return 1;
      return 0;
    } else {
      if ((x & 1) == 0) return 0;
      long long t = n - 2 * (k - (n >> 1)) + 1;
      if (x < t) return 1;
      return 0;
    }
  }
}
int main() {
  cin >> n >> k >> p;
  while (p--) {
    long long t;
    cin >> t;
    if (r(n, k, t))
      printf(".");
    else
      printf("X");
  }
  return 0;
}
