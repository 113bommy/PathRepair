#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, x;
  cin >> s >> x;
  long long d = s - x;
  if (d % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }
  long long d2 = d >> 1;
  long long res = 1;
  for (long long i = 0; i < 45; i++) {
    if ((d2 & (1LL << i)) && (x & (1LL << i))) {
      cout << 0 << endl;
      return 0;
    }
    if ((x & (1LL << i))) {
      res *= 2;
    }
  }
  if (x != s)
    cout << res << endl;
  else
    cout << res - 2 << endl;
}
