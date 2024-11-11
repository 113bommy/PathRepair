#include <bits/stdc++.h>
int main() {
  long long n, a, b, c, ans = 0;
  std::cin >> n >> a >> b >> c;
  if (n < std::min(a, b)) {
    std::cout << 0;
  } else if (a <= b - c || n < b) {
    std::cout << n / a;
  } else {
    ans = 1;
    n -= b;
    ans += n / (b - c);
    n -= (ans - 1) * (b - c) - c;
    ans += n / a;
    std::cout << ans;
  }
  return 0;
}
