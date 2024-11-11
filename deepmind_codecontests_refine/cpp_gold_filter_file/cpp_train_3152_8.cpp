#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 1;
long long int power(long long int x, long long int n) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = result * x;
    x = x * x;
    n = n / 2;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long a, b, c, d, e, f, g, h, i, j, k, ans = 0;
  cin >> a;
  while (a--) {
    cin >> b >> c >> d >> e >> f;
    j = b - d;
    k = c - e;
    ans = 0;
    if ((j + k) <= f) {
      b = d;
      c = e;
      ans = d * e;
    } else {
      if (b < c) {
        if (j >= f) {
          b = b - f;
        } else {
          if ((max(e, c - f)) < d) {
            if (k >= f) {
              c = c - f;
            } else {
              c = e;
              f = f - k;
              b = b - f;
            }
          } else {
            b = d;
            f = f - j;
            c = c - f;
          }
        }
      } else if (b > c) {
        if (k >= f) {
          c = c - f;
        } else {
          if ((max(d, b - f)) < e) {
            if (j >= f) {
              b = b - f;
            } else {
              b = d;
              f = f - j;
              c = c - f;
            }
          } else {
            c = e;
            f = f - k;
            b = b - f;
          }
        }
      } else {
        if (j >= k) {
          if (j >= f) {
            b = b - f;
          } else {
            b = d;
            f = f - j;
            c = c - f;
          }
        } else {
          if (k >= f) {
            c = c - f;
          } else {
            c = e;
            f = f - k;
            b = b - f;
          }
        }
      }
    }
    cout << b * c << '\n';
  }
  return 0;
}
