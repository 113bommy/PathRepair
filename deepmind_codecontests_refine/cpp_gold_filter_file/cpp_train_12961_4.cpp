#include <bits/stdc++.h>
using std::cin;
using std::cout;
inline std::string make(long long a, long long b) {
  if (!a && !b) return "";
  if (a == b) return "fail";
  if (a > b) {
    return std::to_string(a / (b + 1)) + "A" + make(a % (1 + b), b);
  } else {
    return std::to_string(b / (a + 1)) + "B" + make(a, b % (1 + a));
  }
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  long long a, b;
  cin >> a >> b;
  auto res = make(a - 1, b - 1);
  if (res.size() && res.back() == 'l') {
    cout << "Impossible" << '\n';
  } else {
    cout << res << '\n';
  }
}
