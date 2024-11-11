#include <bits/stdc++.h>
using namespace std;
long long n, dn = 3, res;
int main() {
  cin >> n;
  while (n != 1) {
    if (n % 2 == 0) {
      res += n;
      n /= 2;
    } else {
      while (n % dn != 0 || dn < sqrt(n)) dn += 2;
      if (sqrt(n) < dn) {
        res += n;
        break;
      }
      res += n;
      n /= dn;
      dn = 3;
    }
  }
  res++;
  cout << res << endl;
  return 0;
}
