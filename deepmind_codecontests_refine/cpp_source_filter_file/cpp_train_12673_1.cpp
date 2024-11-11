#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  long long l, r, x, y;
  cin >> l >> r >> x >> y;
  if (y % x != 0) {
    cout << "0" << endl;
    return 0;
  }
  long long tmp = y / x;
  long long answer = 0;
  for (long long i = 1; i <= sqrt(r); i++) {
    if (tmp % i != 0) {
      continue;
    }
    long long t1 = i;
    long long t2 = tmp / i;
    if (gcd(t1, t2) != 1) {
      continue;
    }
    long long a = x * t1;
    long long b = x * t2;
    if (a >= l && a <= r && b >= l && b <= r) {
      if (a == b) {
        answer++;
      } else {
        answer += 2;
      }
    }
  }
  cout << answer << endl;
  return 0;
}
