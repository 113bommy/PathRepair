#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while ((a != 0) && (b != 0)) {
    if (a > b) {
      a = a % b;
    } else {
      b = b % a;
    }
  }
  return a + b;
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long nod = gcd(w, b), mi = min(w, b);
  long long nok = (w / nod) * b;
  long long ans = 0;
  ans = (t / nok + 1) * mi;
  if ((t / nok) * nok + mi > t) {
    ans = ans - (t / nok) * nok + mi + t + 1;
  }
  ans--;
  double nok1 = (double)w / nod * b;
  if (nok1 > t) {
    ans = min(mi - 1, t);
  }
  long long c = gcd(ans, t);
  t = t / c;
  ans = ans / c;
  cout << ans << "/" << t << endl;
}
