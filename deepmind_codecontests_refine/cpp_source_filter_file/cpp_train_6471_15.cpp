#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long k;
  cin >> k;
  if (k <= 9) cout << k;
  if (k > 9 && k < 190) {
    long long t = k - 8;
    long long c = t / 2 + 9;
    if (t % 2 == 0)
      cout << c / 10;
    else
      cout << c % 10;
  } else if (k > 189 && k < 2890) {
    long long t = k - 187;
    long long c = t / 3 + 99;
    if (t % 3 == 0)
      cout << c / 100;
    else if (t % 2 == 1)
      cout << (c / 10) % 10;
    else
      cout << c % 10;
  } else if (k > 2889) {
    long long t = k - 2886;
    long long c = t / 4 + 999;
    if (t % 4 == 0)
      cout << c / 1000;
    else if (t % 4 == 1)
      cout << (c / 100) % 10;
    else if (t % 4 == 2)
      cout << (c / 10) % 10;
    else
      cout << c % 10;
  }
}
