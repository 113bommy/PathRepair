#include <bits/stdc++.h>
using namespace std;
long long d, g, p, a, i, m;
int main() {
  cin >> d >> g >> p;
  for (i = 1; i <= d; i++) {
    cin >> a;
    if (a == 2 && p > 0) {
      p--;
    } else {
      if (a == 2 && g > 0) {
        g--;
      } else {
        if (a == 1 && g > 0) {
          g--;
        } else {
          m++;
        }
      }
    }
  }
  cout << m;
  return 0;
}
