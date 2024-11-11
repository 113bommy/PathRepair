#include <bits/stdc++.h>
int main() {
  int t, x, s;
  int n;
  std::cin >> t >> s >> x;
  n = std::floor((((float)x - t) / s));
  std::string res;
  n = std::floor(n);
  int val = t + n * s;
  if ((x == val || x == val + 1) && n >= 1)
    res = "YES";
  else {
    res = "NO";
  }
  if (x == t) res = "YES";
  std::cout << res;
}
