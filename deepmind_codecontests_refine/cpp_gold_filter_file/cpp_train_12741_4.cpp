#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int is_prime[100010];
void sieve() {
  is_prime[0] = is_prime[1] = true;
  for (int i = 2; i <= 100000; i++) {
    if (is_prime[i] == false && (long long)i * i <= 100000) {
      for (int j = i * i; j <= 100000; j += i) is_prime[j] = true;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  long long gc = gcd(a, b);
  a = a / gc;
  b = b / gc;
  long long x1, y1, x2, y2, val, val1, val2, divi;
  divi = min(n / a, m / b);
  val = (divi * a);
  val1 = val2 = val / 2;
  if (val % 2 != 0) val1++;
  x1 = x - val1;
  x2 = x + val2;
  val = (divi * b);
  val1 = val2 = val / 2;
  if (val % 2 != 0) val1++;
  y1 = y - val1;
  y2 = y + val2;
  if (x1 < 0) {
    x2 += (-x1);
    x1 = 0;
  } else if (x2 > n) {
    x1 -= (x2 - n);
    x2 = n;
  }
  if (y1 < 0) {
    y2 += (-y1);
    y1 = 0;
  } else if (y2 > m) {
    y1 -= (y2 - m);
    y2 = m;
  }
  cout << x1 << " " << y1 << " " << x2 << " " << y2;
  return 0;
}
