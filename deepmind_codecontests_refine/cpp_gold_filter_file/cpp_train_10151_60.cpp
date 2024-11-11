#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
const long long mod = 1e9 + 7;
const long long maxim = 1e9, Maxim = 1e18;
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
pair<long long, long long> zarb(long long a, long long b) {
  long long x1 = a / maxim, y1 = a % maxim, x2 = b / maxim, y2 = b % maxim,
            ansx = 0, ansy = 0;
  long long q1 = y1 * y2, q2 = y1 * x2 + x1 * y2, q3 = x1 * x2;
  ansx += q1 / Maxim;
  ansy += q1 % Maxim;
  ansx += q2 / maxim;
  ansy += (q2 % maxim) * maxim;
  ansx += q3;
  return make_pair(ansx, ansy);
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long m = min(w, b);
  pair<long long, long long> lcm = zarb((w / gcd(w, b)), b);
  long long num1, num2;
  if (lcm.first > 6) {
    num1 = 0;
    num2 = t + 1;
  } else {
    long long LCM = (lcm.first * Maxim) + lcm.second;
    num1 = (t + 1) / LCM;
    num2 = (t + 1) % LCM;
  }
  long long soorat = (num1 * m) + min(num2, m) - 1;
  long long GCD = gcd(soorat, t);
  cout << soorat / GCD << "/" << t / GCD;
}
