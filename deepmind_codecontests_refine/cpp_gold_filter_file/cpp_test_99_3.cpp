#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int bas, n;
    cin >> bas >> n;
    long long int cevap = 1;
    if (n == 0)
      cout << bas << endl;
    else if (n == 1 && bas % 2)
      cout << bas + 1 << endl;
    else if (n == 1)
      cout << bas - 1 << endl;
    else {
      if (n > 4) cevap += 4 * ((n - 1) / 4);
      long long int deger = (n - 1) % 4;
      for (long long int i = deger; i > 0; i--) {
        if (i > 2)
          cevap += n - deger + i;
        else
          cevap -= n - deger + i;
      }
      if (bas % 2 == 0) cevap *= -1;
      cout << bas + cevap << endl;
    }
  }
  return 0;
}
