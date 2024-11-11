#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000")
using namespace std;
int main() {
  long long k, d, t;
  cin >> k >> d >> t;
  t *= 2;
  if (k > d) {
    long long n = k / d;
    if (k % d != 0) n++;
    d = n * d;
  }
  long double res = 0;
  long long temp = 2 * k + (d - k);
  long long n = t / temp;
  res += n * d;
  t %= temp;
  if (t <= 2 * k) {
    res += (t / 2.);
  } else {
    res += (k / 2.);
    t -= 2 * k;
    res += t;
  }
  cout << fixed << setprecision(9) << endl;
  cout << res << endl;
}
