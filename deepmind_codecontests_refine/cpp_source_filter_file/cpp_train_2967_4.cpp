#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
bool f[N] = {1, 1};
long long p, q, rub, primepi, res;
long long rev(long long x) {
  long long res;
  for (res = 0; x; x /= 10) res = res * 10 + x % 10;
  return res;
}
int main() {
  cin >> p >> q;
  for (long long i = 1; i < N; ++i) {
    if (!f[i]) {
      primepi++;
      for (long long j = i * i; j < N; j += i) f[j] = 1;
    }
    if (rev(i) == i) rub++;
    if (q * primepi <= p * rub) res = i;
  }
  cout << res;
  return 0;
}
