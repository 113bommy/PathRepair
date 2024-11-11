#include <bits/stdc++.h>
using namespace std;
template <typename T>
T modpow(T base, T exp) {
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    base = (base * base);
    exp >>= 1;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  {
    long long k, a, b;
    cin >> k >> a >> b;
    long long ans = 0;
    int flag = 0;
    if ((a > 0 && b > 0) || (a < 0 && b < 0))
      flag = 1;
    else
      flag = 0;
    if (flag == 0) {
      a = abs(a);
      ans += b / k;
      ans += a / k;
      ans += 1;
    } else {
      if (b < 0) {
        b = abs(b);
        a = abs(a);
        ans -= (b - 1) / k;
        ans += a / k;
      } else {
        ans += b / k;
        ans -= (a - 1) / k;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
