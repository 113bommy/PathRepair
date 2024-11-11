#include <bits/stdc++.h>
using namespace std;
int a, b, mod;
long long Mod, second;
const long long t9 = 1000000000ll;
int main() {
  cin >> a >> b >> mod;
  second = (long long)b, Mod = (long long)mod;
  for (int k = 0ll; k < mod && k <= a; ++k) {
    long long x = t9 * (long long)k % Mod;
    if (x == 0ll) continue;
    if (x + second < Mod) {
      printf("1 %.9d", k);
      return 0;
    }
  }
  putchar('2');
  return 0;
}
