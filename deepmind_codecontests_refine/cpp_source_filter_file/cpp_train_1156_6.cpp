#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, N, min, a, b, c = 0, i, opt1 = 0, opt2 = 0;
  cin >> n;
  N = n;
  if (n == 1) {
    cout << 1 << ' ' << 0 << endl;
    return 0;
  }
  while (1) {
    a = (int)sqrt(n);
    if (a * a == n) {
      opt1++;
      n = a;
    } else {
      for (i = 2; i < n; i++) {
        if (n % i == 0) {
          b = n * i;
          b = (int)sqrt(b);
          if (b * b == n * i) {
            n = b * b;
            c++;
            break;
          }
        }
      }
      if (i == n) {
        break;
      }
    }
  }
  if (opt1 == 0)
    cout << n << ' ' << 0 << endl;
  else if (c == 1)
    cout << n << ' ' << opt1 + 1 << endl;
  else
    cout << n << ' ' << opt1 << endl;
  return 0;
}
