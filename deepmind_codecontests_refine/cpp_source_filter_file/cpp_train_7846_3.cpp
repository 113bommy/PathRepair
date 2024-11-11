#include <bits/stdc++.h>
using namespace std;
long long n;
long long maX(long long x, long long y) {
  if (x > y)
    return x;
  else
    return y;
}
int main() {
  cin >> n;
  if (n % 3 != 0)
    cout << 0 << endl;
  else {
    long long m = n / 3;
    long long a, b, c, ub;
    long long x, y, z;
    long long j = 0;
    long long res = 0;
    while (j * j * j <= m) j++;
    for (a = j - 1; a > 1; a--) {
      if (m % a == 0) {
        ub = (long long)sqrt(m / a);
        for (b = ub; b >= maX((ub - a), a); b--) {
          if (m % (a * b) == 0) {
            c = m / (a * b);
            if (((a + b + c) % 2) != 0)
              continue;
            else {
              long long sum = (a + b + c) / 2;
              x = sum - a;
              y = sum - b;
              z = sum - c;
              if (x <= 0 || y <= 0 || z <= 0) continue;
              if (x == y && y == z && x == z)
                res++;
              else if (x == z)
                res += 3;
              else if (y == z)
                res += 3;
              else if (x == z)
                res += 3;
              else
                res += 6;
            }
          }
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
