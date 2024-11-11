#include <bits/stdc++.h>
using namespace std;
int main() {
  long a, b, c, d, n;
  while (cin >> n) {
    long sum1, sum2, p, q;
    int m = 0;
    for (int i = 1; i <= 4; i++) {
      cin >> a >> b >> c >> d;
      sum1 = min(a, b);
      sum2 = min(c, d);
      if (sum1 + sum2 <= n) {
        m = i;
        p = sum1;
        q = sum2 + (n - (sum1 + sum2));
      }
    }
    if (m == 0)
      cout << "-1" << endl;
    else
      cout << m << " " << p << " " << q << endl;
  }
  return 0;
}
