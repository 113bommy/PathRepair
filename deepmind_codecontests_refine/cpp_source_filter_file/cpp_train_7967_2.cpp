#include <bits/stdc++.h>
using namespace std;
long long int modulo = 1e9 + 7;
long long int eleva(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2 == 0) return eleva(b * b % modulo, e / 2);
  return b * eleva(b * b % modulo, e / 2) % modulo;
}
long long int inverso(long long int x) { return eleva(x, modulo - 2); }
long long int n, m;
int main() {
  cin >> n >> m;
  long long int invm = inverso(m);
  long long int f = 1;
  long long int prod = 1;
  for (int i = 1; i <= n; i++) {
    long long int fc = (f - prod) * invm;
    f = m * (2 * f - fc) % modulo;
    prod = prod * m % modulo;
  }
  cout << ((f % modulo) + modulo) % modulo << endl;
}
