#include <bits/stdc++.h>
using namespace std;
long long make(long long digit) {
  long long num = 9, h = 10;
  for (long long i = 1; i < digit; i++) {
    num += (h * 9);
    h = h * 10;
  }
  return num;
}
long long make2(long long digit) {
  long long one = 1;
  for (long long i = 1; i <= digit; i++) {
    one = one * 10;
  }
  return one;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  if (n < 5) {
    cout << (n * (n - 1)) / 2 << "\n";
    return 0;
  }
  long long ans = 0;
  for (long long i = 9; i > 0; i--) {
    long long num = make(i);
    long long res = 0;
    for (long long j = 0; j < 9; j++) {
      long long add = make2(i) * j;
      long long now = num + add;
      long long lo = (now + 1) / 2;
      long long hi = min(now - 1, n);
      res += max(0LL, (hi - lo + 1));
    }
    if (res != 0) {
      ans = res;
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}
