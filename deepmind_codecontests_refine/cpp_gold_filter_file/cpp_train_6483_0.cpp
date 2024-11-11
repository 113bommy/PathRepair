#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long c = 0, c2 = 0;
    long long n;
    cin >> n;
    long long c1 = 0;
    while (n != 0) {
      c1++;
      if (n % 2 == 0 && (n / 2) % 2 == 0 && n / 2 != 2) {
        c++;
        n -= 1;
      } else if (n % 2 == 0 && (n / 2) % 2 == 1 || (n % 2 == 0 && n / 2 == 2)) {
        c += n / 2;
        n /= 2;
      } else {
        if (n % 2 == 1) {
          c += 1;
          n -= 1;
        }
      }
      if (c1 % 2 == 1) c2 += c;
      c = 0;
    }
    cout << c2 << endl;
  }
}
