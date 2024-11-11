#include <bits/stdc++.h>
using namespace std;
uint64_t gcd(uint64_t a, uint64_t b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
uint64_t inf = 10 * 1000 * 1000 * 1000ull * 1000 * 1000 * 1000ull;
bool check(uint64_t a, uint64_t b) {
  uint64_t q = inf / a;
  return b <= q;
}
uint64_t lcm(uint64_t a, uint64_t b) {
  uint64_t g = gcd(a, b);
  a /= g;
  if (check(a, b))
    return a * b;
  else
    return inf;
}
int main(void) {
  uint64_t t, w, b;
  cin >> t >> w >> b;
  uint64_t l = lcm(w, b);
  uint64_t q = t / l;
  uint64_t lst = min(t, min(w, b) - 1);
  uint64_t ans = lst;
  if (q >= 1) {
    ans += (q - 1) * min(w, b);
    lst = q * l + min(w, b) - 1;
    ans += min(lst, t) - q * l + 1;
  }
  uint64_t g = gcd(ans, t);
  cout << ans / g << "/" << t / g;
  return 0;
}
