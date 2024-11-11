#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  long long a, b, c;
  long long ans;
  if (n & 1) {
    a = n;
    b = max(1LL, a - 1);
    c = max(1LL, b - 1);
    ans = a * b * c;
  } else {
    ans = 1;
    a = n;
    b = max(1, n - 1);
    for (c = max(1LL, b - 1); c >= 1; --c) {
      ans = max(ans, a * b * c / gcd(a * b, c));
    }
    a = n;
    b = max(1LL, a - 1);
    c = max(1LL, b - 1);
    ans = max(ans, a * b * c);
  }
  cout << ans << endl;
}
