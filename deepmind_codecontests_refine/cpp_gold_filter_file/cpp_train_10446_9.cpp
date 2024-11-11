#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1000000007;
int main() {
  int x, y;
  unsigned long long n = 0;
  cin >> x >> y;
  unsigned long long t = 0;
  int power = 2;
  for (int p = 0; p < 2200; p++) {
    if (power > y) break;
    t += y + 1 - power;
    power += 2;
  }
  for (int i = 1; i < x; i++) {
    y = min(i, x - i);
    n += y;
  }
  n *= t;
  cout << n;
  return 0;
}
