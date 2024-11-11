#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long int a, b, n, c, s, l;
  cin >> t;
  while (t--) {
    cin >> a >> b >> n;
    l = max(a, b);
    s = min(a, b);
    if (l > n || s > n) {
      std::cout << 0 << std::endl;
      continue;
    }
    c = 0;
    while (l <= n && s <= n) {
      s = l + s;
      c = c + 1;
      if (l > n || s > n) break;
      l = s + l;
      c = c + 1;
    }
    std::cout << c << std::endl;
  }
  return 0;
}
