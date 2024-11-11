#include <bits/stdc++.h>
using namespace std;
long long int modulo = 1000003;
long long int eleva(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2 == 0) return eleva(b * b % modulo, e / 2);
  return b * eleva(b * b % modulo, e / 2) % modulo;
}
long long int inverso(long long int x) { return eleva(x, modulo - 2); }
long long int veces(long long int f) {
  if (f < 2) return 0;
  return f / 2 + veces(f / 2);
}
long long int normaliza(long long int x) {
  return (x % modulo + modulo) % modulo;
}
int main() {
  long long int m, k;
  cin >> m >> k;
  if (m < 60 and (1 << m) <= k) {
    cout << "1 1" << endl;
    exit(0);
  }
  long long int n = eleva(2, m);
  long long int nk = eleva(n, k);
  long long int inv = inverso(eleva(2, veces(k - 1) + m));
  if (k >= 1000004) {
    long long int x = nk * inv % modulo;
    cout << x << " " << x << endl;
    exit(0);
  }
  long long int prod = 1;
  for (int i = 0; i < k; i++) prod = prod * (n - i) % modulo;
  long long int a = normaliza((nk - prod) * inv);
  long long int b = normaliza(nk * inv);
  cout << a << " " << b << endl;
}
