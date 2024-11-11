#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long psi(long long n) {
  long long res = 0;
  long long pow = 1;
  while (n) {
    long long t = n % 10;
    t = 9 - t;
    res += t * pow;
    pow *= 10;
    n /= 10;
  }
  return res;
}
long long pos(long long u) {
  if (u == 0) return 1;
  long long res = 0;
  while (u) {
    u /= 10;
    res++;
  }
  return res;
}
long long Zpow(long long u, int t) {
  long long res = 1;
  for (int i = 0; i < t; i++) res *= 10;
  return res;
}
int main() {
  while (cin >> n >> m) {
    long long t1 = pos(n), t2 = pos(m);
    if (t1 < t2) n = Zpow(10ll, t2 - 1);
    long long mid = pow(10, t2) / 2;
    if (n >= mid - 1)
      cout << n * psi(n) << endl;
    else if (m <= mid - 1)
      cout << m * psi(m) << endl;
    else
      cout << mid * psi(mid) << endl;
  }
  return 0;
}
