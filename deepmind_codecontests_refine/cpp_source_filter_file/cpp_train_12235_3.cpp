#include <bits/stdc++.h>
constexpr auto NMAX = (int)1e2 + 20;
constexpr auto INF_ULL = 18446744073709551615;
constexpr auto INF_INT = 2147483647;
constexpr auto PI = 3.14159265359;
using namespace std;
unsigned long long n;
unsigned long long res;
unsigned long long logPow(int base, int exp) {
  unsigned long long currentPow = base;
  unsigned long long res = 1;
  while (exp != 0) {
    if (exp & 1) {
      res = res * currentPow;
    }
    currentPow *= currentPow;
    exp >>= 1;
  }
  return res;
}
int main() {
  cin >> n;
  if (n == 3) {
    cout << 24;
    exit(0);
  }
  unsigned long long power = logPow(4, n - 4);
  cout << power * (2 * 3 * 16 + (n - 3) * 9);
  return 0;
}
