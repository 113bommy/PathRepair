#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t > 0) {
    t--;
    long long a, b, x, y, n;
    cin >> n >> x >> y;
    for (int i = n - 1; i > 0; i--) {
      if ((y - x) % i == 0) {
        a = (y - x) / i;
        break;
      }
    }
    cout << x << " " << y << " ";
    n -= 2;
    long long ak = x;
    while (n > 0 && ak + a < y) {
      ak = ak + a;
      cout << ak << " ";
      n--;
    }
    ak = x;
    while (n > 0 && ak - a > 0) {
      ak = ak - a;
      cout << ak << " ";
      n--;
    }
    ak = y;
    while (n > 0) {
      ak = ak + a;
      cout << ak << " ";
      n--;
    }
    cout << endl;
  }
  return 0;
}
