#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, k;
  cin >> n >> k;
  std::vector<int64_t> cows(n);
  for (auto& c : cows) cin >> c;
  if (k % 2 == 0) {
    auto alpha = std::count(begin(cows), end(cows), 1);
    auto beta = std::count(begin(cows), end(cows), 2);
    auto gamma = std::count_if(begin(cows), end(cows),
                               [](int64_t p) { return p % 2 == 0 && p > 2; });
    if ((alpha % 2 == 0 && beta % 2 == 0 && gamma % 2 == 0) ||
        (alpha % 2 == 1 && beta % 2 == 0 && gamma % 2 == 1))
      std::cout << "Nicky";
    else
      std::cout << "Kevin";
  } else {
    bool nOdd = false;
    bool nEven = false;
    for (auto c : cows) {
      if (c == 2 || (c % 2 == 1 && c > 3)) continue;
      int len = 0;
      while (c % 2 == 0) {
        if (c > 4)
          c /= 2;
        else
          c = 3;
        ++len;
      }
      if (c > 3) ++len;
      if (len % 2)
        nOdd = !nOdd;
      else
        nEven = !nEven;
    }
    if (!nEven && !nOdd)
      std::cout << "Nicky";
    else
      std::cout << "Kevin";
  }
}
