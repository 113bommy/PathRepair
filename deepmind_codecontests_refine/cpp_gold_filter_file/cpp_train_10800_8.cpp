#include <bits/stdc++.h>
long long x, y;
long long jisuan(long long xx) {
  if (xx == 0) return 0;
  long long gg = 1e18;
  for (long long i = 0; i < xx; i++) {
    long long f = x * i + (xx - i) * y;
    gg = std::min(gg, f);
  }
  return gg;
}
int main() {
  long long n, xx = 0, yy = 0;
  std::cin >> n >> x >> y;
  std::string s;
  std::cin >> s;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '0' && (i == 0 || s[i - 1] == '1')) xx++;
  }
  long long gg = jisuan(xx);
  std::cout << gg << std::endl;
}
