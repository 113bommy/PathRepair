#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int ang;
    scanf("%d", &ang);
    int c = gcd(ang, 180);
    if (ang < 90)
      cout << 180 / c << endl;
    else {
      if (180 - c > ang)
        cout << 180 / c << endl;
      else
        cout << 360 / c << endl;
    }
  }
}
