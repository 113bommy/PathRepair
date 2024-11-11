#include <bits/stdc++.h>
using namespace std;
long long equ(long long a, long long b, long long i) {
  long long ans = a + (i - 1) * b;
  return ans;
}
long long suma(long long a, long long b, long long i) {
  long long ans = (a - b) * i + (b * i * (i + 1)) / 2;
  return ans;
}
long long inde(long long a, long long b, long long t) {
  long long ans = (t - a) / b + 1;
  return ans;
}
long long sol(long long a, long long b, long long k) {
  long long ans =
      ((b - 2 * a) + sqrt((2 * a - b) * (2 * a - b) + 8 * k * b)) / 2;
  return ans + 2;
}
long long top(long long n) {
  long long ans = 0;
  while (n) {
    ans++;
    n /= 2;
  }
  return ans + 10;
}
int main() {
  long long a, b, quer, sta, t, m;
  cin >> a >> b >> quer;
  for (int i = 0; i < quer; i++) {
    cin >> sta >> t >> m;
    long long in = inde(a, b, t);
    long long prod = t * m;
    if (t < equ(a, b, sta))
      cout << "-1\n";
    else {
      long long k = prod + suma(a, b, sta - 1);
      in = ((sol(a, b, k)) < (in) ? (sol(a, b, k)) : (in));
      long long firs = sta - 1, las = in, mid;
      long long comp = top(las - firs);
      while (comp--) {
        mid = (firs + las) / 2;
        in = mid;
        if (suma(a, b, in) - suma(a, b, sta - 1) < prod)
          firs = mid;
        else
          las = mid;
      }
      if (suma(a, b, in + 1) - suma(a, b, sta - 1) < prod) in++;
      cout << in << "\n";
    }
  }
}
