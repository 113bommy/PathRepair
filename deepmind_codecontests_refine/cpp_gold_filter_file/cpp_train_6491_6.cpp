#include <bits/stdc++.h>
using uli = long long int;
uli bestprice(uli d, uli p) {
  uli price = p, power = 1ll, discount = 0ll, cost = 0ll, digit;
  do {
    discount += cost;
    digit = p % 10ll;
    p /= 10ll;
    if (digit != 9ll) {
      digit += 10ll;
      p--;
    }
    cost = (digit - 9ll) * power;
    power *= 10ll;
  } while (p >= 0 && discount + cost <= d);
  return price - discount;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  uli d, p;
  std::cin >> p >> d;
  std::cout << bestprice(d, p) << std::endl;
  return 0;
}
