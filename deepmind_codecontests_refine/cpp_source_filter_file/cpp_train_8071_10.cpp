#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  unsigned long long mask = 1000000007;
  int q0 = 0;
  while (cin >> c) {
    int q1 = 0;
    short digit;
    if ((c >= '0') && (c <= '9'))
      digit = c - '0';
    else if ((c >= 'A') && (c <= 'Z'))
      digit = c - 55;
    else if ((c >= 'a') && (c <= 'z'))
      digit = c - 61;
    else if (c == '_')
      digit = c - 32;
    else
      digit = c + 17;
    while (digit != 0) {
      ++q1;
      digit = digit & (digit - 1);
    }
    q0 += (6 - q1);
  }
  unsigned long long ans = (q0 > 0);
  for (unsigned i = 1; i <= q0; ++i) {
    ans *= 3;
    ans %= mask;
  }
  cout << ans;
  return 0;
}
