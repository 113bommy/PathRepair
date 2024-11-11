#include <bits/stdc++.h>
using namespace std;
long long modinv(long long num, long long mod) {
  long long x[100], y[100], d[100], k[100], i;
  x[0] = 1;
  y[0] = 0;
  d[0] = mod;
  x[1] = 0;
  y[1] = 1;
  d[1] = num;
  i = 1;
  while ((d[i]) && (i < 100)) {
    k[i] = d[i - 1] / d[i];
    i++;
    x[i] = x[i - 2] - (k[i - 1] * x[i - 1]);
    y[i] = y[i - 2] - (k[i - 1] * y[i - 1]);
    d[i] = d[i - 2] - (k[i - 1] * d[i - 1]);
  }
  int result;
  result = y[i - 1];
  if (result < 0) {
    result += mod;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, g;
  cin >> n >> m >> g;
  if (g) {
    n--;
  }
  if (n < 0) {
    if (m == 1) {
      cout << 1;
    } else {
      cout << 0;
    }
  } else {
    if (m == 0) {
      cout << (n % 2) ? 1 : 0;
    } else if (m == 1) {
      if (n == 0) {
        cout << 1;
      } else {
        if ((n + 1) % 2) {
          cout << n / 2;
        } else {
          cout << (n + 3) / 2;
        }
      }
    } else {
      m--;
      long long mod;
      long long curr, sum, temp;
      mod = 1000000007;
      curr = (n % 2) ? (m + 1) : 1;
      sum = curr;
      long long i;
      for (i = m + (n % 2) + 2; i <= n + m; i += 2) {
        temp = ((((i - 1) * modinv(i - m - 1, mod)) % mod) *
                ((i * modinv(i - m, mod)) % mod)) %
               mod;
        curr = (curr * temp) % mod;
        sum += curr;
      }
      cout << (sum % mod);
    }
  }
}
