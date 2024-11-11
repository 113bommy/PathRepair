#include <bits/stdc++.h>
const int inf = 2147483640;
using namespace std;
long long pow(long long a, long long b) {
  long long ans = 1;
  while (b--) {
    ans *= a;
  }
  return ans;
}
long long solv(long long t, long long p) {
  long long t1 = pow(10ll, p) - 1ll;
  long long t2 = t1 - t;
  return (t2 * t);
}
int main() {
  long long l, r;
  cin >> l >> r;
  long long L = l;
  long long R = r;
  long long rl = 0;
  long long LL = 0;
  long long RR = 0;
  while (L > 0) {
    LL++;
    L /= 10;
  }
  long long rr = 0;
  while (R > 0) {
    RR++;
    R /= 10;
  }
  long long centr = pow(10ll, RR) / 2;
  if (LL < RR) {
    if (r >= centr) {
      cout << solv(centr, RR);
      return 0;
    } else {
      cout << solv(r, RR);
      return 0;
    }
  }
  if ((l >= centr) && (r >= centr)) {
    cout << solv(l, RR);
    return 0;
  } else if ((l <= centr + 1) && (r <= centr + 1)) {
    cout << solv(r, RR);
    return 0;
  } else {
    cout << solv(centr, RR);
    return 0;
  }
}
