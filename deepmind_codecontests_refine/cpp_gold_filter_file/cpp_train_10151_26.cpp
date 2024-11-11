#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long g = gcd(w, b);
  long long w0 = w / g;
  long long b0 = b / g;
  if (t / w < b0) {
    long long ok = min(min(w, b) - 1, t);
    long long g0 = gcd(t, ok);
    cout << ok / g0 << "/" << t / g0 << endl;
  } else {
    long long cnt = t / (w0 * b0 * g);
    long long add1 = min(w, b) - 1;
    long long add2 = min(add1, t - cnt * w0 * b0 * g);
    long long res = cnt * (1 + add1) + add2 + 1 - 1;
    long long g0 = gcd(res, t);
    cout << res / g0 << "/" << t / g0 << endl;
  }
}
