#include <bits/stdc++.h>
using namespace std;
long long pmod(long long a, long long b, long long c) {
  long long d = 1;
  while (b) {
    if (b & 1) d = d * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return d;
}
long long sc, n, m, k, aux, a;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  a = n / k;
  m = n - m;
  if (a > m) {
    aux = m * (k - 1) + n % k;
    a -= m;
    sc = 2;
    sc = pmod(sc, a, 1000000009);
    sc--;
    sc = sc * 2 * k % 1000000009;
    sc += aux;
  } else
    sc = n - m;
  sc %= 1000000009;
  if (sc < 0) sc += 1000000009;
  cout << sc;
  return 0;
}
