#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
long long __gcd(long long a, long long b) {
  while (a != 0) {
    long long __t = b % a;
    b = a;
    a = __t;
  }
  return b;
}
bool isSimple(unsigned x) {
  for (unsigned i = 2; i < x; i++)
    if (x % i == 0) return false;
  return true;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  ios_base::sync_with_stdio(false);
  long long x;
  cin >> x;
  cout << x - x / 2 - x / 3 - x / 5 - x / 7 + x / 6 + x / 10 + x / 14 + x / 15 +
              x / 21 + x / 35 - x / 30 - x / 54 - x / 70 - x / 105 + x / 210;
  return 0;
}
