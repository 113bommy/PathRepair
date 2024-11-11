#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, x;
  cin >> a >> b >> c;
  d = c * (int)(b / ((a + 1) / 2));
  if (b < (a + 1) / 2 || a % 2 == 0)
    cout << "0";
  else {
    for (long long i = 0; i < a / 2; i++) {
      scanf("%lld", &x);
      if (d > x) d = x;
      scanf("%lld", &x);
    }
    cin >> x;
    if (d > x) d = x;
    cout << d;
  }
}
