#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n;
long long f(long long x) {
  if (x == 0) {
    return (x * (x - 1)) / 2;
  }
  long long curr = 0;
  long long t = 9, c = 1;
  x++;
  while (x--) {
    curr += t * c;
    c *= 10;
  }
  long long temp = (curr + 1) / 10;
  curr -= temp;
  long long ans = 0;
  while (curr > 0) {
    if (curr / 2 < n) {
      ans += min(curr / 2, n - curr / 2);
    }
    curr -= temp;
  }
  return ans;
}
int main() {
  cin >> n;
  int i = 9;
  while (i >= 0) {
    long long ans = f(i);
    if (ans > 0) {
      printf("%lld\n", ans);
      return 0;
    }
    i--;
  }
  return 0;
}
