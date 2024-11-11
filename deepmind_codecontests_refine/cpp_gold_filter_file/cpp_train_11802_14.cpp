#include <bits/stdc++.h>
using namespace std;
map<signed long long int, signed long long int> F;
signed long long int fibonacci(signed long long int n, signed long long int M) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return 1;
  }
  if (F.count(n)) return F[n];
  signed long long int k = n / 2;
  if (n % 2 == 0) {
    return F[n] = (fibonacci(k, M) * fibonacci(k, M) % M +
                   fibonacci(k - 1, M) * fibonacci(k - 1, M) % M) %
                  M;
  } else {
    return F[n] = (fibonacci(k, M) * fibonacci(k + 1, M) % M +
                   fibonacci(k - 1, M) * fibonacci(k, M) % M) %
                  M;
  }
}
int main() {
  signed long long int m, L, R, K, ans = 0;
  cin >> m >> L >> R >> K;
  for (signed long long int p = 1, i = 1; i <= R; ++p) {
    signed long long int j = R / (R / i);
    i = j;
    if (R / i - (L - 1) / i >= K) ans = i;
    i++;
  }
  cout << fibonacci(ans - 1, m) % m;
}
