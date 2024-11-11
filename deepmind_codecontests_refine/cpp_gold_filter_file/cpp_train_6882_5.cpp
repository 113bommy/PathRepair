#include <bits/stdc++.h>
using namespace std;
long long calc(long long n) {
  long long res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long long ans = 0;
  long long x = 0;
  while (x <= n) {
    ans = max(ans, (calc(x) + calc(n - x)));
    x = x * 10 + 9;
  }
  cout << ans << "\n";
}
