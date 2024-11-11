#include <bits/stdc++.h>
using namespace std;
int check(long long x) {
  for (int i = 2; i < x / i; i++) {
    if ((x % i == 0) && (x % (i * i) == 0)) return 0;
    if ((x % i == 0) && (x % ((x / i) * (x / i)) == 0)) return 0;
  }
  return 1;
}
int main() {
  long long n, i, ans;
  cin >> n;
  ans = 0;
  for (i = 1; i < n / i; i++) {
    if (n % i == 0) {
      if (check(i) == 1) ans = max(i, ans);
      if (check(n / i) == 1) ans = max(ans, n / i);
    }
  }
  cout << ans;
  return 0;
}
